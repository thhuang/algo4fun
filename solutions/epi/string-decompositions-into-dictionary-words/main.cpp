#include <epi/generic_test.h>

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool IsSubstring(const string& s, const unordered_map<string, int>& word_freq,
                 int word_length) {
    unordered_map<string, int> substr_word_freq;
    for (int i = 0; i < size(s); i += word_length) {
        string word = s.substr(i, word_length);
        if (!word_freq.count(word)) return false;
        if (++substr_word_freq[word] > word_freq.at(word)) return false;
    }
    return true;
}

vector<int> FindAllSubstrings(const string& s, const vector<string>& words) {
    vector<int> res;

    int word_length = size(words.front());
    int substr_length = 0;
    unordered_map<string, int> word_freq;
    for (const string& w : words) ++word_freq[w], substr_length += word_length;

    for (int i = 0; i <= int(size(s)) - substr_length; ++i) {
        if (IsSubstring(s.substr(i, substr_length), word_freq, word_length)) {
            res.emplace_back(i);
        }
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"s", "words"};
    return GenericTestMain(args, "data.tsv", &FindAllSubstrings,
                           DefaultComparator{}, param_names);
}
