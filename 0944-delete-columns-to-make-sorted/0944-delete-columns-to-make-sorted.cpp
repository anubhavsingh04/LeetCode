class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        int n=str.size(),m=str[0].size(),cnt=0;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(str[j][i]<str[j-1][i]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};