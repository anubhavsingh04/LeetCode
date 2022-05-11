class Solution {
public:
    int maxProfit(vector<int>& A, int T) {
        sort(rbegin(A), rend(A)); // sort in descending order
        long mod = 1e9+7, N = A.size(), cur = A[0], ans = 0, i = 0;
        while (T) {
            while (i < N && A[i] == cur) ++i; // handle those same numbers together
            long next = i == N ? 0 : A[i], h = cur - next, r = 0, cnt = min((long)T, i * h);
            if (T < i * h) { // the i * h balls are more than what we need.
                h = T / i; // we just reduce the height by `T / i` instead
                r = T % i; 
            }
            long val = cur - h; // each of the remainder `r` balls has value `cur - h`.
            ans = (ans + (cur + val + 1) * h / 2 * i + val * r) % mod;
            T -= cnt;
            cur = next;
        }
        return ans;
    }
};