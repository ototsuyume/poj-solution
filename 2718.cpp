#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>

using namespace std;

int d[10];
int n,num;

int getval(int *A,int start,int len)
{
	int r=0;
	for(int i=start;i<len;++i)
		r=r*10+A[i];
	return r;
}


int solve()
{
	int ret=10000000;
	int k=num/2;
	do
	{
		if(d[0]==0||d[k]==0)continue;
		int a=getval(d,0,k),b=getval(d,k,num);
		ret=min(ret,abs(a-b));
	}while(next_permutation(d,d+num));
	if(num==2)
		return abs(d[0]-d[1]);
	return ret;
}

int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;++i)
	{
		num=0;
		char c;
		while((c=getchar())!='\n')	
		{
			if(c==' ')continue;
			d[num++]=c-'0';
		}
		printf("%d\n",solve());
	}
	return 0;
}
