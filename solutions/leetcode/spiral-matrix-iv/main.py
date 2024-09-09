# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        directions = ((0, 1), (1, 0), (0, -1), (-1, 0))

        result = [[-1 for _ in range(n)] for _ in range(m)]

        p = head
        i, j = 0, 0
        d = 0

        while p is not None and result[i][j] == -1:
            result[i][j] = p.val
            p = p.next

            ii, jj = i + directions[d][0], j + directions[d][1]
            if not (0 <= ii < m and 0 <= jj < n and result[ii][jj] == -1):
                d = (d + 1) % 4
                ii, jj = i + directions[d][0], j + directions[d][1]

            i, j = ii, jj

        return result
