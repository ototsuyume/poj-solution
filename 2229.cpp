#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	unsigned int *data = new unsigned int[n+1];
	data[1]=1;
	data[2]=2;
	for(int i=3;i<=n;++i)
	{
		if(i%2==0)
		{
			data[i] = (data[i-1]+data[i/2])%1000000000;
		}
		else
		{
			data[i]=data[i-1];
		}
	}
	printf("%d\n",data[n]%1000000000);
	delete [] data;
	return 0;
}
