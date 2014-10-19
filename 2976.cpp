#include<stdio.h>
#include<algorithm>

using namespace std;

double s[1000];
int a[1000],b[1000],n,k;

bool get(double mid)
{
	for(int i=0;i<n;++i)
	{
		s[i]=a[i]-b[i]*mid;
	}
	sort(s,s+n);
	double sum=0.0;
	for(int i=k;i<n;++i)
	{
		sum+=s[i];
	}
	return sum>0;
}

int main()
{
	while(1)
	{
		scanf("%d %d",&n,&k);
		if(n==0&&k==0)
			break;
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		for(int i=0;i<n;++i)
			scanf("%d",&b[i]);
		double l=0.0,r=1.0;
		while(r-l>0.000001)
		{
			double mid=(r+l)/2;
			if(get(mid))l=mid;
			else r=mid;
		}
		int p=(int)(l*1000)%10 >=5?1:0;
		printf("%d\n",(int)(l*100)+p);
	}
	return 0;
}
