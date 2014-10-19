#include<stdio.h>
#include<string.h>
static int data[350][350]={0};
static int dp[2][350]={0};

inline int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=i;++j)
		{
			scanf("%d",&data[i][j]);
		}
	}
	int *cur = dp[0];
	int *next = dp[1];
	cur[0]=data[0][0];
	for(int i=1;i<n;++i)
	{
		next[0]=cur[0]+data[i][0];
		next[i]=cur[i-1]+data[i][i];
		for(int j=1;j<i;++j)
		{
			next[j]=max(cur[j-1],cur[j])+data[i][j];
		}
		int *t = next;
		next = cur;
		cur = t;
	}
	int ans = 0;
	for(int i=0;i<n;++i)
	{
		ans = max(cur[i],ans);
	}
	printf("%d\n",ans);
	return 0;
}
