class SORTracker {
    struct lcmp {
        bool operator()(const pair<string, int>& a,
                        const pair<string, int>& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        }
    };

    struct rcmp {
        bool operator()(const pair<string, int>& b,
                        const pair<string, int>& a) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        }
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, lcmp> left;
    priority_queue<pair<string, int>, vector<pair<string, int>>, rcmp> right;

   public:
    void add(string name, int score) {
        if (!left.empty() &&
            (score > left.top().second ||
             (score == left.top().second && name < left.top().first))) {
            right.push(left.top());
            left.pop();
            left.push({name, score});
        } else {
            right.push({name, score});
        }
    }

    string get() {
        string result = right.top().first;
        left.push(right.top());
        right.pop();
        return result;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
