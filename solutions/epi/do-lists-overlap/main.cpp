#include <epi/generic_test.h>
#include <epi/list_node.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <set>
#include <stdexcept>
using namespace std;

shared_ptr<ListNode<int>> GetCycle(shared_ptr<ListNode<int>> l);
shared_ptr<ListNode<int>> OverlappingNoCycleLists(shared_ptr<ListNode<int>> l0,
                                                  shared_ptr<ListNode<int>> l1);
int GetLength(shared_ptr<ListNode<int>> l);
shared_ptr<ListNode<int>> Advance(shared_ptr<ListNode<int>> n, int steps);

shared_ptr<ListNode<int>> OverlappingLists(shared_ptr<ListNode<int>> l0,
                                           shared_ptr<ListNode<int>> l1) {
    auto c0 = GetCycle(l0);
    auto c1 = GetCycle(l1);
    auto hasCycle0 = c0 != nullptr;
    auto hasCycle1 = c1 != nullptr;

    if (hasCycle0 != hasCycle1) return nullptr;
    if (!hasCycle0 && !hasCycle1) return OverlappingNoCycleLists(l0, l1);

    auto p = c0;
    while (1) {
        if (p == c1) return p;
        p = p->next;
        if (p == c0) break;
    }
    return nullptr;
}

shared_ptr<ListNode<int>> GetCycle(shared_ptr<ListNode<int>> l) {
    auto fast = l;
    auto slow = l;
    while (fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return slow;
    }

    return nullptr;
}

shared_ptr<ListNode<int>> OverlappingNoCycleLists(
    shared_ptr<ListNode<int>> l0, shared_ptr<ListNode<int>> l1) {
    int length0 = GetLength(l0);
    int length1 = GetLength(l1);
    int diff = abs(length0 - length1);
    if (length0 > length1)
        l0 = Advance(l0, diff);
    else
        l1 = Advance(l1, diff);

    while (l0 && l1) {
        if (l0 == l1) return l0;
        l0 = l0->next;
        l1 = l1->next;
    }
    return nullptr;
}

int GetLength(shared_ptr<ListNode<int>> l) {
    int length = 0;
    while (l && l->next) ++length, l = l->next;
    return length;
}

shared_ptr<ListNode<int>> Advance(shared_ptr<ListNode<int>> n, int steps) {
    while (steps--) n = n->next;
    return n;
}

void OverlappingListsWrapper(TimedExecutor& executor,
                             shared_ptr<ListNode<int>> l0,
                             shared_ptr<ListNode<int>> l1,
                             shared_ptr<ListNode<int>> common, int cycle0,
                             int cycle1) {
    if (common) {
        if (!l0) {
            l0 = common;
        } else {
            auto it = l0;
            while (it->next) {
                it = it->next;
            }
            it->next = common;
        }

        if (!l1) {
            l1 = common;
        } else {
            auto it = l1;
            while (it->next) {
                it = it->next;
            }
            it->next = common;
        }
    }

    if (cycle0 != -1 && l0) {
        auto last = l0;
        while (last->next) {
            last = last->next;
        }
        auto it = l0;
        while (cycle0-- > 0) {
            if (!it) {
                throw runtime_error("Invalid input data");
            }
            it = it->next;
        }
        last->next = it;
    }

    if (cycle1 != -1 && l1) {
        auto last = l1;
        while (last->next) {
            last = last->next;
        }
        auto it = l1;
        while (cycle1-- > 0) {
            if (!it) {
                throw runtime_error("Invalid input data");
            }
            it = it->next;
        }
        last->next = it;
    }

    set<shared_ptr<ListNode<int>>> common_nodes;
    auto it = common;
    while (it && common_nodes.count(it) == 0) {
        common_nodes.insert(it);
        it = it->next;
    }

    auto result = executor.Run([&] { return OverlappingLists(l0, l1); });

    if (!((common_nodes.empty() && result == nullptr) ||
          common_nodes.count(result) > 0)) {
        throw TestFailure("Invalid result");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "l0",     "l1",
                               "common",   "cycle0", "cycle1"};
    return GenericTestMain(args, "data.tsv", &OverlappingListsWrapper,
                           DefaultComparator{}, param_names);
}
