class Solution {
public:
    void makeset(vector<int>&parent,vector<int>&rank,int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findparent(vector<int>&parent,int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node]=findparent(parent,parent[node]);
    }

    void unionset(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        int p1 = findparent(parent,u);
        int p2 = findparent(parent,v);
        if(p1==p2)
        {
            return;
        }
        if(rank[p1]<rank[p2])
        {
            parent[p1]=p2;
        }
        else if(rank[p2]<rank[p1])
        {
            parent[p2]=p1;
        }
        else 
        {
            parent[p2]=p1;
            rank[p1]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
       vector<int>parent(n);
       vector<int>rank(n);
       makeset(parent,rank,n);
       int count=0;
       for(auto it:connections)
       {
           int a = it[0];
           int b = it[1];
           if(findparent(parent,a) == findparent(parent,b))
           {
               // cout<<a<<' '<<b<<endl;
                count++;
           }
           else
           {
               unionset(a,b,parent,rank);
           }
       }
       int component=0;
       for(int i=0;i<n;i++)
       {
           if(parent[i]==i)
           {
               // cout<<i<<' '<<endl;
               component++;
           }
       }
       int ans=component-1;
        // cout<<count<<" "<<ans;
      if(count>=ans)
      {
          return ans;
      }
      return -1;
    }
};