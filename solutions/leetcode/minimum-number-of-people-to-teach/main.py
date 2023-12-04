class Solution:

    def minimumTeachings(self, n: int, languages: List[List[int]],
                         friendships: List[List[int]]) -> int:
        lang_require = [set() for _ in range(n)]

        for f in friendships:
            u, v = f[0] - 1, f[1] - 1
            ulang, vlang = set(languages[u]), set(languages[v])

            interlang = ulang & vlang
            if len(interlang) > 0:
                continue

            for lang in range(1, n + 1):
                if lang not in ulang:
                    lang_require[lang - 1].add(u)
                if lang not in vlang:
                    lang_require[lang - 1].add(v)

        result = len(languages)
        for users in lang_require:
            result = min(result, len(users))

        return result
