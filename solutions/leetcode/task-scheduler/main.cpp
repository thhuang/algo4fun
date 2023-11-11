class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskFreq;
        for (char t : tasks) {
            ++taskFreq[t];
        }

        struct FreqTask {
            int freq;
            char task;
        };
        vector<FreqTask> freqTasks;

        unordered_map<char, int> lastScheduledTime;

        for (auto [t, f] : taskFreq) {
            freqTasks.push_back({f, t});
            lastScheduledTime[t] = -n - 1;
        }
        sort(freqTasks.begin(), freqTasks.end(),
             [](FreqTask a, FreqTask b) -> bool { return a.freq > b.freq; });

        int time = 0;
        while (freqTasks.front().freq > 0) {
            for (auto& [f, t] : freqTasks) {
                if (lastScheduledTime[t] + n >= time) continue;
                if (f == 0) break;
                --f;
                lastScheduledTime[t] = time;
                break;
            }
            sort(
                freqTasks.begin(), freqTasks.end(),
                [](FreqTask a, FreqTask b) -> bool { return a.freq > b.freq; });
            ++time;
        }

        return time;
    }
};
