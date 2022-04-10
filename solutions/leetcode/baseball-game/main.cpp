class Solution {
   public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        for (string op : ops) {
            if (op == "C") {
                record.pop_back();
            } else if (op == "D") {
                record.push_back(record.back() * 2);
            } else if (op == "+") {
                int n = record.size();
                record.push_back(record[n - 1] + record[n - 2]);
            } else {
                record.push_back(stoi(op));
            }
        }
        return accumulate(record.begin(), record.end(), 0);
    }
};
