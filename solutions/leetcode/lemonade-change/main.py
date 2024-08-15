class Solution:

    def lemonadeChange(self, bills: List[int]) -> bool:
        five, ten, twenty = 0, 0, 0
        for v in bills:
            if v == 5:
                five += 1
            elif v == 10:
                ten += 1
                if five > 0:
                    five -= 1
                else:
                    return False
            elif v == 20:
                twenty += 1
                if ten > 0 and five > 0:
                    ten -= 1
                    five -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False
        return True
