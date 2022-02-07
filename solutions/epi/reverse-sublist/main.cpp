#include <epi/generic_test.h>
#include <epi/list_node.h>
using namespace std;

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
    if (start == finish) return L;

    auto dummy = make_shared<ListNode<int>>(0, L);
    auto prev = dummy;
    for (int i = 1; i < start; ++i) prev = prev->next;

    auto p1 = prev->next;
    while (start++ < finish) {
        //    ____________
        //   |            v
        // prev p1 <<<<<< x p2 >>>>>>
        //       |           ^
        //        -----------

        auto p2 = p1->next;
        p1->next = p2->next;
        p2->next = prev->next;
        prev->next = p2;
    }

    return dummy->next;
}

/* shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int
 * start, */
/*                                          int finish) { */
/*     if (start == finish) return L; */

/*     auto dummy = make_shared<ListNode<int>>(0, L); */
/*     auto prev = dummy; */
/*     for (int i = 1; i < start; ++i) prev = prev->next; */

/*     auto p2 = prev->next; */
/*     auto p3 = p2->next; */
/*     p2->next = nullptr; */

/*     while (start++ < finish) { */
/*         auto p1 = p2; */
/*         p2 = p3; */
/*         p3 = p2->next; */

/*         p2->next = p1; */
/*     } */

/*     prev->next = p2; */
/*     while (p2->next) p2 = p2->next; */
/*     p2->next = p3; */

/*     return dummy->next; */
/* } */

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"L", "start", "finish"};
    return GenericTestMain(args, "data.tsv", &ReverseSublist,
                           DefaultComparator{}, param_names);
}
