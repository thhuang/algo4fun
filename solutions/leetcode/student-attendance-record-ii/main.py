class Solution:

    def checkRecord(self, n: int) -> int:
        mod = 1_000_000_007

        class DP:

            def __init__(self, l0a0, l1a0, l2a0, l0a1, l1a1, l2a1):
                self.l0a0 = l0a0
                self.l1a0 = l1a0
                self.l2a0 = l2a0
                self.l0a1 = l0a1
                self.l1a1 = l1a1
                self.l2a1 = l2a1

        dp = DP(1, 1, 0, 1, 0, 0)

        for _ in range(1, n):
            dp = DP(
                (dp.l0a0 + dp.l1a0 + dp.l2a0) % mod,
                dp.l0a0,
                dp.l1a0,
                dp.l0a0 + dp.l1a0 + dp.l2a0 + dp.l0a1 + dp.l1a1 + dp.l2a1,
                dp.l0a1,
                dp.l1a1,
            )

        return (dp.l0a0 + dp.l1a0 + dp.l2a0 + dp.l0a1 + dp.l1a1 + dp.l2a1) % mod
