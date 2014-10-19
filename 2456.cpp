#include <stdio.h>
#include <algorithm>
using namespace std;
#define INFNUM  0x7fffffff

int data[100000];
int m,n;

bool test(int d)
{
	int last = 0;
	for(int i=1;i<m;++i)
	{
		int next = last+1;
		while(next<n&&data[next]-data[last]<d)++next;
		if(next==n)
			return false;
		last = next;
	}
	return true;
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&data[i]);
	int lb = 0,ub = INFNUM;
	sort(data,data+n);
	while(ub-lb>=0)
	{
		int mid = (ub+lb)/2;
		if(test(mid))
			lb = mid+1;
		else
			ub = mid-1;
	}
	printf("%d\n",lb-1);
	return 0;
}
