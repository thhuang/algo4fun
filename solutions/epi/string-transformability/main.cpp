#include <epi/generic_test.h>

#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

int TransformString(const unordered_set<string>& D, const string& s,
                    const string& t) {
    struct Entry {
        string s;
        int d;
    };

    queue<Entry> q;
    unordered_set<string> seen;
    q.push({s, 0});
    seen.insert(s);

    while (!empty(q)) {
        auto entry = q.front();
        q.pop();

        for (int i = 0; i < size(s); ++i) {
            string str = entry.s;
            for (int j = 0; j < 26; ++j) {
                str[i] = 'a' + j;
                if (str == t) return entry.d + 1;
                if (!D.count(str)) continue;
                if (seen.count(str)) continue;
                q.push({str, entry.d + 1});
                seen.insert(str);
            }
        }
    }

    return -1;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"D", "s", "t"};
    return GenericTestMain(args, "data.tsv", &TransformString,
                           DefaultComparator{}, param_names);
}
