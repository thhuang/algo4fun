class Solution:

    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        cnt = Counter(letters)

        result = 0
        curr = 0

        def dfs(i):
            nonlocal result
            nonlocal curr
            nonlocal cnt
            nonlocal score

            if i == len(words):
                result = max(result, curr)
                return

            dfs(i + 1)

            word_cnt = Counter(words[i])
            for k, v in word_cnt.items():
                if k not in cnt or cnt[k] < v:
                    return

            for k, v in word_cnt.items():
                cnt[k] -= v
                curr += v * score[ord(k) - ord("a")]

            dfs(i + 1)

            for k, v in word_cnt.items():
                cnt[k] += v
                curr -= v * score[ord(k) - ord("a")]

        dfs(0)

        return result
