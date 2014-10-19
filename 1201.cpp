#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
struct edge
{
	int next,val;
};
vector<edge> g[50010];
int d[50010];
bool v[50010];
int n,mmax=-1,mmin=0x7fffffff;

void path(int cur)
{
	v[cur]=true;
	for(int i=0;i<g[cur].size();++i)
	{
		int next = g[cur][i].next;
		if(d[cur]+g[cur][i].val>d[next])
		{
			d[next]=d[cur]+g[cur][i].val;
			printf("%d %d %d\n",cur,next,d[next]);
			if(!v[next])
				path(next);
		}
	}
	v[cur]=false;
}

int main()
{
	memset(d,0xff,sizeof(int)*50010);
	memset(v,0,sizeof(bool)*50010);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int s,e,c;
		scanf("%d %d %d",&s,&e,&c);
		if(mmin>s)mmin=s;
		if(mmax<e+1)mmax=e+1;
		edge node={e+1,c};
		g[s].push_back(node);
	}

	for(int i=mmin;i<mmax;++i)
	{
		edge node={i+1,0};
		g[i].push_back(node);
		edge node1={i,-1};
		g[i+1].push_back(node1);
	}
	d[mmin]=0;
	path(mmin);
	printf("%d\n",d[mmax]);
	return 0;
}
