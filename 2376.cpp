#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct cow
{
	int start;
	int end;
}cow;

bool cmp(cow a,cow b)
{
	if(a.start==b.start)
		return a.end<b.end;
	return a.start<b.start;
}

int main()
{
	int n,t;
	scanf("%d %d",&n,&t);
	cow *d = new cow[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d %d",&d[i].start,&d[i].end);
	}
	sort(d,d+n,cmp);
	int ins=0,i=0,last=0;
	while(i<n&&last<t)
	{
		int tmp=0,flag=0;
		for(;i<n&&d[i].start<=last+1&&tmp<t;++i)
		{
			if(d[i].end>last)
			{
				flag=1;
				tmp = d[i].end>tmp?d[i].end:tmp;
			}
		}	
		if(!flag)
		{
			printf("-1\n");
			return 0;
		}
		last = tmp;
		++ins;
	}
	if(i==n&&last<t)
		printf("-1\n");
	else
		printf("%d\n",ins);
	delete [] cow;
	return 0;
}
