class Solution:

    def validIPAddress(self, queryIP: str) -> str:
        if self.validIPv4(queryIP):
            return "IPv4"
        if self.validIPv6(queryIP):
            return "IPv6"
        return "Neither"

    def validIPv4(self, queryIP: str) -> bool:
        nums = queryIP.split(".")
        if len(nums) != 4:
            return False
        for num in nums:
            if not self.validIPv4Number(num):
                return False
        return True

    def validIPv6(self, queryIP: str) -> bool:
        nums = queryIP.split(":")
        if len(nums) != 8:
            return False
        for num in nums:
            if not self.validIPv6Number(num):
                return False
        return True

    def validIPv4Number(self, num: str) -> bool:
        if len(num) > 3:
            return False
        if re.search("^\d{1,3}$", num) is None:
            return False
        v = int(num)
        return 0 <= v <= 255 and str(v) == num

    def validIPv6Number(self, num: str) -> bool:
        if len(num) > 4:
            return False
        if re.search("^[\d(a-f)(A-F)]+$", num) is None:
            return False
        return True
