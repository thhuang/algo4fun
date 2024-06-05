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


class Solution:

    def commonChars(self, words: List[str]) -> List[str]:
        result = []
        for c in [chr(i + ord("a")) for i in range(26)]:
            result += [c] * min([w.count(c) for w in words])
        return result


class Solution:

    def commonChars(self, words: List[str]) -> List[str]:
        return [c for c in [chr(i + ord("a")) for i in range(26)] for _ in range(min([w.count(c) for w in words]))]
