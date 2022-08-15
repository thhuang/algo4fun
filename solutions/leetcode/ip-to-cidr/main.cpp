class Solution {
   public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> result;
        ulong x = ip2ulong(ip);
        while (n > 0) {
            ulong dx = x & -x;
            if (dx == 0) dx = 1ULL << 31;

            while (dx > n) dx >>= 1;
            result.push_back(ulong2block(x, dx));
            x += dx;
            n -= dx;
        }
        return result;
    }

    ulong ip2ulong(const string& ip) {
        string b;
        for (int l = 0; l < ip.size();) {
            int r = find(ip.begin() + l, ip.end(), '.') - ip.begin();
            string s = ip.substr(l, r - l);
            b += bitset<8>(stoi(s)).to_string();
            l = r + 1;
        }
        return bitset<32>(b).to_ulong();
    }

    string ulong2block(ulong x, ulong dx) {
        array<string, 4> ip;
        for (int i = 3; i >= 0; --i) {
            ip[i] = to_string(x % 256);
            x /= 256;
        }
        ulong v = 1, pow = 0;
        while (v < dx) {
            v <<= 1;
            ++pow;
        }
        return ip[0] + '.' + ip[1] + '.' + ip[2] + '.' + ip[3] + '/' +
               to_string(32 - pow);
    }
};
