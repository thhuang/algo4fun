class Solution {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                  'A', 'E', 'I', 'O', 'U'};

   public:
    string sortVowels(string s) {
        vector<int> vowelIndices;
        vector<char> vowelChars;

        for (int i = 0; i < s.size(); ++i) {
            if (vowels.count(s[i]) > 0) {
                vowelChars.push_back(s[i]);
                vowelIndices.push_back(i);
            }
        }

        sort(vowelChars.begin(), vowelChars.end());

        for (int i = 0; i < vowelIndices.size(); ++i) {
            s[vowelIndices[i]] = vowelChars[i];
        }

        return s;
    }
};
