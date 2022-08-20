#include<bits/stdc++.h>
#define nl cout<<endl;
using namespace std;
typedef long long ll;
vector<ll>tree[30005];
vector<ll>weight[30005];
bool visit[30005];
ll dis[30005];
ll first_node = 0, max_dis = -1;
void clear(ll n)
{
	for(ll i=0;i<n;i++)
	{
		visit[i]=false;
		dis[i]= 0;
	}
}
ll BFS(ll start,ll n)
{
	max_dis = -1;
	queue<ll>q;
	q.push(start);
	visit[start]=true;
	while(!q.empty())
	{
		ll root = q.front();
		q.pop();
		for(ll i = 0 ; i<tree[root].size(); i++)
		{
			ll val = tree[root][i];
			if(!visit[val])
			{
				q.push(val);
				visit[val]=true;
				dis[val] = dis[root] + weight[root][i];
				if(dis[val]>max_dis)
				{
					max_dis = dis[val];
					first_node = val;
				}
			} 
		}
		
	}
	return first_node;
	return max_dis;
}
void solve(ll Case)
{
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		tree[i].clear();
		weight[i].clear();
	}
	for(ll i=0;i<n-1;i++)
	{
		ll u,v,c;
		cin>>u>>v>>c;
		tree[u].push_back(v);
		tree[v].push_back(u);
		weight[u].push_back(c);
		weight[v].push_back(c);
	}
	clear(n);
     BFS(0,n);
     //cout<<first_node<<endl;
     clear(n);
     BFS(first_node,n);
     cout<<"Case " << Case <<": "<<max_dis<<endl;
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
