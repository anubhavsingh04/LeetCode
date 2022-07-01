// Sort the boxes in decreasing order 
// Take the boxes if the total no of boxes+ current number of  box is less than trucksize
// otherwise check how many boxes we can take by subtracting total boxestaken from trucksize i.e.
// trucksize-boxestaken 

class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b)
    {
        if(a[1]==b[1])
            return a[0]>b[0];
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        
        int unit=0;
        int boxesTaken=0;
        
        for(int i=0;i<boxTypes.size();i++)
        {
            int curr=boxTypes[i][0];
            if(boxesTaken+curr<=truckSize)
            {
                boxesTaken+=curr;
                unit+=curr*boxTypes[i][1];
            }
            else 
            {
                unit+=(truckSize-boxesTaken)*boxTypes[i][1];
                break;
            }
        }
        return unit;
    }
};