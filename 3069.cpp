#include<stdio.h>
#include<algorithm>
using namespace std;

int data[1000];


int main()
{
	int n,r;
	while(scanf("%d %d",&r,&n)==2)
	{
		if(r==-1||n==-1)
			break;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&data[i]);
		}
		sort(data,data+n);
		int count=0,pos=0;
		while(pos<n)
		{
			int range=data[pos++]+r;
			while(pos<n&&data[pos]<=range)pos++;
			range=data[pos-1]+r;
			while(pos<n&&data[pos]<=range)pos++;
			++count;
		}
		printf("%d\n",count);
	}
	return 0;
}
