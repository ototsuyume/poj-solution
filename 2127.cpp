#include<stdio.h>
#include<string.h>

int dp[500][500],pre[500][500];
int a[500],b[500],res[500],la,lb;

inline int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	scanf("%d",&la);
	for(int i=0;i<la;++i)
		scanf("%d",&a[i]);
	scanf("%d",&lb);
	for(int i=0;i<lb;++i)
		scanf("%d",&b[i]);
	if(la==0||lb==0)
	{
		printf("0\n");
		return 0;
	}
	memset(dp,0,sizeof(dp));
	/*
	for(int i=0;i<la;++i)
	{	
		if(b[0]==a[i])
			dp[i][0]=1;
		else
			dp[i][0]=i>0?dp[i-1][0]:0;
	}
	for(int i=0;i<lb;++i)
	{
		if(a[0]==b[i])
			dp[0][i]=1;
		else
			dp[0][i]=i>0?dp[0][i-1]:0;
	}
*/
	for(int i=0,ma,last;i<la;++i)
	{
		ma=0;
		last=-1;
		for(int j=0;j<lb;++j)
		{
			if(a[i]==b[j])
			{
				dp[i][j]=ma+1;
				pre[i][j]=last;
			}
			else
			{
				dp[i][j]=max(i>0?dp[i-1][j]:0,dp[i][j]);
				if(a[i]>b[j]&&ma<(i>0?dp[i-1][j]:0))
				{
					ma = i>0?dp[i-1][j]:0;
					last=j;
				}
			}
		}
	}
	int ret=0,x=0,y=0;
	for(int i=0;i<la;++i)
	{
		for(int j=0;j<lb;++j)
		{
			if(dp[i][j]>ret)
			{
				ret=dp[i][j];
				x=i;y=j;
			}

		}
	}

	printf("%d\n",ret);
	int c=ret;
	--ret;
	while(ret>=0)
	{
		res[ret--]=b[y];
		y=pre[x][y];
		while(a[x]!=b[y]&&x>0)--x;
	}
	for(int i=0;i<c;++i){
		printf("%d",res[i]);
		if(i!=c-1)
			printf(" ");
	}
	printf("\n");
	return 0;
}
