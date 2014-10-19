#include<algorithm>
#include<stdio.h>
#include<math.h>

using namespace std;

double res[100];
int main()
{
	int c;
	scanf("%d",&c);
	for(int i=0;i<c;++i)
	{
		int n,h,r,t;
		scanf("%d %d %d %d",&n,&h,&r,&t);
		for(int j=0;j<n;++j)
		{
			if(t<0)
			{
				res[j]=h;
				continue;
			}
			double nt = sqrt(h*0.2);
			int k=int( t/nt);
			if(k%2)
			{
				double d=k*nt+nt-t;
				res[j] = h-d*d*5;
			}
			else
			{
				double d=t-k*nt;
				res[j] = h- d*d*5;
			}
			--t;
		}

		sort(res,res+n);
		for(int j=0;j<n;++j)
		{
			printf("%.2f",res[j]+0.02*r*j);
			if(j<n-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
