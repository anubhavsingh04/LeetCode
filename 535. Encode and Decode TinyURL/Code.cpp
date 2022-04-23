// class Solution {
// public:

//     // Encodes a URL to a shortened URL.
//     string encode(string longUrl) {
//         return longUrl;
//     }

//     // Decodes a shortened URL to its original URL.
//     string decode(string shortUrl) {
//         return shortUrl;
//     }
// };

class Solution {
    unordered_map<string,string>m;
    int cnt=0;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl="http://tinyurl.com/"+to_string(cnt);
        m[shortUrl]=longUrl;
        cnt++;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));