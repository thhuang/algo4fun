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


class Solution:

    def canArrange(self, arr: List[int], k: int) -> bool:
        freq = [0] * k

        for v in arr:
            freq[v % k] += 1

        if freq[0] % 2 != 0:
            return False

        for i in range(1, k // 2 + 1):
            if freq[i] != freq[k - i]:
                return False

        return True
