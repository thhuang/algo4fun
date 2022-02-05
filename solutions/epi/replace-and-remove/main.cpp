#include <epi/generic_test.h>
#include <epi/timed_executor.h>
using namespace std;

int ReplaceAndRemove(int size, char s[]) {
    int write_idx = 0;
    int res_size = 0;
    for (int i = 0; i < size; ++i) {
        if (s[i] == 'b') continue;
        s[write_idx++] = s[i];

        if (s[i] == 'a') ++res_size;
        ++res_size;
    }

    int removed_size = write_idx;
    write_idx = res_size - 1;
    for (int i = removed_size - 1; ~i; --i) {
        if (s[i] == 'b') continue;
        if (s[i] == 'a') {
            s[write_idx--] = 'd';
            s[write_idx--] = 'd';
            continue;
        }
        s[write_idx--] = s[i];
    }

    return res_size;
}
vector<string> ReplaceAndRemoveWrapper(TimedExecutor& executor, int size,
                                       const vector<string>& s) {
    vector<char> s_copy(s.size(), '\0');
    for (int i = 0; i < s.size(); ++i) {
        if (!s[i].empty()) {
            s_copy[i] = s[i][0];
        }
    }

    int res_size =
        executor.Run([&] { return ReplaceAndRemove(size, s_copy.data()); });

    vector<string> result;
    for (int i = 0; i < res_size; ++i) {
        result.emplace_back(string(1, s_copy[i]));
    }
    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "size", "s"};
    return GenericTestMain(args, "data.tsv", &ReplaceAndRemoveWrapper,
                           DefaultComparator{}, param_names);
}
