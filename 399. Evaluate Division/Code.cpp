class Solution {
public:
	double divid(string A, string B, set<string> visited, map<string,map<string,double>> m){
		if(A==B) return 1.0;
		visited.insert(A);
		for(auto x:m[A]){
			string s=x.first;
			if(visited.count(s)) continue;
			double d=divid(s,B,visited,m);
			if(d>0) return d*m[A][s];
		}
		return -1.0;
	}
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		map<string,map<string,double>> m;
		vector<double> res;
		set<string> table;
		for(int i=0;i<equations.size();i++){
			m[equations[i][0]][equations[i][1]]=values[i];
			m[equations[i][1]][equations[i][0]]=1.0/values[i];
			table.insert(equations[i][0]);
			table.insert(equations[i][1]);

		}
		for(auto x:queries){
			if(table.count(x[0])==0 || table.count(x[1])==0){
				res.push_back(-1.0);
				continue;
			}
			string A=x[0];
			string B=x[1];
			set<string> visited;
			res.push_back(divid(A,B,visited,m));
		}
		return res;


	}
};