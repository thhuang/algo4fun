#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <iterator>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Person {
    int age;
    string name;
};

void GroupByAge(vector<Person>* people) {
    vector<Person>& vec = *people;

    unordered_map<int, int> age_count;
    for (const Person p : vec) ++age_count[p.age];

    unordered_map<int, int> age_offset;
    int offset = 0;
    for (auto& [age, count] : age_count)
        age_offset[age] = offset, offset += count;

    while (!empty(age_offset)) {
        auto from = age_offset.begin();
        int age = vec[from->second].age;
        auto to = age_offset.find(age);

        swap(vec[from->second], vec[to->second]);
        --age_count[age];
        ++age_offset[age];
        if (age_count[age] == 0) age_offset.erase(age);
    }

    return;
}

namespace test_framework {
template <>
struct SerializationTrait<Person> : UserSerTrait<Person, int, string> {};
}  // namespace test_framework

void GroupByAgeWrapper(TimedExecutor& executor, vector<Person>& people) {
    if (people.empty()) {
        return;
    }
    multiset<Person, function<bool(Person, Person)>> values(
        begin(people), end(people), [](const Person& a, const Person& b) {
            return a.age == b.age ? a.name < b.name : a.age < b.age;
        });

    executor.Run([&] { GroupByAge(&people); });

    if (people.empty()) {
        throw TestFailure("Empty result");
    }

    set<int> ages;
    int last_age = people[0].age;
    for (auto& x : people) {
        if (ages.count(x.age)) {
            throw TestFailure("Entries are not grouped by age");
        }
        if (x.age != last_age) {
            ages.insert(last_age);
            last_age = x.age;
        }
        auto it = values.find(x);
        if (it == end(values)) {
            throw TestFailure("Entry set changed");
        }
        values.erase(it);
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "people"};
    return GenericTestMain(args, "data.tsv", &GroupByAgeWrapper,
                           DefaultComparator{}, param_names);
}
