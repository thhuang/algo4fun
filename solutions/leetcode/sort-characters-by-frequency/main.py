class Solution:

    def frequencySort(self, s: str) -> str:
        freq = Counter(s)
        inv_freq = sorted([(-f, c) for c, f in freq.items()])
        chars = [c for neg_f, c in inv_freq for _ in range(-neg_f)]
        return "".join(chars)
