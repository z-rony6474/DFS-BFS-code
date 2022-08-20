#include<bits/stdc++.h>
#define nl cout<<endl;
using namespace std;
typedef long long ll;
char Mat[25][25];
bool visit[25][25];
ll cnt = 0;
ll col, row;
ll dx[] = {-1,1,0,0};
ll dy[] = {0,0,1,-1};
bool check(ll x,ll y)
{
	if(x>=0 && x<row && y>=0 && y<col && Mat[x][y]!='#' && !visit[x][y])
	{
		return true;
	}
	return false;
}

ll DFS(ll x,ll y)
{
	visit[x][y]=true;
	cnt++;
	for(ll i=0;i<4;i++)
	{
		ll a = x+dx[i];
		ll b = y+dy[i];
		if(check(a,b))
		DFS(a,b);
	} 
	return cnt;
}


void solve(ll Case)
{
	cin >> col >> row;
	for(ll i=0;i<row;i++)
	{
		for(ll j=0;j<col;j++)
		{
			cin >> Mat[i][j];
		}
	}
	
	memset(visit,false,sizeof(visit));
	cnt = 0;
	for(ll i=0;i<row;i++)
	{
		for(ll j=0;j<col;j++)
		{
			if(Mat[i][j]=='@')
			{
				DFS(i,j);
			}
		}
	}
	cout <<"Case " << Case <<": "<<cnt<<endl;
}
int main()
{
	ll t;
	cin>>t;
	ll Case = 0;
	while(t--)
	{
	  Case++;
	  solve(Case);
	}
	return 0;
}
