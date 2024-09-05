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
                for _ in range(cnt):
                    result += cs

            return i + 1, result

        _, cs = decode(0)
        return "".join(cs)


class Solution:

    def decodeString(self, s: str) -> str:
        n = len(s)
        p = 0

        def getNumber():
            nonlocal p
            v = 0
            while p < n and s[p] != "[":
                v = v * 10 + int(s[p])
                p += 1
            return v

        def decode():
            nonlocal p

            result = []

            while p < n and s[p] != "]":
                if s[p].isdigit():
                    v = getNumber()
                    p += 1
                    t = decode()
                    for _ in range(v):
                        for c in t:
                            result.append(c)

                else:
                    result.append(s[p])

                p += 1

            return result

        return "".join(decode())
