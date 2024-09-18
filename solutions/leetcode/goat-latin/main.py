class Solution:

    def toGoatLatin(self, sentence: str) -> str:
        vowels = {"a", "e", "i", "o", "u", "A", "E", "I", "O", "U"}

        words = []

        for i, w in enumerate(sentence.split()):
            word = []

            if w[0] in vowels:
                word.append(w)
            else:
                word.append(w[1:])
                word.append(w[0])

            word.append("ma")
            for _ in range(i + 1):
                word.append("a")

            words.append(word)

        return " ".join(["".join(word) for word in words])
