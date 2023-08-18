class Solution {
public:
    map<string,string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s = longUrl.substr(0,20);
        m[s] = longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));