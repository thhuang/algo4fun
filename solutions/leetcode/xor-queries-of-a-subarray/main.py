class Solution:

    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        suffix_xor = [0] * (n + 1)
        for i in reversed(range(n)):
            suffix_xor[i] = arr[i] ^ suffix_xor[i + 1]
        result = []
        for l, r in queries:
            result.append(suffix_xor[l] ^ suffix_xor[r + 1])
        return result
