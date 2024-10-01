class Solution:

    def canArrange(self, arr: List[int], k: int) -> bool:
        n = len(arr) // 2

        mp = defaultdict(int)

        for v in arr:
            t = (k - v % k) % k
            if mp[t] > 0:
                mp[t] -= 1
                n -= 1
            else:
                mp[v % k] += 1

        return n == 0
