class Solution:

    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        l, r = 0, len(people) - 1

        result = 0
        while r - l >= 1:
            if people[l] + people[r] <= limit:
                l += 1
            r -= 1
            result += 1

        if l == r:
            result += 1

        return result
