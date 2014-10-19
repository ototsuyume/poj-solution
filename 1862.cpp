#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}

int data[100];
int main()
{
	int c;
	scanf("%d",&c);
	for(int i=0;i<c;++i)
		scanf("%d",&data[i]);
	sort(data,data+c,cmp);
	double k = 1.0*data[0];
	for(int i=1;i<c;++i)
	{
		k = 2*sqrt(data[i]*k);
	}
	printf("%.03f\n",k);
}
