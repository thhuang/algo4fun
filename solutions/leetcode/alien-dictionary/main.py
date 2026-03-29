class Solution:

    def alienOrder(self, words: List[str]) -> str:
        adj = defaultdict(list)

        for i in range(len(words) - 1):
            a, b = words[i], words[i + 1]

            if len(a) > len(b) and b == a[:len(b)]:
                return ""

            for u, v in zip(a, b):
                if u != v:
                    adj[u].append(v)
                    break

        # 0: unprocessed
        # 1: processing
        # 2: processed
        status = defaultdict(lambda: 0)

        rresult = []

        def dfs(u: int) -> bool:
            if status[u] == 1:
                return False
            if status[u] == 2:
                return True

            status[u] = 1

            for v in adj[u]:
                if not dfs(v):
                    return False

            rresult.append(u)
            status[u] = 2
            return True

        for c in "".join(words):
            if not dfs(c):
                return ""

        return "".join(rresult)[::-1]
