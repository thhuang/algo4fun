#include <epi/binary_tree_utils.h>
#include <epi/bst_node.h>
#include <epi/generic_test.h>
#include <epi/timed_executor.h>

#include <memory>
using namespace std;

bool PairIncludesAncestorAndDescendantOfM(
    const unique_ptr<BstNode<int>>& possible_anc_or_desc_0,
    const unique_ptr<BstNode<int>>& possible_anc_or_desc_1,
    const unique_ptr<BstNode<int>>& middle) {
    if (!possible_anc_or_desc_0 || !possible_anc_or_desc_1 || !middle)
        return false;

    if (possible_anc_or_desc_0->data == middle->data ||
        possible_anc_or_desc_1->data == middle->data)
        return false;

    auto p = middle.get();
    BstNode<int>* lower;
    auto p0 = possible_anc_or_desc_0.get();
    auto p1 = possible_anc_or_desc_1.get();
    while (p0 || p1) {
        if (p0) {
            if (p0 == p) {
                lower = possible_anc_or_desc_1.get();
                break;
            }
            auto& up0 = p->data > p0->data ? p0->right : p0->left;
            p0 = up0 ? up0.get() : nullptr;
        }
        if (p1) {
            if (p1 == p) {
                lower = possible_anc_or_desc_0.get();
                break;
            }
            auto& up1 = p->data > p1->data ? p1->right : p1->left;
            p1 = up1 ? up1.get() : nullptr;
        }
    }
    if (!p0 && !p1) return false;

    while (p) {
        if (p == lower) return true;
        auto& up = lower->data > p->data ? p->right : p->left;
        p = up ? up.get() : nullptr;
    }

    return false;
}

bool PairIncludesAncestorAndDescendantOfMWrapper(
    TimedExecutor& executor, const unique_ptr<BstNode<int>>& tree,
    int possible_anc_or_desc_0, int possible_anc_or_desc_1, int middle) {
    auto& candidate0 = MustFindNode(tree, possible_anc_or_desc_0);
    auto& candidate1 = MustFindNode(tree, possible_anc_or_desc_1);
    auto& middle_node = MustFindNode(tree, middle);
    return executor.Run([&] {
        return PairIncludesAncestorAndDescendantOfM(candidate0, candidate1,
                                                    middle_node);
    });
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "tree", "possible_anc_or_desc_0",
                               "possible_anc_or_desc_1", "middle"};
    return GenericTestMain(args, "data.tsv",
                           &PairIncludesAncestorAndDescendantOfMWrapper,
                           DefaultComparator{}, param_names);
}
