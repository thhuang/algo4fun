#include <epi/generic_test.h>
#include <epi/list_node.h>
using namespace std;

shared_ptr<ListNode<int>> RangeReverse(shared_ptr<ListNode<int>> first,
                                       shared_ptr<ListNode<int>> last);
int GetNumNodes(shared_ptr<ListNode<int>> L);

bool IsLinkedListAPalindrome(shared_ptr<ListNode<int>> L) {
    int num_nodes = GetNumNodes(L);
    if (num_nodes < 2) return true;

    auto left = L;
    for (int i = 0; i < num_nodes / 2 - 1; ++i) left = left->next;
    auto right = left->next;
    if (num_nodes & 1) right = right->next;

    auto mid = left->next;
    RangeReverse(L, left);
    bool res = true;
    for (auto p0 = left, p1 = right; p1; p0 = p0->next, p1 = p1->next) {
        if (p0->data != p1->data) {
            res = false;
            break;
        }
    }
    RangeReverse(left, L);
    left->next = mid;

    return res;
}

shared_ptr<ListNode<int>> RangeReverse(shared_ptr<ListNode<int>> first,
                                       shared_ptr<ListNode<int>> last) {
    auto p0 = make_shared<ListNode<int>>(0, first);
    auto p1 = first;
    while (p1 != last) {
        auto p2 = p1->next;
        p1->next = p0;
        p0 = p1;
        p1 = p2;
    }
    p1->next = p0;
    return p1;
}

int GetNumNodes(shared_ptr<ListNode<int>> L) {
    int num = 0;
    while (L) ++num, L = L->next;
    return num;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"L"};
    return GenericTestMain(args, "data.tsv", &IsLinkedListAPalindrome,
                           DefaultComparator{}, param_names);
}
