class Solution {
public:
    string intToRoman(int num) {
        int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int i=0;string ans="";
        while(num)
        {
            while(num>=value[i])
            {
                ans+=roman[i];
                num-=value[i];
            }
            i++;
        }
        return ans ;
    }
};