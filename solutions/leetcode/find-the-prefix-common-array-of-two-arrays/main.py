class Solution:

    def findThePrefixCommonArray(self, A: List[int],
                                 B: List[int]) -> List[int]:
        freq = defaultdict(int)
        acc = 0
        result = []

        for i in range(len(A)):
            freq[A[i]] += 1
            if freq[A[i]] == 2:
                acc += 1
            freq[B[i]] += 1
            if freq[B[i]] == 2:
                acc += 1
            result.append(acc)

        return result
