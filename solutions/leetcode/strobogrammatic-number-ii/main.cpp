class Solution {
    array<string, 5> side = {"00", "11", "69", "88", "96"};
    array<char, 3> mid = {'0', '1', '8'};

   public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> result;

        deque<char> dq;
        function<void(int)> search = [&](int i) -> void {
            if (i == n) {
                string s = {dq.begin(), dq.end()};
                if (s.size() == 1 || s[0] != '0') {
                    result.push_back(s);
                }
                return;
            }

            for (string t : side) {
                dq.push_front(t.front());
                dq.push_back(t.back());
                search(i + 2);
                dq.pop_front();
                dq.pop_back();
            }
        };

        if (n % 2 == 0) {
            search(0);
        } else {
            for (char c : mid) {
                dq.push_back(c);
                search(1);
                dq.pop_back();
            }
        }

        return result;
    }
};
