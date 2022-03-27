class Solution {
   public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> result;
        int max_points = 0;
        vector<int> curr_arrows;
        int curr_points = 0;
        int arrows = numArrows;
        function<void(int)> search = [&](int i) -> void {
            if (arrows < 0) return;
            if (i == size(aliceArrows)) {
                if (curr_points > max_points)
                    result = curr_arrows, max_points = curr_points;
                return;
            }

            curr_arrows.push_back(0);
            search(i + 1);
            curr_arrows.pop_back();

            int needs = aliceArrows[i] + 1;
            arrows -= needs;
            curr_points += i;
            curr_arrows.push_back(needs);
            search(i + 1);
            arrows += needs;
            curr_points -= i;
            curr_arrows.pop_back();
        };

        search(0);

        int sum = 0;
        for (int v : result) sum += v;
        result[0] = numArrows - sum;

        return result;
    }
};
