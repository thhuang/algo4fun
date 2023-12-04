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

class Encrypter {
    unordered_map<string, int> encryptFreq;
    unordered_map<char, int> keyToIndex;
    const vector<string> values;

   public:
    Encrypter(vector<char>& keys, vector<string>& values,
              vector<string>& dictionary)
        : values(values) {
        for (int i = 0; i < keys.size(); ++i) {
            keyToIndex[keys[i]] = i;
        }

        for (const string& w : dictionary) {
            string enc = encrypt(w);
            if (!enc.empty()) {
                ++encryptFreq[enc];
            }
        }
    }

    string encrypt(string word1) {
        string enc = "";
        for (char c : word1) {
            if (keyToIndex.count(c) == 0) {
                return "";
            }
            enc += values[keyToIndex[c]];
        }
        return enc;
    }

    int decrypt(string word2) { return encryptFreq[word2]; }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
