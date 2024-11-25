class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        directions = (
            (1, 3),
            (0, 2, 4),
            (1, 5),
            (0, 4),
            (1, 3, 5),
            (2, 4),
        )

        def swap(u: str, i: int, j: int) -> str:
            state = list(u)
            state[i], state[j] = state[j], state[i]
            return "".join(state)

        q = deque()
        q.append((0, "".join([str(v) for v in board[0] + board[1]])))

        visited = set()

        while len(q) > 0:
            moves, u = q.popleft()

            if u == "123450":
                return moves

            if u in visited:
                continue
            visited.add(u)

            i = u.find("0")
            for j in directions[i]:
                q.append((moves + 1, swap(u, i, j)))

        return -1
