class Solution {
  int hex2int(string h) {
    stringstream ss(h);
    int v;
    ss >> hex >> v;
    return v;
  }

  string getSimilar(string hs) {
    int h = hex2int(hs);

    string result;
    int diff = numeric_limits<int>::max();
    for (char c = '0'; c <= '9'; ++c) {
      int v = hex2int({c, c});
      if (int d = abs(h - v); d < diff) {
        result = {c, c};
        diff = d;
      }
    }
    for (char c = 'a'; c <= 'f'; ++c) {
      int v = hex2int({c, c});
      if (int d = abs(h - v); d < diff) {
        result = {c, c};
        diff = d;
      }
    }

    return result;
  }

public:
  string similarRGB(string color) {
    return string(1, '#') + getSimilar(color.substr(1, 2)) +
           getSimilar(color.substr(3, 2)) + getSimilar(color.substr(5, 2));
  }
};
