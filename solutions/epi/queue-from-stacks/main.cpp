#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/test_failure.h>
using namespace std;

class Queue {
   public:
    void Enqueue(int x) { inputs_.push(x); }
    int Dequeue() {
        if (outputs_.empty()) {
            if (inputs_.empty()) throw out_of_range("empty queue");

            while (!inputs_.empty()) {
                outputs_.push(inputs_.top());
                inputs_.pop();
            }
        }

        int val = outputs_.top();
        outputs_.pop();
        return val;
    }

   private:
    stack<int> inputs_;
    stack<int> outputs_;
};

struct QueueOp {
    enum class Operation { kConstruct, kDequeue, kEnqueue } op;
    int argument;

    QueueOp(const string& op_string, int arg) : argument(arg) {
        if (op_string == "Queue") {
            op = Operation::kConstruct;
        } else if (op_string == "dequeue") {
            op = Operation::kDequeue;
        } else if (op_string == "enqueue") {
            op = Operation::kEnqueue;
        } else {
            throw runtime_error("Unsupported queue operation: " + op_string);
        }
    }
};

namespace test_framework {
template <>
struct SerializationTrait<QueueOp> : UserSerTrait<QueueOp, string, int> {};
}  // namespace test_framework

void QueueTester(const vector<QueueOp>& ops) {
    try {
        Queue q;
        for (auto& x : ops) {
            switch (x.op) {
                case QueueOp::Operation::kConstruct:
                    break;
                case QueueOp::Operation::kDequeue: {
                    int result = q.Dequeue();
                    if (result != x.argument) {
                        throw TestFailure("Dequeue: expected " +
                                          to_string(x.argument) + ", got " +
                                          to_string(result));
                    }
                } break;
                case QueueOp::Operation::kEnqueue:
                    q.Enqueue(x.argument);
                    break;
            }
        }
    } catch (length_error&) {
        throw TestFailure("Unexpected length_error exception");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"ops"};
    return GenericTestMain(args, "data.tsv", &QueueTester, DefaultComparator{},
                           param_names);
}
