class Solution:

    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        directions = ((0, 1), (1, 0), (0, -1), (-1, 0))

        obs = set()
        for x, y in obstacles:
            obs.add((x, y))

        result = 0

        i, j = 0, 0
        d = 0
        for cmd in commands:
            if cmd == -2:
                d = (d + 4 - 1) % 4
            elif cmd == -1:
                d = (d + 1) % 4
            else:
                for _ in range(cmd):
                    ii, jj = i + directions[d][0], j + directions[d][1]
                    if (ii, jj) in obs:
                        break
                    i, j = ii, jj
            result = max(result, i * i + j * j)

        return result
