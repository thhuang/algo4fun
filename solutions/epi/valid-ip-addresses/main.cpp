#include <epi/generic_test.h>

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool IsValid(const string& s, int b, int e);

vector<string> GetValidIpAddress(const string& s) {
    vector<string> res;
    for (int i = 1; i < size(s); ++i) {
        if (!IsValid(s, 0, i)) continue;

        for (int j = i + 1; j < size(s); ++j) {
            if (!IsValid(s, i, j)) continue;

            for (int k = j + 1; k < size(s); ++k) {
                if (!IsValid(s, j, k)) continue;
                if (!IsValid(s, k, size(s))) continue;

                auto ip = s.substr(0, i) + "." + s.substr(i, j - i) + "." +
                          s.substr(j, k - j) + "." + s.substr(k, size(s) - k);
                res.emplace_back(ip);
            }
        }
    }
    return res;
}

bool IsValid(const string& s, int b, int e) {
    int len = e - b;
    if (len == 0 || len > 3 || e > size(s)) return false;
    if (len > 1 && s[b] == '0') return false;

    int num = stoi(s.substr(b, len));
    return 0 <= num && num <= 255;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"s"};
    return GenericTestMain(args, "data.tsv", &GetValidIpAddress,
                           UnorderedComparator{}, param_names);
}
