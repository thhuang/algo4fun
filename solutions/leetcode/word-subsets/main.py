class Solution:

    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        words_char_freq_1 = [Counter(list(w)) for w in words1]

        f2 = Counter(words2[0])
        for w in words2:
            for k, v in Counter(w).items():
                f2[k] = max(f2.get(k, 0), v)

        result = []
        for i in range(len(words1)):
            is_subset = True
            f1 = words_char_freq_1[i]
            for k, v in f2.items():
                if f1.get(k, 0) < v:
                    is_subset = False
                    break
            if is_subset:
                result.append(words1[i])

        return result
