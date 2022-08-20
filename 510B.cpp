// URL: https://codeforces.com/problemset/problem/510/B
#include<bits/stdc++.h>
#define nl cout<<endl;
using namespace std;
typedef long long ll;
char Mat[55][55];
bool visit[55][55];
ll n,m;
ll dx[] = {-1,1,0,0};
ll dy[] = {0,0,1,-1};
char s;
bool check(ll x,ll y)
{
     if(x>=0 && x<n && y>=0 && y<m && !visit[x][y] && Mat[x][y]==s)
	{
		return true;
	}
	return false;
}
ll DFS(ll x,ll y,ll p,ll q)
{
	for(ll i=0;i<4;i++)
	{
		ll a = x+dx[i];
		ll b = y+dy[i];
		if(check(a,b) && (a!=p || b!=q))
		{
			visit[a][b]=true;
			DFS(a,b,x,y);
		}
		
	} 
}

void solve()
{
	cin >> n >> m;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>Mat[i][j];
		}
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			 memset(visit,false,sizeof(visit));
			 s=Mat[i][j];
			 DFS(i,j,i,j);
			 if(visit[i][j])
			 {
			 	cout<<"Yes\n";
			 	return ;
			 }
		}
	}
	cout<<"No\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
     cin.tie(NULL);
	solve();
	return 0;
}
