/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
    string getHostname(string url) {
        url += '/';
        int i = url.find('/', 7);
        return url.substr(7, i - 7);
    }

   public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string targetHostname = getHostname(startUrl);

        unordered_set<string> result;
        function<void(string)> dfs = [&](string url) -> void {
            string hostname = getHostname(url);
            if (hostname != targetHostname) return;
            if (result.count(url) > 0) return;
            result.insert(url);

            for (auto nextUrl : htmlParser.getUrls(url)) {
                dfs(nextUrl);
            }
        };
        dfs(startUrl);

        return {result.begin(), result.end()};
    }
};
