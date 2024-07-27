class Solution:

    def minKBitFlips(self, nums: List[int], k: int) -> int:
        sign = deque([False] * k)
        flip_sign = True
        result = 0
        for i, v in enumerate(nums):
            flipped = sign.popleft() == flip_sign
            should_flip = v == 0
            if (should_flip and not flipped) or (not should_flip and flipped):
                if i + k > len(nums):
                    return -1
                flip_sign = not flip_sign
                result += 1
            sign.append(not flip_sign)
        return result
