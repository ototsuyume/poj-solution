#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n,top=0,seq=1,gindex=0;
char ng[101]={0},dfn[101]={0},low[101]={0},instk[101]={0},stack[101]={0};
char indeg[101]={0},outdeg[101]={0};
vector<char> edge[101];
set<char> nedge[101];

void solve(int x)
{
	dfn[x]=low[x]=seq++;
	stack[top++]=x;
	instk[x]=1;
	for(int i=0;i<edge[x].size();++i)
	{
		int j=edge[x][i];
		if(!dfn[j])
		{
			solve(j);
			low[x]=min(low[x],low[j]);
		}
		else if(instk[j])
			low[x]=min(low[x],dfn[j]);
	}
	if(dfn[x]==low[x])
	{
		int j=x;
		do{
			j=stack[--top];
			instk[j]=0;
			ng[j]=gindex;
		}while(j!=x);
		++gindex;
	}
}
void scc()
{
	for(int i=0;i<n;++i)
		if(!dfn[i])
			solve(i);
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<edge[i].size();++j)
		{
			int x=edge[i][j];
			if(ng[x]==ng[i])continue;
				nedge[ng[i]].insert(x);
		}
	}
	for(int i=0;i<gindex;++i)
	{
		outdeg[i]=nedge[i].size();
		for(set<char>::iterator it=nedge[i].begin();it!=nedge[i].end();++it)
		{
			int x=ng[*it];
			++indeg[x];
		}
	}
}


int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int v;
		while(1){
			scanf("%d",&v);
			if(v==0)
				break;
			edge[i].push_back(v-1);
		}
	}
	scc();
	int ans1=0,ans2=0;
	for(int i=0;i<gindex;++i)
	{
		if(indeg[i]==0)
			++ans1;
		if(outdeg[i]==0)
			++ans2;
	}
	//ans2+=ans1-1;
	if(gindex==1)
		printf("1\n0\n");
	else
		printf("%d\n%d\n",ans1>0?ans1:1,ans1>ans2?ans1:ans2);
	return 0;
}
