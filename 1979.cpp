#include<stdio.h>

int w,h,res;
char map[20][20];

void dfs(int x,int y)
{
	++res;
	map[x][y]=0;
	if(x>0&&map[x-1][y]=='.')
		dfs(x-1,y);
	if(y>0&&map[x][y-1]=='.')
		dfs(x,y-1);
	if(x<h-1&&map[x+1][y]=='.')
		dfs(x+1,y);
	if(y<w-1&&map[x][y+1]=='.')
		dfs(x,y+1);
}

int main()
{
	char tmp;
	while(1)
	{
		scanf("%d %d\n",&w,&h);
		if(w==0||h==0)
			break;
		int x=-1,y=-1;
		for(int i=0;i<h;++i)
		{
			for(int j=0;j<w;++j)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@')
				{
					x=i;
					y=j;
				}
			}
			scanf("%c",&tmp);
		}
		res=0;
		dfs(x,y);
		printf("%d\n",res);
	}
	return 0;	
}
