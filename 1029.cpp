#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<stdlib.h>

int coin[1001];
unsigned short test[1001];
int main()
{
	int n,k,c=0;
	scanf("%d %d",&n,&k);
	memset(coin,0,(n+1)*sizeof(int));
	for(int i=0;i<k;++i)
	{
		int count;
		scanf("%d",&count);
		for(int j=0;j<2*count;++j)
			scanf("%d",&test[j]);
		char sym;
		scanf("%c",&sym);
		scanf("%c",&sym);
		if(sym=='=')
		{
			for(int j=0;j<2*count;++j)
				coin[test[j]]=0x7fffffff;
		}
		else if(sym=='<')
		{
			for(int j=0;j<count;++j)
			{
				if(coin[test[j]]!=0x7fffffff)
					coin[test[j]]--;
				if(coin[test[count+j]]!=0x7fffffff)
					coin[test[count+j]]++;
			}
			++c;
		}
		else
		{
			for(int j=0;j<count;++j)
			{
				if(coin[test[j]]!=0x7fffffff)
					coin[test[j]]++;
				if(coin[test[count+j]]!=0x7fffffff)
					coin[test[count+j]]--;
			}
			++c;
		}
	}
	int res=0,backup=0;
	{
		for(int i=1;i<n+1;++i)
		{
			if(coin[i]==c||-coin[i]==c)
			{
				if(res>0)
				{
					res=0;
					break;
				}
				else
				{
					res=i;
				}
			}
			else if(coin[i]==0)
			{
				if(backup!=0&&backup!=-1)
					backup=i;
				else
					backup=-1;
			}
		}
	}
	if(res==0&&backup>0)
		res=backup;
	printf("%d\n",res);
	return 0;
}
