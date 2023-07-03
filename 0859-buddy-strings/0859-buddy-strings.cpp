class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int i=0,j=s.size()-1;
         if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); // Swapping same characters
        }
        while(i<j && s[i]==goal[i]){
            i++;
        }
        while(j>i && s[j]==goal[j]){
            j--;
        }
        swap(s[i],s[j]);
        return s==goal;
    }
};