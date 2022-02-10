#include <epi/generic_test.h>
#include <epi/list_node.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <memory>
using namespace std;

int Length(shared_ptr<ListNode<int>> node) {
    int length = 1;
    while (node) {
        node = node->next;
        ++length;
    }
    return length;
}

shared_ptr<ListNode<int>> Advance(shared_ptr<ListNode<int>> node, int steps) {
    while (steps--) {
        node = node->next;
    }
    return node;
}

shared_ptr<ListNode<int>> OverlappingNoCycleLists(
    shared_ptr<ListNode<int>> l0, shared_ptr<ListNode<int>> l1) {
    int dist0 = Length(l0);
    int dist1 = Length(l1);

    int diff = abs(dist0 - dist1);
    if (dist0 > dist1) {
        l0 = Advance(l0, diff);
    } else {
        l1 = Advance(l1, diff);
    }

    while (1) {
        if (l0 == l1) return l0;
        l0 = l0->next;
        l1 = l1->next;
    }
    return nullptr;
}

void OverlappingNoCycleListsWrapper(TimedExecutor& executor,
                                    shared_ptr<ListNode<int>> l0,
                                    shared_ptr<ListNode<int>> l1,
                                    shared_ptr<ListNode<int>> common) {
    if (common) {
        if (l0) {
            auto i = l0;
            while (i->next) {
                i = i->next;
            }
            i->next = common;
        } else {
            l0 = common;
        }

        if (l1) {
            auto i = l1;
            while (i->next) {
                i = i->next;
            }
            i->next = common;
        } else {
            l1 = common;
        }
    }

    auto result = executor.Run([&] { return OverlappingNoCycleLists(l0, l1); });

    if (result != common) {
        throw TestFailure("Invalid result");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "l0", "l1", "common"};
    return GenericTestMain(args, "data.tsv", &OverlappingNoCycleListsWrapper,
                           DefaultComparator{}, param_names);
}
