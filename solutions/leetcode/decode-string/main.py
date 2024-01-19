class Solution:

    def decodeString(self, s: str) -> str:
        chars = [c for c in s]

        def decode(i):
            nonlocal chars

            result = []

            while i < len(chars) and chars[i] != ']':
                if chars[i].isalpha():
                    result.append(chars[i])
                    i += 1
                    continue

                cnt = 0
                while chars[i].isdigit():
                    cnt = cnt * 10 + (ord(chars[i]) - ord('0'))
                    i += 1
                i, cs = decode(i + 1)
                for k in range(cnt):
                    result += cs

            return i + 1, result

        _, cs = decode(0)
        return "".join(cs)
