class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'||s.empty())
            return 0;
        int decodeuptoprev_idx=1,decodeuptocurr_idx=1,prev;
        // decodeuptoprev_idx means no of ways to decode upto index i-1
        // decodeuptocurr_idx means no of ways to decode upto index i
        // prev is to store decodeuptocurridx in each iteration
        for(int i=1;i<s.size();i++)
        {
            prev=decodeuptocurr_idx;
            if(s[i]=='0') 
                decodeuptocurr_idx=0;
            if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<'7'))
                decodeuptocurr_idx+=decodeuptoprev_idx;
            decodeuptoprev_idx=prev;
        }
        return decodeuptocurr_idx;
    }
};