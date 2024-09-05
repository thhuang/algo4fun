class Solution:

    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        result = [0] * n

        stack = []
        t0 = 0
        curr_i = None

        for log in logs:
            i, op, t1 = log.split(":")
            i = int(i)
            t1 = int(t1)

            if op == "start":
                stack.append(i)
            else:  # op == "end"
                stack.pop()
                t1 += 1

            if curr_i is not None:
                result[curr_i] += t1 - t0

            if len(stack) > 0:
                curr_i = stack[-1]
            else:
                curr_i = None

            t0 = t1

        return result
