class Solution:

    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        result = []

        for i in range(1, len(currentState)):
            if currentState[i - 1:i + 1] == "++":
                result.append(currentState[:i - 1] + "--" +
                              currentState[i + 1:])

        return result
