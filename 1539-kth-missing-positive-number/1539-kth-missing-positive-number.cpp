class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        for (auto a : arr) 
            if (a <= k) 
                k++;
            else 
                 break;
        return k; 
        
//          if(arr[0]!=1)
//         {
//             int res=arr[0]-1;
//             if(res<k)
//                 k-=res;
//             else
//                 return k;
//         }
//         for(int i=0; i<arr.size()-1; i++)
//         {
//             int sum=arr[i+1]-arr[i];
//             if(sum>1)
//             {
//                 if(sum>k)
//                 {    
//                    int ans =arr[i]+k;
//                    return ans;
//                 }
//                 else
//                 {
//                     k-=sum-1;
//                 }
//             }
            
                
//         }
//        return arr[arr.size()-1]+k;
    
    }
};
