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
