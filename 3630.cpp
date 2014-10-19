#include<stdio.h>
#include<string.h>

int tree[100005][10];
int par[100005];

int cur,flag;

inline int getint(char c)
{
	return c-'0';
}

void insert(const char *str)
{
	int pos=0,now=0;
	while(*str)
	{
		int v=getint(*str);
		now = tree[pos][v];
		if(now==0)
		{
			par[cur]=0;
			memset(tree[cur],0,sizeof(tree[cur]));
			tree[pos][v]=cur++;
			now=tree[pos][v];
		}
		if(par[now])
		{
			flag=1;
			return;
		}
		pos=now;
		++str;
	}
	par[pos]=1;
	for(int i=0;i<10;++i)
	{
		if(tree[pos][i])
		{
			flag=1;
			return;
		}
	}
}

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&m);
		flag=0;
		cur=1;
		memset(tree[0],0,sizeof(tree[0]));
		for(int j=0;j<m;++j)
		{
			char phone[11];
			scanf("%s",phone);
			if(!flag) insert(phone);
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
