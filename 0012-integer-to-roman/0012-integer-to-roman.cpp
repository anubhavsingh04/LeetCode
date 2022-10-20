class Solution {
public:
    string intToRoman(int num) {
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int val[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int i=0;
        string ans="";
        while(num)
        {
            while(num>=val[i])
            {
                num-=val[i];
                ans+=roman[i];
            }
            i++;
        }
        return ans;
    }
};