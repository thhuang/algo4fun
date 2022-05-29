class Solution {
   public:
    string discountPrices(string sentence, int discount) {
        double rate = 0.01 * (100 - discount);
        stringstream in(sentence), out;

        string w;
        while (in >> w) {
            if (w[0] != '$' || w.size() == 1 || !isdigit(w[1])) {
                out << w << " ";
                continue;
            }

            string num_str = w.substr(1);
            long long v = stoll(num_str);

            if (v < 0 || to_string(v) != num_str) {
                out << w << " ";
                continue;
            }

            out << "$" << fixed << setprecision(2) << rate * v << " ";
        }

        string result = out.str();
        result.pop_back();

        return result;
    }
};
