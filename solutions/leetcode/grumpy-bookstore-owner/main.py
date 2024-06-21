class Solution:

    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)
        normal_suffix_sum = [0] * (n + 1)
        secret_suffix_sum = [0] * (n + 1)

        for i in reversed(range(n)):
            normal_suffix_sum[i] = normal_suffix_sum[i + 1] + (customers[i] if grumpy[i] == 0 else 0)
            secret_suffix_sum[i] = secret_suffix_sum[i + 1] + customers[i]

        result = 0
        for i in range(n):
            normal = normal_suffix_sum[0] - normal_suffix_sum[i] + (normal_suffix_sum[i + minutes] if i +
                                                                    minutes < n else 0)
            secret = secret_suffix_sum[i] - (secret_suffix_sum[i + minutes] if i + minutes < n else 0)
            result = max(result, normal + secret)

        return result
