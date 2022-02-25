#include <epi/generic_test.h>

#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> FindAnagrams(const vector<string>& dictionary) {
    unordered_map<string, vector<string>> anagram_map;
    for (const auto& s : dictionary) {
        string sorted_str(s);
        sort(sorted_str.begin(), sorted_str.end());
        anagram_map[sorted_str].emplace_back(s);
    }

    vector<vector<string>> res;
    for (const auto& [_, strs] : anagram_map) {
        if (size(strs) >= 2) res.emplace_back(strs);
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"dictionary"};
    return GenericTestMain(args, "data.tsv", &FindAnagrams,
                           UnorderedComparator{}, param_names);
}
