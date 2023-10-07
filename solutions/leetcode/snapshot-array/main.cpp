class SnapshotArray {
    vector<vector<pair<int, int>>> updates;
    int id = 0;

   public:
    SnapshotArray(int length) { updates.resize(length, {{0, 0}}); }

    void set(int index, int val) {
        if (updates[index].back().first == id) {
            updates[index].pop_back();
        }
        updates[index].push_back({id, val});
    }

    int snap() { return id++; }

    int get(int index, int snap_id) {
        auto& records = updates[index];
        auto it = --upper_bound(
            records.begin(), records.end(), snap_id,
            [](int t, pair<int, int> v) -> bool { return t < v.first; });
        return it->second;
    }
};

class SnapshotArray {
    struct History {
        int value;
        int id;
    };

    int length;
    vector<vector<History>> data;
    int id = 0;

   public:
    SnapshotArray(int length) : length(length), data(length, {{0, 0}}) {}

    void set(int index, int val) {
        vector<History>& history = data[index];
        if (history.back().id == id) {
            history.back().value = val;
        } else {
            history.push_back({val, id});
        }
    }

    int snap() { return id++; }

    int get(int index, int snap_id) {
        const vector<History>& history = data[index];
        auto it = upper_bound(
            history.begin(), history.end(), snap_id,
            [](int t, const History& e) -> bool { return t < e.id; });
        return prev(it)->value;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
