#include <epi/generic_test.h>

#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> char_to_decimal{
    {'0', 0},  {'1', 1},  {'2', 2},  {'3', 3},  {'4', 4},  {'5', 5},
    {'6', 6},  {'7', 7},  {'8', 8},  {'9', 9},  {'A', 10}, {'B', 11},
    {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
};

unordered_map<int, char> decimal_to_char{
    {0, '0'},  {1, '1'},  {2, '2'},  {3, '3'},  {4, '4'},  {5, '5'},
    {6, '6'},  {7, '7'},  {8, '8'},  {9, '9'},  {10, 'A'}, {11, 'B'},
    {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'},
};

string ConvertBase(const string& num_as_string, int b1, int b2) {
    if (num_as_string == "0") return "0";

    bool is_negative = false;
    long long x = 0;
    long long mul = 1;
    for (int i = size(num_as_string) - 1; ~i; --i) {
        if (num_as_string[i] == '-') {
            is_negative = true;
            break;
        }
        x += char_to_decimal[num_as_string[i]] * mul;
        mul *= b1;
    }

    string rs;
    while (x) {
        rs += decimal_to_char[x % b2];
        x /= b2;
    }
    if (is_negative) rs += '-';

    return {crbegin(rs), crend(rs)};
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"num_as_string", "b1", "b2"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &ConvertBase,
                           DefaultComparator{}, param_names);
}
