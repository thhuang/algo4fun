class Solution {
   public:
    int digitsCount(int d, int low, int high) {
        function<int(int)> process = [&](int x) -> int {
            if (x <= 9) return d == 0 ? 0 : x >= d;

            // e.g. 876
            int result = 0;

            // 000 ~ 869
            result += x / 10;
            if (d == 0) --result;

            // 870 ~ 876
            if (x % 10 >= d) ++result;

            // 00X ~ 87X
            result += process(x / 10) * 10;

            // 877 ~ 879
            string s = to_string(x / 10);
            result -= count(s.begin(), s.end(), '0' + d) * (9 - x % 10);

            return result;
        };

        return process(high) - process(low - 1);
    }
};
