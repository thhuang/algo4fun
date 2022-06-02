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

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
