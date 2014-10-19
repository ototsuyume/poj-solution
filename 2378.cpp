#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>

using namespace std;


vector<int> g[10001];

char visited[10001],res[10001];
int n;

int dfs(int c)
{
	bool isok=true;
	int pn=n-1;
	visited[c]=1;
	for(int i=0;i<g[c].size();++i)
	{
		if(!visited[g[c][i]])
		{
			int tmp = dfs(g[c][i]);
			if(tmp>n/2)
				isok=false;
			pn-=tmp;
		}
	}
	if(pn<=n/2&&isok)
		res[c]=1;
	return n-pn;
}

int main()
{
	memset(visited,0,sizeof(visited));
	memset(res,0,sizeof(res));
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(1);
	for(int i=1;i<=n;++i)
		if(res[i])
			printf("%d\n",i);
	return 0;
}
