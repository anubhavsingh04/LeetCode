#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define mp make_pair
#define F first
#define S second

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		if((n==1||m==1)&&abs(n-m)>1)
		{
			cout<<-1<<endl;
			continue;
		}
		int d=abs(n-m);
		int mini=min(n,m);
		int maxi=max(n,m);
		int ans=(mini-1)+(mini-1);
		if(d%2==0)
		cout<<ans+2*d<<endl;
		else
		cout<<ans+2*d-1<<endl;

	}
	return(0);
}