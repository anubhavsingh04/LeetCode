class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> vc;
        for(int i = 0; i < difficulty.size(); i++) vc.push_back(make_pair(difficulty[i], profit[i]));   
        sort(vc.begin(), vc.end());
        for(int i = 1; i < vc.size(); i++) vc[i].second=max(vc[i].second, vc[i-1].second);
         
        sort(worker.begin(), worker.end());
        int  x = 0, ans=0;
        for(int i = 0; i < worker.size(); i++){
            while(vc[x].first<=worker[i] && vc.size()>x){
                x++;
            }
            ans+=x==0?0:vc[x-1].second;
        }
        return ans;
    }
};
