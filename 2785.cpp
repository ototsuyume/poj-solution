#include<algorithm>
#include<stdio.h>

using namespace std;

int a[4000],b[4000],c[4000],d[4000];
int cd[4000*4000];


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cd[i*n+j]=c[i]+d[j];
		}
	}
	sort(cd,cd+n*n);
	long long res=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			int target = -a[i]-b[j];
			int *l = lower_bound(cd,cd+n*n,target);
			int *u = upper_bound(cd,cd+n*n,target);
			res+=u-l;
		}
	}
	printf("%lld\n",res);
	return 0;
}
