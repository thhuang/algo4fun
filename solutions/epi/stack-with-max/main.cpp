#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/test_failure.h>
using namespace std;

class Stack {
   public:
    bool Empty() const { return data_.empty(); }
    int Max() const { return data_.top().max; }
    int Pop() {
        int val = data_.top().val;
        data_.pop();
        return val;
    }
    void Push(int x) {
        int max_val = data_.empty() ? x : max(data_.top().max, x);
        data_.push(ElementWithMax{x, max_val});
    }

   private:
    struct ElementWithMax {
        int val;
        int max;
    };
    stack<ElementWithMax> data_;
};

struct StackOp {
    string op;
    int argument;
};

namespace test_framework {
template <>
struct SerializationTrait<StackOp> : UserSerTrait<StackOp, string, int> {};
}  // namespace test_framework

void StackTester(const vector<StackOp>& ops) {
    try {
        Stack s;
        for (auto& x : ops) {
            if (x.op == "Stack") {
                continue;
            } else if (x.op == "push") {
                s.Push(x.argument);
            } else if (x.op == "pop") {
                int result = s.Pop();
                if (result != x.argument) {
                    throw TestFailure("Pop: expected " + to_string(x.argument) +
                                      ", got " + to_string(result));
                }
            } else if (x.op == "max") {
                int result = s.Max();
                if (result != x.argument) {
                    throw TestFailure("Max: expected " + to_string(x.argument) +
                                      ", got " + to_string(result));
                }
            } else if (x.op == "empty") {
                int result = s.Empty();
                if (result != x.argument) {
                    throw TestFailure("Empty: expected " +
                                      to_string(x.argument) + ", got " +
                                      to_string(result));
                }
            } else {
                throw runtime_error("Unsupported stack operation: " + x.op);
            }
        }
    } catch (length_error&) {
        throw TestFailure("Unexpected length_error exception");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"ops"};
    return GenericTestMain(args, "data.tsv", &StackTester, DefaultComparator{},
                           param_names);
}
