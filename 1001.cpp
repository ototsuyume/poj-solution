#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUM 1000000

unsigned int bignum[400];
unsigned short ftable[5]={1,10000,1000,100,10};
unsigned int table[7]={10,100,1000,10000,100000,1000000};

int main(int argc,char* argv[])
{
	char s[256];
	int  p,data,i,j,c,temp,maxlen;
	unsigned long long res;
	bool cont;

	while(scanf("%s %d",s,&p)==2)
	{
		memset(bignum,0,sizeof(int)*400);
		i = 0;
		c = 0;
		cont=true;
		for(j=5;j>=0;--j)
		{
			if(s[j]=='0'&&cont)
			{
				++c;
				continue;
			}
			if(s[j]=='.')
			{
				break;
			}
			cont = false;
			++i;
		}
		if(j>0)
		{

			s[j]=0;
			i = 5-j-c;
			s[6-c]=0;
			if(i>0)
			{
				data = atoi(&s[j+1]);
				data+=(atoi(s)*ftable[j+c]);

			}
		}
		else
			i=0;
		if(i==0)
		{
			data=atoi(s);
		}
		//printf("i:%d data:%d\n",i,data);
		bignum[0]=1;
		maxlen=0;
		for(j=0;j<p;++j)
		{

			temp=0;
			for(c=0;c<=maxlen;++c)
			{
				res = (unsigned long long)bignum[c]*data;
				res+=temp;
				temp = res/MAX_NUM;
				bignum[c]=res%MAX_NUM;
				//printf("c:%d bignum:%lld\n",c,bignum[c]);
			}
			if(temp>0)
			{
				++maxlen;
				bignum[maxlen]=temp;
			}
		}
		i*=p;
		temp = bignum[maxlen];
		c=MAX_NUM/10;
		j=6;
		while((temp/c)==0)
		{
			c/=10;
			--j;
		}
		temp=maxlen*6+j;
		//printf("result length:%d %d\n",temp,i);
		if(i>=temp)
		{
			printf(".");
			for(j=0;j<i-temp;++j)
				printf("0");
			i=0;
		}
		for(j=temp-1;j>=0;--j)
		{
			if(i>0)
			{
				if(j==i-1)
					printf(".");
			}
			printf("%d",(bignum[j/6]%table[j%6])/(table[j%6]/10));
		}
		/*
		if(i==0)
		{
			for(j=maxlen;j>=0;--j)
			{
				printf("%d",bignum[j]);
			}
		}
		else if(temp<=i)
		{
			printf(".");
			for(j=0;j<temp-i;++j)
			{
				printf("0");
			}
			for(j=maxlen;j>=0;--j)
				printf("%d",bignum[j]);
		}
		else
		{
			c=i/6;
			for(j=maxlen;j>=0;--j)
			{
				if(j==c)
				{
					temp=table[i%6];
					printf("%d.",bignum[j]/temp);

					printf("%d",bignum[j]%temp);
				}
				else
					printf("%d",bignum[j]);
			}
				
		}
		*/
		
		printf("\n");
	}
	return 0;
}

