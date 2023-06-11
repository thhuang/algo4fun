class SnapshotArray {
    int id = 0;
    TreeMap<Integer, Integer>[] updates;

    public SnapshotArray(int length) {
        updates = new TreeMap[length];
        for (int i = 0; i < length; ++i) {
            updates[i] = new TreeMap<Integer, Integer>();
            updates[i].put(0, 0);
        }
    }

    public void set(int index, int val) {
        updates[index].put(id, val);
    }

    public int snap() {
        return id++;
    }

    public int get(int index, int snap_id) {
        return updates[index].floorEntry(snap_id).getValue();
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */
