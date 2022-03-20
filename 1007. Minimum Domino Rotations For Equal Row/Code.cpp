class Solution {
public:
    int solve(vector<int>A,vector<int>B,int c)
    {
       int total=0,cntInA=0,cntInB=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]==c||B[i]==c)
                total++;
            if(A[i]==c)
                cntInA++;
            if(B[i]==c)
                cntInB++;
        }
        if(total!=A.size())
            return -1;
        else if(cntInA>cntInB)
            return (total-cntInA);
        else 
            return (total-cntInB);
            
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=solve(tops,bottoms,tops[0]);
        return (ans!=-1?ans:solve(tops,bottoms,bottoms[0]));
    }
};