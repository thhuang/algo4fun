class Solution {
    const array<char, 16> mp = {'0', '1', '2', '3', '4', '5', '6', '7',
                                '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    const int mask = (1 << 4) - 1;

   public:
    string toHex(int num) {
        string rresult;
        for (int i = 0; i < 8; ++i) {
            rresult += mp[num & mask];
            num >>= 4;
        }
        while (rresult.size() > 1 && rresult.back() == '0') rresult.pop_back();
        return {rresult.rbegin(), rresult.rend()};
    }
};
