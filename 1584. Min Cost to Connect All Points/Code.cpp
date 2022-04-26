class Solution {
public:
    int find(vector<int> &par, int i) {
        if (par[i] != i) {
            par[i] = find(par, par[i]);
        }
        return par[i];
    }
    void uniondsu(vector<int> &par, vector<int> &sz, int &x, int &y, int &w, int &ans, int &E) {
        int p1 = find(par, x);
        int p2 = find(par, y);
        if (p1 == p2) return;
        ans += w;
        E--;
        if (sz[p1] > sz[p2]) {
            sz[p1] += sz[p2];
            par[p2] = p1;
        } else {
            sz[p2] += sz[p1];
            par[p1] = p2;
        }
        return;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edge;
        int n = points.size();
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int sz = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edge.push_back({sz, i, j});
            }
        }
        sort(edge.begin(), edge.end());
        vector<int> par(n);
        vector<int> size(n, 1);
        for(int i=0; i<n; i++) par[i] = i;
        int E = n-1;
        int ans = 0;
        for(auto &i: edge) {
            int w, x, y;
            w = i[0];
            x = i[1];
            y = i[2];
            uniondsu(par, size, x, y, w, ans, E);
            if (!E) break;
        }
        return ans;
    }
};