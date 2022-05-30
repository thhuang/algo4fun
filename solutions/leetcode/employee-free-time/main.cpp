/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
    class EmployeeSchedule {
        int i = 0;
        vector<Interval>* data;

       public:
        EmployeeSchedule(vector<Interval>* intervals) : data(intervals) {}

        void next() { ++i; };

        bool empty() { return i / 2 >= data->size(); }

        array<int, 2> curr() {
            const auto& in = data->at(i / 2);
            if (i & 1) return {in.end, 1};
            return {in.start, -1};
        }
    };

   public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int n = schedule.size();

        auto comp = [&](EmployeeSchedule& a, EmployeeSchedule& b) -> bool {
            return a.curr()[0] > b.curr()[0];
        };

        priority_queue<EmployeeSchedule, vector<EmployeeSchedule>, decltype(comp)> pq(comp);
        for (auto& s : schedule) pq.push(EmployeeSchedule(&s));

        int free = n;
        vector<Interval> result;
        Interval interval;
        while (!pq.empty()) {
            auto es = pq.top();
            pq.pop();

            auto [t, d] = es.curr();
            free += d;

            if (d == 1 && free == n) {
                interval.start = t;
            } else if (d == -1 && free == n - 1) {
                interval.end = t;
                if (interval.start != interval.end) result.push_back(interval);
            }

            es.next();
            if (!es.empty()) pq.push(es);
        }

        return {result.begin() + 1, result.end()};
    }
};
