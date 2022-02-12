#include <epi/generic_test.h>
#include <epi/list_node.h>
using namespace std;

shared_ptr<ListNode<int>> AddTwoNumbers(shared_ptr<ListNode<int>> L1,
                                        shared_ptr<ListNode<int>> L2) {
    auto dummy = make_shared<ListNode<int>>();
    auto p = dummy;
    int carry = 0;
    while (L1 || L2 || carry) {
        int sum = carry;
        if (L1) sum += L1->data, L1 = L1->next;
        if (L2) sum += L2->data, L2 = L2->next;
        carry = sum / 10;
        p->next = make_shared<ListNode<int>>(sum % 10, nullptr);
        p = p->next;
    }

    return dummy->next;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"L1", "L2"};
    return GenericTestMain(args, "data.tsv", &AddTwoNumbers,
                           DefaultComparator{}, param_names);
}
