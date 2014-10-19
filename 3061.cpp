#include<stdio.h>

int d[100000];
int main()
{
	int c;
	scanf("%d",&c);
	for(int i=0;i<c;++i)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&d[i]);
		}
		int res=0x7fffffff,sum=0,begin=0,end=0;
		while(end<n)
		{
			sum+=d[end];
			if(sum>=k)
			{
				while(begin<=end&&sum>k)
				{
					sum-=d[begin];
					++begin;
				}
				int tmp=end-begin+2;
				res=res>tmp?tmp:res;

			}
			++end;
		}
		res=res==0x7fffffff?0:res;
		printf("%d\n",res);
	}
	return 0;
}
