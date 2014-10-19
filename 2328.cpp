#include<stdio.h>
#include<string.h>

int main()
{
	char msg[128];
	char s[11];
	memset(s,0,sizeof(s));
	int c=0,target=0;
	bool res=true;
	while(1)
	{
		int v;
		scanf("%d",&v);
		if(v==0)
			break;
		getchar();
		gets(msg);
		
		if(strcmp(msg,"too high")==0){
			if(s[v]==1)
				res=false;
			s[v]=2;
		}
		else if(strcmp(msg,"too low")==0){
			if(s[v]==2)
				res=false;
			s[v]=1;
		}
		else if(strcmp(msg,"right on")==0)
		{
			if(s[v]!=0)
				res=false;
			for(int i=1;i<v;++i)
			{
				if(res&&s[i]==2)
				{
					res=false;
					break;
				}
			}
			for(int i=v+1;i<=10;++i)
			{
				if(res&&s[i]==1)
				{
					res=false;
					break;
				}
			}
			printf("Stan %s\n",res?"may be honest":"is dishonest");
			res=true;
			memset(s,0,sizeof(s));
		}
	}
	return 0;
}
