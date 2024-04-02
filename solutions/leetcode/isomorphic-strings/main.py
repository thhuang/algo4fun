class Solution:

    def isIsomorphic(self, s: str, t: str) -> bool:
        mapped = set()
        mp = dict()
        for i, c in enumerate(s):
            if c in mp:
                if mp[c] != t[i]:
                    return False
                continue
            if t[i] in mapped:
                return False
            mp[c] = t[i]
            mapped.add(t[i])
        return True
