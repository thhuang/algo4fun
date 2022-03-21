#include <epi/fmt_print.h>
#include <epi/generic_test.h>
#include <epi/test_failure.h>

#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ClientsCreditsInfo {
   public:
    void Insert(const string& client_id, int c) {
        Remove(client_id);
        client_to_credit_[client_id] = c - offset_;
        credit_to_clients_[c - offset_].insert(client_id);
    }

    bool Remove(const string& client_id) {
        auto it = client_to_credit_.find(client_id);
        if (it == client_to_credit_.end()) return false;

        credit_to_clients_[it->second].erase(client_id);
        client_to_credit_.erase(it);
        return true;
    }

    int Lookup(const string& client_id) const {
        auto it = client_to_credit_.find(client_id);
        if (it == client_to_credit_.end()) return -1;
        return it->second + offset_;
    }

    void AddAll(int C) { offset_ += C; }

    string Max() const {
        return Empty() ? "" : *credit_to_clients_.rbegin()->second.begin();
    }

   private:
    int offset_ = 0;
    map<int, unordered_set<string>> credit_to_clients_;
    unordered_map<string, int> client_to_credit_;

    bool Empty() const { return empty(client_to_credit_); }
};

struct Operation {
    string op;
    string s_arg;
    int i_arg;
};

ostream& operator<<(ostream& out, const Operation& op) {
    return out << FmtStr("{}({}, {})", op.op, op.s_arg, op.i_arg);
}

namespace test_framework {
template <>
struct SerializationTrait<Operation>
    : UserSerTrait<Operation, string, string, int> {};
}  // namespace test_framework
void ClientsCreditsInfoTester(const vector<Operation>& ops) {
    ClientsCreditsInfo cr;
    int op_idx = 0;
    for (auto& op : ops) {
        if (op.op == "ClientsCreditsInfo") {
            continue;
        } else if (op.op == "remove") {
            bool result = cr.Remove(op.s_arg);
            if (result != op.i_arg) {
                throw TestFailure()
                    .WithProperty(PropertyName::STATE, cr)
                    .WithProperty(PropertyName::COMMAND, op)
                    .WithMismatchInfo(op_idx, op.i_arg, result);
            }
        } else if (op.op == "max") {
            auto result = cr.Max();
            if (result != op.s_arg) {
                throw TestFailure()
                    .WithProperty(PropertyName::STATE, cr)
                    .WithProperty(PropertyName::COMMAND, op)
                    .WithMismatchInfo(op_idx, op.i_arg, result);
            }
        } else if (op.op == "insert") {
            cr.Insert(op.s_arg, op.i_arg);
        } else if (op.op == "add_all") {
            cr.AddAll(op.i_arg);
        } else if (op.op == "lookup") {
            auto result = cr.Lookup(op.s_arg);
            if (result != op.i_arg) {
                throw TestFailure()
                    .WithProperty(PropertyName::STATE, cr)
                    .WithProperty(PropertyName::COMMAND, op)
                    .WithMismatchInfo(op_idx, op.i_arg, result);
                ;
            }
        }
        op_idx++;
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"ops"};
    return GenericTestMain(args, "data.tsv", &ClientsCreditsInfoTester,
                           DefaultComparator{}, param_names);
}
