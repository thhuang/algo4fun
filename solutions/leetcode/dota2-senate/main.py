from collections import deque


class Solution:

    def predictPartyVictory(self, senate: str) -> str:
        radiant = 0
        dire = 0
        q = deque()
        for c in senate:
            if c == 'R':
                radiant += 1
            else:  # c == 'D'
                dire += 1
            q.append(c)

        r = 0
        d = 0
        while radiant > 0 and dire > 0:
            c = q.popleft()
            if c == 'R':
                if r < 0:
                    r += 1
                    radiant -= 1
                else:
                    d -= 1
                    q.append('R')
            else:  # c == 'D'
                if d < 0:
                    d += 1
                    dire -= 1
                else:
                    r -= 1
                    q.append('D')

        return 'Radiant' if radiant > 0 else 'Dire'
