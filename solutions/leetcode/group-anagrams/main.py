from collections import defaultdict


class Solution:

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        group = defaultdict(lambda: [])
        for s in strs:
            group["".join(sorted(s))].append(s)
        return [g for g in group.values()]
