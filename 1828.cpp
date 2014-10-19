#include<algorithm>
#include<stdio.h>

using namespace std;


struct Point{
	int x,y;
};

bool cmp(const Point &a,const Point &b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}

Point monkey[50000];

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<n;++i)
		{
			scanf("%d %d",&monkey[i].x,&monkey[i].y);
		}
		sort(monkey,monkey+n,cmp);
		int r=1,my=monkey[n-1].y;
		for(int i=n-2;i>=0;--i)
		{
			if(monkey[i].x==monkey[i+1].x)
				continue;
			else if(monkey[i].y>my)
			{
				my = monkey[i].y;
				++r;
			}
		}
		printf("%d\n",r);
	}
	return 0;
}
