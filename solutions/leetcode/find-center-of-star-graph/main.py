class Solution:

    def findCenter(self, edges: List[List[int]]) -> int:
        return edges[1][0] if edges[1][0] in set(edges[0]) else edges[1][1]
