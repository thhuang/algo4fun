class Solution {
    unordered_map<string, string> long2short_;
    unordered_map<string, string> short2long_;
    int serial_num_ = 0;
    string base_ = "https://tinyurl.com/";

   public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (auto it = long2short_.find(longUrl); it != long2short_.end()) {
            return base_ + it->second;
        }
        string path = to_string(serial_num_++);
        long2short_[longUrl] = path;
        short2long_[path] = longUrl;
        return base_ + path;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (shortUrl.size() < base_.size() + 1) return shortUrl;

        string base = shortUrl.substr(0, base_.size());
        if (base != base_) return shortUrl;

        string path = shortUrl.substr(base_.size());
        auto it = short2long_.find(path);
        if (it == short2long_.end()) return shortUrl;
        return it->second;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
