from enum import Enum
from typing import List


class Solution:

    class State(Enum):
        Unknown = 1
        Safe = 2
        Unsafe = 3

    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        states = [self.State.Unknown] * n

        def dfs(u: int) -> self.State:
            if states[u] != self.State.Unknown:
                return states[u]

            states[u] = self.State.Unsafe
            is_safe = True

            for v in graph[u]:
                if dfs(v) != self.State.Safe:
                    is_safe = False

            if is_safe:
                states[u] = self.State.Safe

            return states[u]

        result = []
        for u in range(n):
            if dfs(u) == self.State.Safe:
                result.append(u)

        return result
