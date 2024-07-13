class Solution:

    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        pdhi = sorted([(positions[i], directions[i], healths[i], i) for i in range(len(positions))])

        robots = []
        for _, d, h, i in pdhi:
            while d == "L" and h > 0 and len(robots) > 0 and robots[-1][0] == "R":
                dd, hh, ii = robots.pop()
                if hh < h:
                    h -= 1
                elif hh > h:
                    hh -= 1
                    h = 0
                    robots.append((dd, hh, ii))
                else:
                    h = 0
            if h > 0:
                robots.append((d, h, i))

        robots.sort(key=lambda r: r[2])

        return [h for _, h, _ in robots]
