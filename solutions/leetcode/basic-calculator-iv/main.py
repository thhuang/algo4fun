class Solution:

    def basicCalculatorIV(self, s: str, evalvars: List[str], evalints: List[int]) -> List[str]:

        mp = {k: v for k, v in zip(evalvars, evalints)}

        p = 0

        def getOrder(k):
            if k == "":
                return 0
            return len(k.split("*"))

        def add(a, b):
            result = defaultdict(int)
            for k, v in a.items():
                result[k] += v
            for k, v in b.items():
                result[k] += v
                if result[k] == 0:
                    del result[k]
            return result

        def mul(a, b):
            result = defaultdict(int)
            for ka, va in a.items():
                for kb, vb in b.items():
                    variables = sorted(ka.split("*") + kb.split("*"))[::-1]
                    while len(variables) > 0 and variables[-1] == "":
                        variables.pop()
                    k = "*".join(variables[::-1])
                    v = va * vb
                    result[k] += v
            return result

        def getNumber():
            nonlocal p
            v = 0
            while p < len(s) and s[p].isdigit():
                v = v * 10 + int(s[p])
                p += 1
            p -= 1
            return {"": v}

        def getVariable():
            nonlocal p
            l = []
            while p < len(s) and s[p].isalpha():
                l.append(s[p])
                p += 1
            p -= 1
            k = "".join(l)
            if k in mp:
                return {"": mp[k]}
            return {k: 1}

        def process():
            nonlocal p

            total = {}
            last = {}
            sign = {"": 1}
            op = "+"

            while p < len(s) and s[p] != ")":
                if s[p] in {"+", "-", "*"}:
                    op = s[p]

                elif s[p] != " ":
                    if s[p].isdigit():
                        v = getNumber()
                    elif s[p].isalpha():
                        v = getVariable()
                    elif s[p] == "(":
                        p += 1
                        v = process()

                    if op == "+":
                        total = add(total, mul(sign, last))
                        sign = {"": 1}
                        last = v
                    elif op == "-":
                        total = add(total, mul(sign, last))
                        sign = {"": -1}
                        last = v
                    elif op == "*":
                        last = mul(last, v)

                p += 1

            return add(total, mul(sign, last))

        return [(f"{v}*{k}" if k != "" else f"{v}")
                for k, v in sorted(process().items(), key=lambda kv: (-getOrder(kv[0]), kv[0]))]
