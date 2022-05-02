class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char>st;
        int cnt=0;
        for(int i=0;i<jewels.size();i++)
        {
            st.insert(jewels[i]);
        }
        for(int i=0;i<stones.size();i++)
        {
            if(st.find(stones[i])!=st.end())
                cnt++;
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int numJewelsInStones(string jewels, string stones) {
//         set<char>st;
//         int cnt=0;
//         for(int i=0;i<jewels.size();i++)
//         {
//             st.insert(jewels[i]);
//         }
//         for(int i=0;i<stones.size();i++)
//         {
//             cnt+=st.count(stones[i]);
//         }
//         return cnt;
//     }
// };
