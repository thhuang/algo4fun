class Solution:

    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed_chars = set(allowed)

        def isConsistent(word: str) -> bool:
            for c in word:
                if c not in allowed_chars:
                    return False
            return True

        result = 0
        for w in words:
            if isConsistent(w):
                result += 1

        return result
