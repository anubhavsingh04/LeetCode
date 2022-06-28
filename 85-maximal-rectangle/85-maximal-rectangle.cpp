class Solution {
public:
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
    
    // next smaller to right traverse from right 
    // here we will assume that one building is after lastmost index of 0 height
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
        return right;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left=NSL(heights);
        vector<int>right=NSR(heights);
        vector<int>width;
        reverse(right.begin(),right.end());
        
        int maxarea=-1;
        for(int i=0;i<heights.size();i++)
        {
            int width=right[i]-left[i]-1;
            maxarea=max(maxarea,width*heights[i]);
        }
        return maxarea;
    }
    
    // upar ke teen function largest rectangle in histogram vale q ka hai
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>v;
        for(int j=0;j<matrix[0].size();j++)
        {
            v.push_back(matrix[0][j]-'0');
        }
        int maxi=largestRectangleArea(v);
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='0')
                    v[j]=0;
                else 
                    v[j]+=matrix[i][j]-'0';
            }
            maxi=max(maxi,largestRectangleArea(v));
        }
        return maxi;
    }
};