class Solution:

    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)

        vis = [False for _ in range(n)]

        def dfs(u: int) -> None:
            if vis[u]:
                return
            vis[u] = True
            for v in rooms[u]:
                dfs(v)

        dfs(0)

        return False not in vis
