class Solution:

    def countOfAtoms(self, formula: str) -> str:
        p = 0

        def getNumber():
            nonlocal p
            v = 1
            if p < len(formula) and formula[p].isdigit():
                v = 0
                while p < len(formula) and formula[p].isdigit():
                    v = v * 10 + int(formula[p])
                    p += 1
            return v

        def process():
            nonlocal p

            freq = defaultdict(int)

            while p < len(formula) and formula[p] != ")":

                if formula[p] == "(":

                    p += 1
                    f = process()
                    p += 1
                    num = getNumber()
                    for k, v in f.items():
                        freq[k] += v * num

                else:

                    k = formula[p]
                    p += 1
                    if p < len(formula) and formula[p].islower():
                        k = formula[p - 1:p + 1]
                        p += 1

                    freq[k] += getNumber()

            return freq

        return "".join([f"{k}{'' if v == 1 else str(v)}" for k, v in sorted(process().items())])
