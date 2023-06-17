class Solution {
public:
    // vector<int> NSL(vector<int>&heights)
    // {
    //     int n=heights.size();
    //     stack<pair<int,int>>st;
    //     vector<int>ans;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(st.empty()) ans.push_back(-1);
    //         else if(st.top().first<heights[i]) ans.push_back(st.top().second);
    //         else if(st.top().first>=heights[i]){
    //             while(!st.empty() && st.top().first>=heights[i]) st.pop();
    //             if(st.empty()) ans.push_back(-1);
    //             else  ans.push_back(st.top().second);
    //         }
    //         st.push({heights[i],i});
    //     }
    //     return ans;
    // }
     vector<int>NSL(vector<int>h)
    {
        vector<int>left;
        stack<pair<int,int>>st;
        int pseudo=-1; 
        for(int i=0;i<h.size();i++)
        {
            if(st.empty())
               left.push_back(pseudo);
            
            else if(st.size()>0 && st.top().first<h[i])
                left.push_back(st.top().second);
            
            else if(st.size()>0 && st.top().first>=h[i])
            {
                while(st.size()>0 && st.top().first>=h[i])
                    st.pop();
                if(st.empty())
                    left.push_back(pseudo);
                else 
                    left.push_back(st.top().second);
            }
            st.push({h[i],i});
        }
        return left;
    }
    
    // vector<int> NSR(vector<int>&heights)
    // {
    //     int n=heights.size();
    //     stack<pair<int,int>>st;
    //     vector<int>ans;
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         if(st.empty()) ans.push_back(n);
    //         else if(st.top().first<heights[i]) ans.push_back(st.top().second);
    //         else if(st.top().first>=heights[i]){
    //             while(!st.empty() && st.top().first>=heights[i]) st.pop();
    //             if(st.empty()) ans.push_back(n);
    //             else  ans.push_back(st.top().second);
    //         }
    //         st.push({heights[i],i});
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }
    vector<int>NSR(vector<int>h)
    {
        vector<int>right;
        stack<pair<int,int>>st;
        int pseudo=h.size(); 
        for(int i=h.size()-1;i>=0;i--)
        {
            if(st.empty())
               right.push_back(pseudo);
            else if(st.size()>0 && st.top().first<h[i])
                right.push_back(st.top().second);
            else if(st.size()>0 && st.top().first>=h[i])
            {
                while(st.size()>0 && st.top().first>=h[i])
                    st.pop();
                if(st.empty())
                    right.push_back(pseudo);
                else 
                    right.push_back(st.top().second);
            }
            st.push({h[i],i});
        }
        reverse(right.begin(),right.end());
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        // vector<int>left=NSL(heights);
        // vector<int>right=NSR(heights);
        // int maxarea=-1;
        // for(int i=0;i<heights.size();i++)
        // {  
        //     cout<<left[i]<<" "<<right[i]<<endl;
        //     int width=right[i]-left[i]-1;
        //     maxarea=max(maxarea,width*heights[i]);
        // }
        // return maxarea;
        vector<int>left=NSL(heights);
        vector<int>right=NSR(heights);
        int maxarea=-1;
        for(int i=0;i<heights.size();i++)
        {
            int width=right[i]-left[i]-1;
            maxarea=max(maxarea,width*heights[i]);
        }
        return maxarea;
    }
};
