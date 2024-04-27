class Solution:

    def findRotateSteps(self, ring: str, key: str) -> int:
        q = deque([(0, 0)])
        vis = set()
        step = 0

        while len(q) > 0:
            n = len(q)

            for _ in range(n):
                i, j = q.popleft()
                if (i, j) in vis:
                    continue
                vis.add((i, j))

                if ring[i] == key[j]:
                    if j + 1 == len(key):
                        return step + 1
                    q.append((i, j + 1))

                q.append(((i - 1 + len(ring)) % len(ring), j))
                q.append(((i + 1) % len(ring), j))

            step += 1

        return -1
