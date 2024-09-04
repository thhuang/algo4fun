class Solution:

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)

        mn, mx = min(freq.values()), max(freq.values())
        buckets = [[] for _ in range(mx - mn + 1)]
        for v, f in freq.items():
            buckets[f - mn].append(v)

        result = []
        for i in reversed(range(len(buckets))):
            for v in buckets[i]:
                result.append(v)
                if len(result) == k:
                    return result

        return result
