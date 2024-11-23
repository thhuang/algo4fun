class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m = len(box)
        n = len(box[0])

        result = [[box[i][j] for i in reversed(range(m))] for j in range(n)]

        for j in range(m):
            p = n - 1

            for i in reversed(range(n)):
                if result[i][j] == "*":
                    p = i - 1
                elif result[i][j] == "#":
                    result[p][j] = "x"
                    p -= 1

            for i in range(n):
                if result[i][j] == "x":
                    result[i][j] = "#"
                elif result[i][j] != "*":
                    result[i][j] = "."

        return result
