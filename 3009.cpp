#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAXINT 0x7fffffff

int map[20][20];
int w,h,ans;
int sx,sy,ex,ey;

void dfs(int x,int y,int cur)
{
	if(x==ex&&y==ey)
	{
		ans=min(cur,ans);
		return;
	}
	else if(cur>10)
		return;
	for(int i=x+1;i<h&&map[i][y]!=1;++i)
	{
		if(i==ex&&y==ey)
		{
			ans=min(cur+1,ans);
			return;
		}
		else if(i<h-1&&map[i+1][y]==1)
		{
			map[i+1][y]=0;
			dfs(i,y,cur+1);
			map[i+1][y]=1;
			break;
		}
	}
	for(int i=x-1;i>=0&&map[i][y]!=1;--i)
	{
		if(i==ex&&y==ey)
		{
			ans=min(cur+1,ans);
			return;
		}
		else if(i>0&&map[i-1][y]==1)
		{
			map[i-1][y]=0;
			dfs(i,y,cur+1);
			map[i-1][y]=1;
			break;
		}
	}
	for(int i=y-1;i>=0&&map[x][i]!=1;--i)
	{
		if(x==ex&&i==ey)
		{
			ans=min(cur+1,ans);
			return;
		}
		else if(i>0&&map[x][i-1]==1)
		{
			map[x][i-1]=0;
			dfs(x,i,cur+1);
			map[x][i-1]=1;
			break;
		}
	}
	for(int i=y+1;i<w&&map[x][i]!=1;++i)
	{
		if(x==ex&&i==ey)
		{
			ans=min(cur+1,ans);
			return;
		}
		else if(i<w-1&&map[x][i+1]==1)
		{
			map[x][i+1]=0;
			dfs(x,i,cur+1);
			map[x][i+1]=1;
			break;
		}
	}
}

int main()
{
	while(1)
	{
		scanf("%d %d",&w,&h);
		if(w==0&&h==0)
			break;
		ex=ey=sx=sy=-1;
		for(int i=0;i<h;++i)
		{
			for(int j=0;j<w;++j)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)
				{
					sx=i;sy=j;
				}
				else if(map[i][j]==3)
				{
					ex=i;ey=j;
				}
			}
		}
		ans=MAXINT;
		if(ex!=-1&&ey!=-1&&sx!=-1&&sy!=-1)
			dfs(sx,sy,0);
		ans=ans>10?-1:ans;
		printf("%d\n",ans);
	}
	return 0;
}

