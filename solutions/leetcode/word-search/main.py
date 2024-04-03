class Solution:

    def exist(self, board: List[List[str]], word: str) -> bool:
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))

        m = len(board)
        n = len(board[0])

        vis = [[False] * n for _ in range(m)]

        def dfs(i, j, k):
            if i < 0 or m <= i or j < 0 or n <= j or vis[i][j]:
                return False
            if board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True

            result = False
            vis[i][j] = True

            for di, dj in directions:
                result = result or dfs(i + di, j + dj, k + 1)

            vis[i][j] = False
            return result

        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True

        return False
