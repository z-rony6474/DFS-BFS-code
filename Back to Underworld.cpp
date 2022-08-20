#include<bits/stdc++.h>
#define nl cout<<endl;
#define black 1
#define red   2
#define white 0
using namespace std;
typedef long long ll;
vector<ll>graph[20005];
ll color[20005];
ll vampr = 0, lykn = 0;
void clr()
{
	for(ll i=0; i<20005; i++)
	{
		graph[i].clear();
	}
}
void BFS(ll x)
{
	queue<ll>q;
	q.push(x);
	color[x] = black;
	vampr++;
	while(!q.empty())
	{
		ll val = q.front();
		q.pop();
		for(ll i=0; i<graph[val].size();i++)
		{
			ll nm = graph[val][i];
			if(color[nm]==white)
			{
				q.push(nm);
				if(color[val]==black)
				{
					color[nm]=red;
					lykn++;
				}
				else
				{
					color[nm]=black;
					vampr++;
				}	
			}
		}
	}	
}
void solve(ll Case)
{
	ll n;
	cin >> n;
	for(ll i=0;i<n;i++)
	{
		ll u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
     memset(color, 0 , sizeof color);
	ll ans = 0;
	for(ll i=0;i<20005;i++)
	{
		vampr = 0, lykn = 0;
		if(color[i]==white and graph[i].size()!=0)
		{
			BFS(i);
		}
		ans += max(vampr,lykn);
	}
	cout << "Case " << Case << ": " << ans << endl;
}
int main()
{
	ll t;
	cin>>t;
	ll Case =0 ;
	while(t--)
	{
	  clr();
	  Case++;
	  solve(Case);
	}
	return 0;
}
