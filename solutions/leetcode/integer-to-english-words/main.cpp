class Solution {
    unordered_map<int, string> digit2eng = {
        {1, "One"}, {2, "Two"},   {3, "Three"}, {4, "Four"}, {5, "Five"},
        {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
    unordered_map<int, string> teen2eng = {
        {10, "Ten"},      {11, "Eleven"},  {12, "Twelve"},  {13, "Thirteen"},
        {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
        {18, "Eighteen"}, {19, "Nineteen"}};
    unordered_map<int, string> ten2eng = {
        {2, "Twenty"}, {3, "Thirty"},  {4, "Forty"},  {5, "Fifty"},
        {6, "Sixty"},  {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};

    void convert(vector<string>& words, int v) {
        int hundred = v / 100;
        if (hundred) {
            words.push_back(digit2eng[hundred]);
            words.push_back("Hundred");
        }

        v %= 100;
        if (v >= 20) {
            words.push_back(ten2eng[v / 10]);
            if (v % 10) words.push_back(digit2eng[v % 10]);
        } else if (v >= 10) {
            words.push_back(teen2eng[v]);
        } else if (v > 0) {
            words.push_back(digit2eng[v]);
        }
    };

   public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        int one = num % 1000;
        num /= 1000;
        int thousand = num % 1000;
        num /= 1000;
        int million = num % 1000;
        num /= 1000;
        int billion = num % 1000;
        num /= 1000;
        int trillion = num % 1000;
        num /= 1000;

        vector<string> words;
        if (trillion) convert(words, trillion), words.push_back("Trillion");
        if (billion) convert(words, billion), words.push_back("Billion");
        if (million) convert(words, million), words.push_back("Million");
        if (thousand) convert(words, thousand), words.push_back("Thousand");
        if (one) convert(words, one);

        string result;
        for (string w : words) result += w + " ";
        result.pop_back();
        return result;
    }
};
