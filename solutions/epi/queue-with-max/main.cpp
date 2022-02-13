#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/test_failure.h>
using namespace std;

class QueueWithMax {
   public:
    void Enqueue(int x) {
        q_.push(x);

        while (!max_.empty() && x > max_.back()) max_.pop_back();
        max_.push_back(x);
    }

    int Dequeue() {
        int val = q_.front();
        q_.pop();

        if (val == max_.front()) max_.pop_front();

        return val;
    }

    int Max() const { return max_.front(); }

   private:
    queue<int> q_;
    deque<int> max_;
};

struct QueueOp {
    enum class Operation { kConstruct, kDequeue, kEnqueue, kMax } op;
    int argument;

    QueueOp(const string& op_string, int arg) : argument(arg) {
        if (op_string == "QueueWithMax") {
            op = Operation::kConstruct;
        } else if (op_string == "dequeue") {
            op = Operation::kDequeue;
        } else if (op_string == "enqueue") {
            op = Operation::kEnqueue;
        } else if (op_string == "max") {
            op = Operation::kMax;
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
        QueueWithMax q;
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
                case QueueOp::Operation::kMax: {
                    int s = q.Max();
                    if (s != x.argument) {
                        throw TestFailure("Max: expected " +
                                          to_string(x.argument) + ", got " +
                                          to_string(s));
                    }
                } break;
            }
        }
    } catch (const length_error&) {
        throw TestFailure("Unexpected length_error exception");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"ops"};
    return GenericTestMain(args, "data.tsv", &QueueTester, DefaultComparator{},
                           param_names);
}
