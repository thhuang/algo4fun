class Solution:

    def countTriplets(self, arr: List[int]) -> int:
        prefix_cnt = defaultdict(int)
        prefix_idx_sum = defaultdict(int)

        prefix_cnt[0] = 1

        result = 0
        xor = 0

        for i in range(len(arr)):
            xor = xor ^ arr[i]

            result += prefix_cnt[xor] * i - prefix_idx_sum[xor]

            prefix_cnt[xor] += 1
            prefix_idx_sum[xor] += i + 1

        return result
