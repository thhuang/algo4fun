class Solution:

    def countCharacters(self, words: List[str], chars: str) -> int:
        result = 0

        target = Counter(chars)
        for w in words:
            cnt = Counter(w)
            if cnt < target:
                result += len(w)

        return result
