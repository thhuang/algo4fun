class Solution {
   public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0, n; i < data.size(); i += n) {
            if ((data[i] >> 7) == 0)
                n = 1;
            else if ((data[i] >> 5) == 0b110)
                n = 2;
            else if ((data[i] >> 4) == 0b1110)
                n = 3;
            else if ((data[i] >> 3) == 0b11110)
                n = 4;
            else
                return false;

            if (i + n > data.size()) return false;

            for (int j = i + 1; j < i + n; ++j) {
                if ((data[j] >> 6) != 0b10) return false;
            }
        }

        return true;
    }
};
