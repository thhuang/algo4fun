class Encrypter {
   public:
    Encrypter(vector<char>& keys, vector<string>& values,
              vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); ++i) {
            keys_to_values_.insert({keys[i], values[i]});
            values_to_keys_.insert({values[i], keys[i]});
        }
        for (string d : dictionary) ++value_count_[encrypt(d)];
    }

    string encrypt(string word1) {
        string s;
        for (char c : word1) s += keys_to_values_[c];
        return s;
    }

    int decrypt(string word2) { return value_count_[word2]; }

   private:
    unordered_map<char, string> keys_to_values_;
    unordered_multimap<string, char> values_to_keys_;
    unordered_map<string, int> value_count_;
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
