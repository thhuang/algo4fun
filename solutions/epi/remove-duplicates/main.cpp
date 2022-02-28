#include <epi/generic_test.h>
#include <epi/serialization_traits.h>

#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

struct Name {
    bool operator<(const Name& that) const {
        return first_name != that.first_name ? first_name < that.first_name
                                             : last_name < that.last_name;
    }

    bool operator==(const Name& that) const {
        return first_name == that.first_name;
    }

    string first_name, last_name;
};

void EliminateDuplicate(vector<Name>* names) {
    sort(begin(*names), end(*names));
    names->erase(unique(begin(*names), end(*names)), end(*names));
}

namespace test_framework {
template <>
struct SerializationTrait<Name> : UserSerTrait<Name, string, string> {};
}  // namespace test_framework

ostream& operator<<(ostream& out, const Name& n) { return out << n.first_name; }

vector<Name> EliminateDuplicateWrapper(vector<Name> names) {
    EliminateDuplicate(&names);
    return names;
}

bool Comp(vector<string> expected, vector<Name> result) {
    sort(begin(expected), end(expected));
    sort(begin(result), end(result));
    return equal(
        begin(expected), end(expected), begin(result), end(result),
        [](const string& s, const Name& n) { return s == n.first_name; });
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"names"};
    return GenericTestMain(args, "data.tsv", &EliminateDuplicateWrapper, &Comp,
                           param_names);
}
