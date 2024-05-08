class Solution:

    def wonderfulSubstrings(self, word: str) -> int:
        freq = {0: 1}

        result = 0

        mask = 0
        for c in word:
            shift = ord(c) - ord("a")
            mask ^= (1 << shift)

            if mask in freq:
                result += freq[mask]
                freq[mask] += 1
            else:
                freq[mask] = 1

            for i in range(10):
                v = mask ^ (1 << i)
                if v in freq:
                    result += freq[v]

        return result


class Solution:

    def wonderfulSubstrings(self, word: str) -> int:
        freq = defaultdict(int)
        freq[0] = 1

        result = 0

        mask = 0
        for c in word:
            shift = ord(c) - ord("a")
            mask ^= (1 << shift)

            result += freq[mask]
            freq[mask] += 1

            for i in range(10):
                result += freq[mask ^ (1 << i)]

        return result
