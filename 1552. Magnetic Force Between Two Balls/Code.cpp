class Solution {
    bool possible(vector<int>& position, int distance, int m) {
        int lastPosition = position[0];
        int ballsNeedToBePlaced = m - 1;
        for (int i = 1; i < position.size() && ballsNeedToBePlaced > 0; i++) {
            if (position[i] - lastPosition >= distance) {
                lastPosition = position[i];
                ballsNeedToBePlaced--;
            }
        }
        return ballsNeedToBePlaced == 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1;
        int right = 1e9;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (possible(position, mid, m))
                left = mid;
            else
                right = mid - 1;
        }

        return left;
    }
};