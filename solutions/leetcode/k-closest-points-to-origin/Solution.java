class Solution {
    static private int dist2(int[] point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    static private int partition(List<int[]> points, int l, int r, int t) {
        Collections.swap(points, r, t);
        int p = l;
        int d2 = dist2(points.get(r));
        for (int i = l; i < r; ++i) {
            if (dist2(points.get(i)) <= d2) {
                Collections.swap(points, i, p++);
            }
        }
        Collections.swap(points, p, r);
        return p;
    }

    public int[][] kClosest(int[][] points, int k) {
        List<int[]> ps = Arrays.asList(points);

        int l = 0;
        int r = points.length;
        while (r - l > 1) {
            int t = l + (r - l) / 2;
            t = partition(ps, l, r - 1, t);
            if (t >= k) {
                r = t;
            } else {
                l = t;
            }
        }

        int[][] result = new int[k][];
        for (int i = 0; i < k; ++i) {
            result[i] = ps.get(i);
        }

        return result;
    }
}