class Solution {
public:
    bool is_valid_sound(map<char,int>& mp) {
        if(mp['c']>=mp['r'] && mp['r']>=mp['o'] && mp['o']>=mp['a'] && mp['a']>=mp['k']) {
            return true;
        }
        return false;
    }
    int minNumberOfFrogs(string croakOfFrogs) {
        int ans=0;
        map<char,int>freq;
        int croaking_frogs=0;
        for(auto i:croakOfFrogs) {
            freq[i]++;
            if(not is_valid_sound(freq)) {
            return -1;
            }
            if(i=='c') {
                croaking_frogs+=1;
            }else if(i=='k'){
                croaking_frogs-=1;
            }
            ans=max(ans,croaking_frogs);
        }
        if(croaking_frogs) {
            return -1;
        }
        return ans;
    }
};