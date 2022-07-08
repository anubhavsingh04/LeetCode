// biggest number of box would be when we have 99999 balls (highLimit is 10e5) i.e 9*5 = 45.
// Make a vector of 46 element initialised with zero 
// calculate sum for each insert into the vector 
// return the max element of vector 

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int>box(46,0);
        for(int i=lowLimit;i<=highLimit;i++)
        {
            int tmp=i;
            int sum=0;
            while(tmp>0)
            {
                sum+=tmp%10;
                tmp/=10;
            }
            box[sum]++;
        }
        return *max_element(box.begin(),box.end());
    }
};