#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;


char map[300][300],visited[300][300];

int m,n,sx,sy;

struct state{
	int x,y,count;
};


class cmp{
	public:
		bool operator()(const state &a,const state &b)
		{
			return a.count>b.count;
		}
};

static int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int main()
{
	while(1)
	{
		scanf("%d %d",&m,&n);
		if(m==0||n==0)
			break;
		getchar();
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='Y')
				{
					sx=i;
					sy=j;
				}
			}
			getchar();
		}
		memset(visited,0,sizeof(visited));
		visited[sx][sy]=1;
		priority_queue<state,vector<state>,cmp> q;
		state s;
		s.x=sx,s.y=sy,s.count=0;
		q.push(s);
		bool find=false;
		while(!q.empty())
		{
			state s=q.top();
			q.pop();
			int x=s.x,y=s.y;
			for(int i=0;i<4;++i)
			{
				int nx = x+dir[i][0];
				int ny = y+dir[i][1];
				if(nx<0||nx>=m||ny<0||ny>=n||visited[nx][ny]||map[nx][ny]=='S'||map[nx][ny]=='R')
					continue;
				if(map[nx][ny]=='T')
				{
					printf("%d\n",s.count+1);
					find=true;
					break;
				}
				visited[nx][ny]=1;
				state ns;
				ns.x=nx,ns.y=ny;
				if(map[nx][ny]=='B')
					ns.count=s.count+2;
				else
					ns.count=s.count+1;
				q.push(ns);
			}
			if(find)
				break;
		}
		if(!find)
			printf("-1\n");
	}
	return 0;
}
