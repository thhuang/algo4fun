#include <epi/generic_test.h>
#include <epi/timed_executor.h>

#include <string>
using namespace std;

void ReverseWords(string* s_ptr) {
    string& s = *s_ptr;
    reverse(s.begin(), s.end());

    int l = 0, r = 0;
    while (r < size(s)) {
        if (s[r++] != ' ') continue;
        reverse(s.begin() + l, s.begin() + r - 1);
        l = r;
    }
    reverse(s.begin() + l, s.begin() + r);
}

string ReverseWordsWrapper(TimedExecutor& executor, string s) {
    string s_copy = s;

    executor.Run([&] { ReverseWords(&s_copy); });

    return s_copy;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "s"};
    return GenericTestMain(args, "data.tsv", &ReverseWordsWrapper,
                           DefaultComparator{}, param_names);
}
