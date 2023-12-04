class Encrypter:

    def __init__(self, keys: List[str], values: List[str],
                 dictionary: List[str]):
        self.keys = keys
        self.values = values

        self.key_to_index = {}
        for i, k in enumerate(keys):
            self.key_to_index[k] = i

        self.encrypt_freq = defaultdict(int)
        for w in dictionary:
            found = True
            enc = ""
            for c in w:
                if c not in self.key_to_index:
                    found = False
                    break
                enc += values[self.key_to_index[c]]
            if found:
                self.encrypt_freq[enc] += 1

    def encrypt(self, word1: str) -> str:
        enc = ""
        for c in word1:
            if c not in self.key_to_index:
                return ""
            enc += self.values[self.key_to_index[c]]
        return enc

    def decrypt(self, word2: str) -> int:
        return self.encrypt_freq[word2]


# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)
