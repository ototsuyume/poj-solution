#include<stdio.h>

double len[10000];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	double sum=0;
	for(int i=0;i<n;++i)
	{
		scanf("%lf",&len[i]);
		sum+=len[i];
	}
	double low=0,upper = sum/k,last=0,mid=0;
	while(upper-low>0.0000001)
	{
		mid=(low+upper)/2.0;
		int count=0;
		for(int i=0;i<n;++i)
		{
			count+=int(len[i]/mid);
		}
		if(count>=k){
			last=mid>last?mid:last;
			low=mid;
		}
		else
			upper=mid;
	}
	printf("%.02lf\n",int((last+0.0000005)*100)*0.01);
}
