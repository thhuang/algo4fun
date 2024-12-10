class Solution:
    def maximumLength(self, s: str) -> int:
        result = 0

        for length in range(1, len(s) + 1):
            freq = defaultdict(int)
            for l in range(len(s) - length + 1):
                t = s[l : l + length]
                if len(set([c for c in t])) > 1:
                    continue
                freq[t] += 1
            if len(freq) > 0 and max(freq.values()) >= 3:
                result = length

        if result == 0:
            return -1
        return result


class Solution:
    def maximumLength(self, s: str) -> int:
        result = 0

        for length in range(1, len(s) + 1):
            freq = defaultdict(int)

            window = defaultdict(int)

            for r in range(length - 1):
                window[s[r]] += 1

            for r in range(length - 1, len(s)):
                l = r - length + 1
                window[s[r]] += 1
                if window[s[r]] == length:
                    freq[s[r]] += 1
                window[s[l]] -= 1

            if len(freq) > 0 and max(freq.values()) >= 3:
                result = length

        if result == 0:
            return -1
        return result
