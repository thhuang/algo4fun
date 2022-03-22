#include <epi/generic_test.h>

#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

vector<string> PhoneMnemonic(const string& phone_number) {
    auto digit_to_chars = array<string, 10>{
        "0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    vector<string> result;

    function<void(int, string)> search = [&](int i, string s) {
        if (i == size(phone_number)) {
            result.emplace_back(s);
            return;
        }

        int digit = phone_number[i] - '0';
        for (char c : digit_to_chars[digit]) search(i + 1, s + c);
    };

    search(0, "");

    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"phone_number"};
    return GenericTestMain(args, "data.tsv", &PhoneMnemonic,
                           UnorderedComparator{}, param_names);
}
