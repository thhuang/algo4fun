class Solution:

    def compareVersion(self, version1: str, version2: str) -> int:
        ver1 = [int(v) for v in version1.split(".")]
        ver2 = [int(v) for v in version2.split(".")]
        for i in range(max(len(ver1), len(ver2))):
            v1 = ver1[i] if i < len(ver1) else 0
            v2 = ver2[i] if i < len(ver2) else 0
            if v1 > v2:
                return 1
            elif v1 < v2:
                return -1
        return 0
