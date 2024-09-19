class Solution:

    def diffWaysToCompute(self, expression: str) -> List[int]:

        operation = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "*": lambda a, b: a * b,
        }

        nums = []
        ops = []

        i = 0
        while i < len(expression):
            if expression[i].isdigit():
                v = 0
                while i < len(expression) and expression[i].isdigit():
                    v = v * 10 + int(expression[i])
                    i += 1
                nums.append(v)
            else:
                ops.append(expression[i])
                i += 1

        @cache
        def dfs(l, r):
            if l == r:
                return [nums[l]]

            result = []

            for i in range(l, r):
                for a in dfs(l, i):
                    for b in dfs(i + 1, r):
                        result.append(operation[ops[i]](a, b))

            return result

        return dfs(0, len(nums) - 1)
