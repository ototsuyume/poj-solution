#include <stdio.h>
#include <string.h>

int dp[31][1001]={0};
int count[1001]={0};
int main()
{
	int w,t;
	scanf("%d %d",&t,&w);
	for(int i=0;i<t;++i)
		scanf("%d",&count[i]);
	int max=0;
	//memset(dp,0,sizeof(int)*31*1001);

	dp[0][0]=count[0]==1?1:0;
	dp[1][0]=count[0]==2?1:0;

	for(int i=1;i<t;++i)
	{
		dp[0][i] = dp[0][i-1]+(count[i]==1?1:0);
		//printf("dp[0][i]:%d\n",dp[0][i]);
		for(int j=1;j<=w&&j<=i;++j)
		{
			//printf("%d %d\n",dp[j][i-1],dp[j-1][i-1]);
			int cur = (dp[j-1][i-1]>dp[j][i-1])?dp[j-1][i-1]:dp[j][i-1];
			dp[j][i] = cur + ((j%2+1)==count[i]?1:0);
			//printf("cur:%d loc:%d val:%d %d %d \n",cur,count[i],dp[j][i],i,j);
		}
	}

	for(int i=0;i<=w;++i)
	{
		max = max>dp[i][t-1]?max:dp[i][t-1];
	}
	
memset(dp,0,sizeof(int)*31*1001);

	dp[0][0]=count[0]==2?1:0;
	dp[1][0]=count[0]==1?1:0;

	for(int i=1;i<t;++i)
	{
		dp[0][i] = dp[0][i-1]+(count[i]==2?1:0);
		//printf("dp[0][i]:%d\n",dp[0][i]);
		for(int j=1;j<=w&&j<=i;++j)
		{
			//printf("%d %d\n",dp[j][i-1],dp[j-1][i-1]);
			int cur = (dp[j-1][i-1]>dp[j][i-1])?dp[j-1][i-1]:dp[j][i-1];
			dp[j][i] = cur + ((j%2)==(count[i]%2)?1:0);
			//printf("cur:%d loc:%d val:%d %d %d \n",cur,count[i],dp[j][i],i,j);
		}
	}

	for(int i=0;i<=w;++i)
	{
		max = max>dp[i][t-1]?max:dp[i][t-1];
	}

	printf("%d\n",max);
	return 0;
}
