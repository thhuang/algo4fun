#include <epi/bst_node.h>
#include <epi/generic_test.h>

#include <algorithm>
#include <limits>
#include <memory>
using namespace std;

/* unique_ptr<BstNode<int>> ConstructNode(const vector<int>& preorder_sequence,
 */
/*                                        int l, int r) { */
/*     if (r < l) return nullptr; */

/*     int data = preorder_sequence[l]; */
/*     auto node = make_unique<BstNode<int>>(data); */

/*     auto it = upper_bound(preorder_sequence.begin() + l + 1, */
/*                           preorder_sequence.begin() + r + 1, data); */
/*     int m = it - begin(preorder_sequence); */

/*     node->left = ConstructNode(preorder_sequence, l + 1, m - 1); */
/*     node->right = ConstructNode(preorder_sequence, m, r); */

/*     return node; */
/* } */

/* unique_ptr<BstNode<int>> RebuildBSTFromPreorder( */
/*     const vector<int>& preorder_sequence) { */
/*     if (empty(preorder_sequence)) return nullptr; */
/*     return ConstructNode(preorder_sequence, 0, size(preorder_sequence) - 1);
 */
/* } */

unique_ptr<BstNode<int>> ConstructNode(const vector<int>& preorder_sequence,
                                       int minimum, int maximum, int& pos) {
    if (pos == size(preorder_sequence)) return nullptr;

    int data = preorder_sequence[pos];
    if (data < minimum || data > maximum) return nullptr;

    auto node = make_unique<BstNode<int>>(data);
    ++pos;

    node->left = ConstructNode(preorder_sequence, minimum, data, pos);
    node->right = ConstructNode(preorder_sequence, data, maximum, pos);

    return node;
}

unique_ptr<BstNode<int>> RebuildBSTFromPreorder(
    const vector<int>& preorder_sequence) {
    int pos = 0;
    return ConstructNode(preorder_sequence, numeric_limits<int>::min(),
                         numeric_limits<int>::max(), pos);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"preorder_sequence"};
    return GenericTestMain(args, "data.tsv", &RebuildBSTFromPreorder,
                           DefaultComparator{}, param_names);
}
