class Solution:

    def openLock(self, deadends: List[str], target: str) -> int:
        invalid = set(deadends)

        q = deque(["0000"])
        step = 0

        while len(q) > 0:
            n = len(q)

            for _ in range(n):
                u = q.popleft()

                if u in invalid:
                    continue
                if u == target:
                    return step

                invalid.add(u)

                for i in range(4):
                    v = ord(u[i]) - ord("0")

                    q.append(u[:i] + chr((v + 1) % 10 + ord("0")) + u[i + 1:])
                    q.append(u[:i] + chr((v + 9) % 10 + ord("0")) + u[i + 1:])

            step += 1

        return -1
