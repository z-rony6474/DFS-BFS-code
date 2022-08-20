#include<bits/stdc++.h>
#define nl cout<<endl;
using namespace std;
typedef long long ll;
vector<ll>graph[510];
ll ans;
ll BFS(ll n)
{
	ans = INT_MAX;
	for(ll i=0;i<n;i++)
	{
		vector<ll>dis(n,INT_MAX);
		vector<ll>parent(n,-1);
		queue<ll>q;
		dis[i]=0;
		q.push(i);
		while(!q.empty())
		{
			ll x = q.front();
			q.pop();
			for(ll j=0;j<graph[x].size();j++)
			{
				ll child = graph[x][j];
				if(dis[child]==INT_MAX)
				{
					dis[child] = dis[x]+1;
					parent[child]=x;
					q.push(child);
				}
		      	else if(parent[x]!=child)
				{
					ans = min(ans,dis[x]+dis[child]+1);
				}
			}
		}	
	}
}

void solve(ll Case)
{
	ll n,m;
	cin >> n >> m;
	for(ll i=0;i<510;i++)
	{
		graph[i].clear();
	}
	for(ll i=0;i<m;i++)
	{
		ll u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	BFS(n);
	if(ans!=INT_MAX)
	cout<< "Case "<<Case<<": "<< ans << endl;
	else
	cout<< "Case "<<Case<<": "<< "impossible" << endl;
	
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
