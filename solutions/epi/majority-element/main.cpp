#include <epi/generic_test.h>

#include <string>
#include <vector>
using namespace std;

string MajoritySearch(vector<string>::const_iterator stream_begin,
                      const vector<string>::const_iterator stream_end) {
    int count = 0;
    string word;
    for (auto it = stream_begin; it != stream_end; ++it) {
        if (count == 0) {
            ++count;
            word = *it;
            continue;
        }

        count += *it == word ? 1 : -1;
    }

    return word;
}
string MajoritySearchWrapper(const vector<string>& stream) {
    return MajoritySearch(cbegin(stream), cend(stream));
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"stream"};
    return GenericTestMain(args, "data.tsv", &MajoritySearchWrapper,
                           DefaultComparator{}, param_names);
}
