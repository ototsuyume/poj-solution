#include<stdio.h>
#include<string.h>

char map[5][5], used[1000000];
int total;


void dfs(int x,int y,int count,int val)
{
	if(count==0)
	{
		if(!used[val]){
			++total;
			used[val]=1;
		}
		return;
	}
	val=val*10+map[x][y];
	if(x>0)dfs(x-1,y,count-1,val);
	if(y>0)dfs(x,y-1,count-1,val);
	if(x<4)dfs(x+1,y,count-1,val);
	if(y<4)dfs(x,y+1,count-1,val);
}
int main()
{
	for(int i=0;i<5;++i)
	{
		for(int j=0;j<5;++j)
			scanf("%d",&map[i][j]);
	}
	memset(used,0,sizeof(used));
	total=0;
	for(int i=0;i<5;++i)
	{
		for(int j=0;j<5;++j)
		{
			dfs(i,j,6,0);
		}
	}
	printf("%d\n",total);
	return 0;
}
