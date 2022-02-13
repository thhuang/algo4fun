#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/test_failure.h>
using namespace std;

class Queue {
   public:
    Queue(size_t capacity) : entries_(vector<int>(capacity)) {}

    void Enqueue(int x) {
        if (size_ == size(entries_)) Expand();
        entries_[end_] = x;
        end_ = Abs(end_ + 1);
        ++size_;
    }

    int Dequeue() {
        if (size_ == 0) throw out_of_range("empty queue");
        int val = entries_[begin_];
        begin_ = Abs(begin_ + 1);
        --size_;
        return val;
    }

    int Size() const { return size_; }

   private:
    const int kExpandFactor = 2;
    vector<int> entries_;
    int size_ = 0;
    int begin_ = 0;
    int end_ = 0;

    int Abs(int x) const { return (x + size(entries_)) % size(entries_); }

    void Expand() {
        rotate(begin(entries_), begin(entries_) + begin_, end(entries_));
        entries_.resize(size(entries_) * 2);
        begin_ = 0;
        end_ = size_;
    }
};

struct QueueOp {
    enum class Operation { kConstruct, kDequeue, kEnqueue, kSize } op;
    int argument;

    QueueOp(const string& op_string, int arg) : argument(arg) {
        if (op_string == "Queue") {
            op = Operation::kConstruct;
        } else if (op_string == "dequeue") {
            op = Operation::kDequeue;
        } else if (op_string == "enqueue") {
            op = Operation::kEnqueue;
        } else if (op_string == "size") {
            op = Operation::kSize;
        } else {
            throw runtime_error("Unsupported queue operation: " + op_string);
        }
    }

    void execute(Queue& q) const {
        switch (op) {
            case Operation::kConstruct:
                // Hack to bypass deleted assign operator
                q.~Queue();
                new (&q) Queue(argument);
                break;
            case Operation::kDequeue: {
                int result = q.Dequeue();
                if (result != argument) {
                    throw TestFailure("Dequeue: expected " +
                                      to_string(argument) + ", got " +
                                      to_string(result));
                }
            } break;
            case Operation::kEnqueue:
                q.Enqueue(argument);
                break;
            case Operation::kSize: {
                int s = q.Size();
                if (s != argument) {
                    throw TestFailure("Size: expected " + to_string(argument) +
                                      ", got " + to_string(s));
                }
            } break;
        }
    }
};

namespace test_framework {
template <>
struct SerializationTrait<QueueOp> : UserSerTrait<QueueOp, string, int> {};
}  // namespace test_framework

void QueueTester(const vector<QueueOp>& ops) {
    Queue q(0);
    for (auto& op : ops) {
        op.execute(q);
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"ops"};
    return GenericTestMain(args, "data.tsv", &QueueTester, DefaultComparator{},
                           param_names);
}
