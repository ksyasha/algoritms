#include<bits/stdc++.h>
using namespace std;
vector <int> graph[1000];
bool used[1000];
int dist[1000], par[1000];
void bfs(int v)
{
	queue <int> q;
	dist[v]=0;
	par[v]=-1;
	used[v]=true;
	q.push(v);
	while (!q.empty())
	{
	  int r=q.front();
	  q.pop();
	  for (int to:graph[r])	
	  {
	  	if (!used[to])
	  	{
	  	  used[to]=true;
	  	  q.push(to);
	  	  dist[to]=dist[r]+1;
	  	  par[to]=r;
		}
	  }
	}
}
int main()
{
  int n;
  cin>>n;
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
	{
	  int c;
	  cin>>c;
	  if (c==1) graph[i].push_back(j);	
	}
	int b,e;
	cin>>b>>e;
	bfs(b);	
	if (used[e])
	{
		cout<<dist[e]<<endl;
		if (dist[e]>0)
		{
			vector <int> p;
			p.push_back(e);
			while (par[e]!=-1)
			{
				e=par[e];
				p.push_back(e);
			}
			reverse(p.begin(),p.end());
			for (int i=0; i<p.size(); i++)
			  cout<<p[i]<<" ";
		}
	}
	else cout<<-1;
}
