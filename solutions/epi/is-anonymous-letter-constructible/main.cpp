#include <epi/generic_test.h>

#include <string>
#include <unordered_map>
using namespace std;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
    unordered_map<char, int> char_count;
    for (char c : magazine_text) ++char_count[c];
    for (char c : letter_text) {
        if (--char_count[c] < 0) return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"letter_text", "magazine_text"};
    return GenericTestMain(args, "data.tsv", &IsLetterConstructibleFromMagazine,
                           DefaultComparator{}, param_names);
}
