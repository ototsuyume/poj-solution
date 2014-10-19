#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char cow[5000],op[5000];
int n;

int cal(int k)
{
	memset(op,0,n);
	int res=0,sum=0;
	for(int i=0;i+k<=n;++i)
	{
		if((cow[i]+sum)%2!=0)
		{
			++res;
			op[i]=1;
		}
		sum+=op[i];
		if(i-k+1>=0)
			sum-=op[i-k+1];
	}
	for(int i=n-k+1;i<n;++i)
	{
		if((cow[i]+sum)%2!=0)
		{
			return -1;
		}
		if(i-k+1>=0)
			sum-=op[i-k+1];
	}
	return res;

}
int main()
{
	scanf("%d\n",&n);
	char c;
	for(int i=0;i<n;++i){
		scanf("%c\n",&c);
		if(c=='B')
			cow[i]=1;
		else
			cow[i]=0;
	}
	int m = 0x7fffffff,k=-1;
	for(int i=n;i>0;--i)
	{
		int tmp = cal(i);
		if(tmp==-1)
			continue;
		if(tmp<m)
		{
			m = tmp;
			k=i;
		}
	}
	printf("%d %d\n",k,m);
	return 0;
}
