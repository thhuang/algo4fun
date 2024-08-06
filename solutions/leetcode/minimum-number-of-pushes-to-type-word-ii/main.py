class Solution:

    def minimumPushes(self, word: str) -> int:
        inv_freq = sorted([(v, k) for k, v in Counter(word).items()], reverse=True)
        result = 0
        for i, (cnt, ch) in enumerate(inv_freq):
            result += cnt * ((i // 8) + 1)
        return result
