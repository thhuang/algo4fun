#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/test_failure.h>

#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class LruCache {
   public:
    LruCache(size_t capacity) : capacity_(capacity) {}
    int Lookup(int isbn) {
        auto it = data_.find(isbn);
        if (it == end(data_)) return -1;

        int res = it->second.second;
        MoveToFront(it->second.first);

        return res;
    }

    void Insert(int isbn, int price) {
        auto it = data_.find(isbn);
        if (it != end(data_)) {
            MoveToFront(it->second.first);
            return;
        }

        if (size(data_) == capacity_) Erase(order_.back());

        order_.emplace_front(isbn);
        data_[isbn] = {begin(order_), price};
    }

    bool Erase(int isbn) {
        auto it = data_.find(isbn);
        if (it == end(data_)) return false;

        order_.erase(it->second.first);
        data_.erase(it);

        return true;
    }

   private:
    size_t capacity_;
    list<int> order_;
    unordered_map<int, pair<list<int>::iterator, int>> data_;

    void MoveToFront(list<int>::iterator it) {
        int key = *it;
        order_.erase(it);
        order_.emplace_front(key);
        data_[key].first = begin(order_);
    }
};

struct Op {
    string code;
    int arg1;
    int arg2;
};

namespace test_framework {
template <>
struct SerializationTrait<Op> : UserSerTrait<Op, string, int, int> {};
}  // namespace test_framework

void LruCacheTester(const vector<Op>& commands) {
    if (commands.empty() || commands[0].code != "LruCache") {
        throw runtime_error("Expected LruCache as first command");
    }
    LruCache cache(commands[0].arg1);

    for (int i = 1; i < commands.size(); i++) {
        auto& cmd = commands[i];
        if (cmd.code == "lookup") {
            int result = cache.Lookup(cmd.arg1);
            if (result != cmd.arg2) {
                throw TestFailure("Lookup: expected " + to_string(cmd.arg2) +
                                  ", got " + to_string(result));
            }
        } else if (cmd.code == "insert") {
            cache.Insert(cmd.arg1, cmd.arg2);
        } else if (cmd.code == "erase") {
            bool result = cache.Erase(cmd.arg1);
            if (result != cmd.arg2) {
                throw TestFailure("Erase: expected " + to_string(cmd.arg2) +
                                  ", got " + to_string(result));
            }
        } else {
            throw runtime_error("Unexpected command " + cmd.code);
        }
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"commands"};
    return GenericTestMain(args, "data.tsv", &LruCacheTester,
                           DefaultComparator{}, param_names);
}
