class Solution:

    def commonChars(self, words: List[str]) -> List[str]:
        max_len = max([len(w) for w in words])
        char_max_cnt = [max_len] * 26
        for w in words:
            freq = Counter(w)
            for i in range(26):
                char_max_cnt[i] = min(char_max_cnt[i], freq.get(chr(ord("a") + i), 0))

        result = []
        for i, cnt in enumerate(char_max_cnt):
            result += [chr(ord("a") + i)] * cnt

        return result
