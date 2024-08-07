class Solution:

    def __init__(self):
        self.digit_map = ("Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine")
        self.teen_map = ("Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                         "Eighteen", "Nineteen")
        self.ten_map = ("", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety")

    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"

        words = []

        self.convert(words, num // 1_000_000_000_000, "Trillion")
        self.convert(words, num // 1_000_000_000 % 1000, "Billion")
        self.convert(words, num // 1_000_000 % 1000, "Million")
        self.convert(words, num // 1000 % 1000, "Thousand")
        self.convert(words, num % 1000)

        return " ".join(words)

    def convert(self, words: List[str], v: int, magnitude: Optional[str] = None):
        if v == 0:
            return

        hundred = v // 100
        if hundred > 0:
            words.append(self.digit_map[hundred])
            words.append("Hundred")

        remain = v % 100
        if remain >= 20:
            words.append(self.ten_map[remain // 10])
            if remain % 10 > 0:
                words.append(self.digit_map[remain % 10])
        elif remain >= 10:
            words.append(self.teen_map[remain % 10])
        elif remain > 0:
            words.append(self.digit_map[remain])

        if magnitude is not None:
            words.append(magnitude)
