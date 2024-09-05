class Solution:

    def simplifyPath(self, path: str) -> str:
        p = path.split("/")
        result = [""]
        for d in p:
            if d == "." or d == "":
                continue
            elif d == "..":
                if len(result) > 1:
                    result.pop()
            else:
                result.append(d)
        if len(result) == 1:
            return "/"
        return "/".join(result)
