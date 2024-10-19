class Solution:

    def findKthBit(self, n: int, k: int) -> str:
        s = ["0"]
        for i in range(1, n):
            s = s + ["1"] + list(reversed(self.inverted(s)))
        return s[k - 1]

    def inverted(self, s: List[str]) -> List[str]:
        r = s.copy()
        for i in range(len(r)):
            if r[i] == "0":
                r[i] = "1"
            else:
                r[i] = "0"
        return r
