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

            s = 0
            word_cnt = Counter(words[i])
            for k, v in word_cnt.items():
                if k not in cnt or cnt[k] < v:
                    return
                cnt[k] -= v
                s += v * score[ord(k) - ord("a")]

            curr += s
            dfs(i + 1)
            curr -= s

            for k, v in word_cnt.items():
                cnt[k] += v

        dfs(0)

        return result
