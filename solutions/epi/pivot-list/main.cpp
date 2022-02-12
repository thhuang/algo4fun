#include <epi/generic_test.h>
#include <epi/list_node.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>
using namespace std;

shared_ptr<ListNode<int>> ListPivoting(const shared_ptr<ListNode<int>>& l,
                                       int x) {
    auto less = make_shared<ListNode<int>>();
    auto equal = make_shared<ListNode<int>>();
    auto greater = make_shared<ListNode<int>>();
    auto less_head = less;
    auto equal_head = equal;
    auto greater_head = greater;

    for (auto p = l; p; p = p->next) {
        if (p->data < x) {
            less->next = p, less = less->next;
            continue;
        }
        if (p->data > x) {
            greater->next = p, greater = greater->next;
            continue;
        }
        equal->next = p, equal = equal->next;
    }

    greater->next = nullptr;
    equal->next = greater_head->next;
    less->next = equal_head->next;

    return less_head->next;
}

vector<int> ListToVector(const shared_ptr<ListNode<int>>& l) {
    vector<int> v;
    ListNode<int>* it = l.get();
    while (it) {
        v.push_back(it->data);
        it = it->next.get();
    }
    return v;
}

void ListPivotingWrapper(TimedExecutor& executor,
                         const shared_ptr<ListNode<int>>& l, int x) {
    vector<int> original = ListToVector(l);

    shared_ptr<ListNode<int>> pivoted_list =
        executor.Run([&] { return ListPivoting(l, x); });

    vector<int> pivoted = ListToVector(pivoted_list);
    enum class Mode { kLess, kEq, kGreater } mode = Mode::kLess;
    for (auto& i : pivoted) {
        switch (mode) {
            case Mode::kLess:
                if (i == x) {
                    mode = Mode::kEq;
                } else if (i > x) {
                    mode = Mode::kGreater;
                }
                break;
            case Mode::kEq:
                if (i < x) {
                    throw TestFailure("List is not pivoted");
                } else if (i > x) {
                    mode = Mode::kGreater;
                }
                break;
            case Mode::kGreater:
                if (i <= x) {
                    throw TestFailure("List is not pivoted");
                }
        }
    }
    sort(begin(original), end(original));
    sort(begin(pivoted), end(pivoted));
    if (original != pivoted) {
        throw TestFailure("Result list contains different values");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "l", "x"};
    return GenericTestMain(args, "data.tsv", &ListPivotingWrapper,
                           DefaultComparator{}, param_names);
}
