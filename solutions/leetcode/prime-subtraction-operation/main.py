class Solution:

    def getPrimes(self, mx: int) -> List[int]:
        primes = [2]
        for i in range(3, mx + 1, 2):
            is_prime = True
            for p in primes:
                if p * p > i:
                    break
                if i % p == 0:
                    is_prime = False
                    break
            if is_prime:
                primes.append(i)
        return primes

    def primeSubOperation(self, nums: List[int]) -> bool:
        mx = max(nums)
        primes = self.getPrimes(mx)

        nums = [0] + nums
        for i in range(1, len(nums)):
            v = nums[i]
            for p in primes:
                if v - p <= nums[i - 1]:
                    break
                nums[i] = v - p
            if nums[i] <= nums[i - 1]:
                return False

        return True
