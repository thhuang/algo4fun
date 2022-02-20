#include <epi/generic_test.h>

#include <queue>
#include <vector>
using namespace std;

struct Container {
    priority_queue<int, vector<int>, less<>> left;
    priority_queue<int, vector<int>, greater<>> right;

    void push(int val) {
        left.emplace(val);
        right.emplace(left.top());
        left.pop();

        if (size(right) > size(left)) {
            left.emplace(right.top());
            right.pop();
        }
    }

    double median() {
        if (size(left) > size(right)) return left.top();
        return 0.5 * (left.top() + right.top());
    }
};

vector<double> OnlineMedian(vector<int>::const_iterator sequence_begin,
                            const vector<int>::const_iterator& sequence_end) {
    Container container;
    vector<double> result;
    for (auto iter = sequence_begin; iter != sequence_end; ++iter) {
        container.push(*iter);
        result.emplace_back(container.median());
    }
    return result;
}

vector<double> OnlineMedianWrapper(const vector<int>& sequence) {
    return OnlineMedian(cbegin(sequence), cend(sequence));
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"sequence"};
    return GenericTestMain(args, "data.tsv", &OnlineMedianWrapper,
                           DefaultComparator{}, param_names);
}
