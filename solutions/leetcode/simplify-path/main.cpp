class Solution {
   public:
    string simplifyPath(string path) {
        path += "/";
        regex slashes("//+");
        path = regex_replace(path, slashes, "/");

        vector<string> dirs;
        for (int l = 0, r = path.find('/', l + 1); r != string::npos;
             l = r, r = path.find('/', l + 1)) {
            string dir = path.substr(l + 1, r - l - 1);
            if (dir == ".") continue;
            if (dir == "..") {
                if (!dirs.empty()) dirs.pop_back();
                continue;
            }
            dirs.push_back(dir);
        }

        if (dirs.empty()) return "/";

        string result;
        for (auto s : dirs) result += "/" + s;

        return result;
    }
};
