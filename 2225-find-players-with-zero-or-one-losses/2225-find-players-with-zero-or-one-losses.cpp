class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>win,lose;
        int n=matches.size();
        for(int i=0;i<n;i++)
        {
            int a=matches[i][0];
            int b=matches[i][1];
            lose[b]++;
            win[a]++;
        }
        vector<vector<int>>ans;
        vector<int>all_wins,one_lost;
        for(auto i:win) {
            if(!lose.count(i.first))
            all_wins.push_back(i.first);
        }
        for(auto &i:lose)
        {
            if(lose[i.first]==1)
                one_lost.push_back(i.first);
        }
        ans.push_back(all_wins);
        ans.push_back(one_lost);
        return ans;
    }
};