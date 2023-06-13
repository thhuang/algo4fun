class Solution {
   public:
    int shortestWay(string source, string target) {
        int count = 0;
        int l = 0;
        while (l < target.size()) {
            ++count;
            int r = l;
            for (char c : source) {
                if (c == target[r]) ++r;
            }
            if (r == l) return -1;
            l = r;
        }
        return count;
    }
};

class Solution {
   public:
    int shortestWay(string source, string target) {
        unordered_set<int> chars(source.begin(), source.end());
        for (char c : target) {
            if (chars.count(c) == 0) return -1;
        }

        int result = 1;
        int i = 0;
        for (char c : target) {
            if (i == source.size()) i = 0, ++result;
            while (source[i] != c) {
                ++i;
                if (i == source.size()) i = 0, ++result;
            }
            ++i;
        }

        return result;
    }
};
