#include <epi/generic_test.h>

using namespace std;

string ShortestEquivalentPath(const string& path) {
    if (size(path) == 0) throw invalid_argument("empty path");

    vector<string> curr_path;
    if (path[0] == '/') curr_path.push_back("/");

    stringstream ss(path);
    string token;
    const char kDelimiter = '/';
    while (getline(ss, token, kDelimiter)) {
        if (token == "" || token == ".") continue;
        if (token != "..") {
            curr_path.push_back(token);
            continue;
        }

        // token is ".."
        if (curr_path.empty() || curr_path.back() == "..") {
            curr_path.push_back(token);
            continue;
        }
        if (curr_path.back() == "/") throw invalid_argument("invalid path");
        curr_path.pop_back();
    }

    string res = curr_path[0];
    if (res == "/" && size(curr_path) > 1) res = ""; 
    for (int i = 1; i < size(curr_path); ++i) {
        res += "/" + curr_path[i];
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"path"};
    return GenericTestMain(args, "data.tsv", &ShortestEquivalentPath,
                           DefaultComparator{}, param_names);
}
