#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

struct node
{
	int vx,val;
};


class cmp
{
	public:
		bool operator()(const node &a,const node &b)
		{
			return a.val>b.val;
		}
};
int main()
{
	int count;
	scanf("%d",&count);
	for(int i=0;i<count;++i)
	{
		int n,m,r;
		scanf("%d %d %d",&n,&m,&r);
		vector<node> *d = new vector<node>[m+n];
		bool *used = new bool [m+n];
		memset(used,0,sizeof(bool)*(m+n));
		for(int j=0;j<r;++j)
		{
			int vx,vy,val;
			scanf("%d %d %d",&vx,&vy,&val);
			node ne;
			ne.vx=vy+n;
			ne.val=-val;
			d[vx].push_back(ne);
			ne.vx=vx;
			d[vy+n].push_back(ne);
		}
		priority_queue<node,vector<node>,cmp> q;
		long long res=(m+n)*10000;
		int count=0;
		for(int j=0;j<n+m;++j)
		{
			if(used[j])continue;
			node ne;
			ne.vx=j;
			ne.val=0;
			q.push(ne);
			while(!q.empty())
			{
				node vex = q.top();
				q.pop();
				int x=vex.vx,v=vex.val;
				if(used[x]) continue;
				++count;
				res+=v;
				used[x]=true;
				for(int k=0;k<d[x].size();++k)
				{
					q.push(d[x][k]);
				}
			}
			if(count==m+n)
				break;
		}
		delete [] used;
		printf("%lld\n",res);
	}
	return 0;
}

