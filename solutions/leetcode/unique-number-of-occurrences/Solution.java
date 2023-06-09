class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        for (int v : arr) {
            freq.put(v, freq.getOrDefault(v, 0) + 1);
        }
        HashSet<Integer> seen = new HashSet<Integer>();
        for (Map.Entry<Integer, Integer> kv : freq.entrySet()) {
            int v = kv.getValue();
            if (seen.contains(v)) {
                return false;
            }
            seen.add(v);
        }
        return true;
    }
}
