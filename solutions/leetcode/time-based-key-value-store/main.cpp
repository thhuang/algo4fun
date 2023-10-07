class TimeMap {
    // {key, {timestamp, value}}
    unordered_map<string, vector<pair<int, string>>> mp;

   public:
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        const vector<pair<int, string>>& tv = mp[key];
        auto it = upper_bound(tv.begin(), tv.end(), timestamp,
                              [](int t, const pair<int, string>& v) -> bool {
                                  return t < v.first;
                              });
        if (it == tv.begin()) return "";
        return prev(it)->second;
    }
};

class TimeMap {
    struct ValueTimestamp {
        string value;
        int timestamp;
    };

    unordered_map<string, vector<ValueTimestamp>> kvs;

   public:
    void set(string key, string value, int timestamp) {
        kvs[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        auto it = kvs.find(key);
        if (it == kvs.end()) return "";

        const auto& vs = it->second;
        int l = -1, r = vs.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (vs[m].timestamp <= timestamp) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l == -1) return "";
        return vs[l].value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
