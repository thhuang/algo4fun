class Solution {
   public:
    int characterReplacement(string s, int k) {
        int result = 0;
        for (char c = 'A'; c <= 'Z'; ++c) {
            int diff = 0;
            for (int l = 0, r = 0; r < s.size(); ++r) {
                if (s[r] != c) ++diff;
                while (diff > k) {
                    if (s[l++] != c) --diff;
                }
                result = max(result, r - l + 1);
            }
        }
        return result;
    }
};

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int result = 0;

        array<int, 26> charCount;
        charCount.fill(0);

        deque<int> desc;

        for (int l = 0, r = 0; r < s.size(); ++r) {
            int c = s[r];
            if (int v = charCount[c - 'A'];
                !desc.empty() && v == desc.front()) {
                desc.pop_front();
            }

            int v = ++charCount[c - 'A'];
            while (!desc.empty() && desc.back() < v) {
                desc.pop_back();
            }
            desc.push_back(v);

            while (r - l + 1 - desc.front() > k) {
                char t = s[l++];
                int a = charCount[t - 'A'];
                if (desc.front() == a) desc.pop_front();

                int b = --charCount[t - 'A'];
                while (!desc.empty() && desc.back() < b) {
                    desc.pop_back();
                }
                desc.push_back(b);
            }

            result = max(result, r - l + 1);
        }

        return result;
    }
};

class Solution {
   public:
    int characterReplacement(string s, int k) {
        array<int, 26> count;
        count.fill(0);
        int max_count = 0;
        int result = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            max_count = max(max_count, ++count[s[r] - 'A']);
            while (r - l + 1 - max_count > k) --count[s[l++] - 'A'];
            result = max(result, r - l + 1);
        }
        return result;
    }
};
