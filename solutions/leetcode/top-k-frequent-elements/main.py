class Solution:

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return [k for k, _ in Counter(nums).most_common(k)]


class Solution:

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        sorted_freq = sorted(freq.items(), key=lambda v: -v[1])
        return [v[0] for v in sorted_freq[:k]]


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
