#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

int map[401][401];

inline void set(int x,int y,int t)
{
	if(map[x][y]==-1)
		map[x][y]=t;
	else
		map[x][y]=min(map[x][y],t);
}

int main()
{
	int m;
	scanf("%d",&m);
	memset(map,0xff,sizeof(map));
	for(int i=0;i<m;++i)
	{
		int x,y,t;
		scanf("%d %d %d",&x,&y,&t);
		set(x,y,t);
		if(x>0)
			set(x-1,y,t);
		if(y>0)
			set(x,y-1,t);
		if(x<500)
			set(x+1,y,t);
		if(y<500)
			set(x,y+1,t);
	}
	if(map[0][0]==0)
	{
		printf("-1\n");
		return 0;
	}
	else if(map[0][0]==-1)
	{
		printf("0\n");
		return 0;
	}
/*	
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
			printf("%d ",map[i][j]);
		printf("\n");
	}
*/	
	int cur=1,next=0,t=1;
	queue<int> path;
	path.push(0);
	while(!path.empty())
	{
		int x = path.front()>>16, y = path.front()&0xff;
		path.pop();
		--cur;
		if(x>0)
		{
			if(map[x-1][y]==-1){
				printf("%d\n",t);
				return 0;
			}
			else if(map[x-1][y]>t){
				path.push((x-1)<<16|y);
				++next;
				map[x-1][y]=0;
			}
		}
		if(x<500)
		{
			if(map[x+1][y]==-1){
				printf("%d\n",t);
				return 0;
			}
			else if(map[x+1][y]>t){
				path.push((x+1)<<16|y);
				++next;
				map[x+1][y]=0;
			}
		}
		if(y>0)
		{
			if(map[x][y-1]==-1){
				printf("%d\n",t);
				return 0;
			}
			else if(map[x][y-1]>t){
				path.push(x<<16|(y-1));
				++next;
				map[x][y-1]=0;
			}
		}
		if(y<500)
		{
			if(map[x][y+1]==-1){
				printf("%d\n",t);
				return 0;
			}
			else if(map[x][y+1]>t){
				path.push(x<<16|(y+1));
				++next;
				map[x][y+1]=0;
			}
		}
		if(cur==0)
		{
			swap(cur,next);
			++t;
		}
	}

	printf("-1\n");
	return 0;

}
