class Solution {
    array<string, 5> side = {"00", "11", "69", "88", "96"};
    array<char, 3> mid = {'0', '1', '8'};

   public:
    int strobogrammaticInRange(string low, string high) {
        int m = low.size();
        int n = high.size();

        long long l = stoll(low);
        long long r = stoll(high);

        int result = 0;

        deque<char> dq;
        function<void(int)> search = [&](int i) -> void {
            if (m <= i && i <= n) {
                string s = {dq.begin(), dq.end()};
                long long v = stoll(s);
                if (s == to_string(v) && l <= v && v <= r) {
                    ++result;
                }
            }
            if (i >= n) return;

            for (string t : side) {
                dq.push_front(t.front());
                dq.push_back(t.back());
                search(i + 2);
                dq.pop_back();
                dq.pop_front();
            }
        };

        search(0);
        for (char c : mid) {
            dq.push_back(c);
            search(1);
            dq.pop_back();
        }

        return result;
    }
};
