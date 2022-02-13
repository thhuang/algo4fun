#include <epi/generic_test.h>

#include <iostream>
#include <string>
using namespace std;

int Evaluate(const string& expression) {
    stringstream ss(expression);
    const char kDelimiter = ',';
    map<string, function<int(int, int)>> op_map = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }},
    };

    string token;
    stack<int> intermediate;
    while (getline(ss, token, kDelimiter)) {
        if (op_map.count(token)) {
            int a, b;
            b = intermediate.top(), intermediate.pop();
            a = intermediate.top(), intermediate.pop();
            intermediate.push(op_map[token](a, b));
            continue;
        }
        intermediate.push(stoi(token));
    }

    return intermediate.top();
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"expression"};
    return GenericTestMain(args, "data.tsv", &Evaluate, DefaultComparator{},
                           param_names);
}
