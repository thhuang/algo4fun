class Solution:

    def minRemoveToMakeValid(self, s: str) -> str:
        should_remove = set()
        stack = []
        for i, c in enumerate(s):
            if c == "(":
                stack.append(i)
            elif c == ")":
                if len(stack) == 0:
                    should_remove.add(i)
                else:
                    stack.pop()

        for i in stack:
            should_remove.add(i)

        result = []
        for i, c in enumerate(s):
            if i not in should_remove:
                result.append(c)

        return "".join(result)
