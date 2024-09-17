class Solution:

    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        freq1 = Counter(s1.split())
        freq2 = Counter(s2.split())
        result = []
        for w, cnt in freq1.items():
            if cnt == 1 and w not in freq2:
                result.append(w)
        for w, cnt in freq2.items():
            if cnt == 1 and w not in freq1:
                result.append(w)
        return result
