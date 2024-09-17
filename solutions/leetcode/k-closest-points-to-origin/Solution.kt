class Solution {
    private fun dist2(point: IntArray): Int {
        return point[0] * point[0] + point[1] * point[1]
    }

    fun kClosest(points: Array<IntArray>, k: Int): Array<IntArray> {

        val partition: (Int, Int, Int) -> Int = { l, r, t ->
            points[r] = points[t].also { points[t] = points[r] }
            var p = l
            val d = dist2(points[r])
            for (i in l until r) {
                if (dist2(points[i]) <= d) {
                    points[i] = points[p].also { points[p] = points[i] }
                    p += 1
                }
            }
            points[p] = points[r].also { points[r] = points[p] }
            p
        }

        // [l, r)
        var l = 0
        var r = points.size
        while (r - l > 1) {
            val m = l + (r - l) / 2
            val t = partition(l, r - 1, m)
            if (t >= k) {
                r = t
            } else {
                l = t
            }
        }

        return points.copyOfRange(0, k)
    }
}