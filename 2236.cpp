#include<stdio.h>
#include<string.h>

int n;
double d;
char status[10010];
int set[10010];
int x[10010],y[10010];


int find(int i)
{
	if(set[i]==-1){
		set[i]=i;
		return i;
	}
	if(set[i]==i)return i;
	int p=  find(set[i]);
	set[i]=p;
	return p;
}

void merge(int i,int j)
{
	int pj=find(j),pi=find(i);
	set[pi]=pj;
}

bool test(int i,int j)
{
	return find(i)==find(j);
}

int main()
{
	scanf("%d %lf",&n,&d);
	d*=d;
	memset(status,0,sizeof(status));
	memset(set,0xff,sizeof(set));
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	getchar();
	char type;
	while((type=getchar())!=EOF)
	{
		if(type=='O')
		{
			int c;
			scanf("%d",&c);
			status[c]=1;
			for(int i=1;i<=n;++i)
			{
				if(i==c||!status[i])continue;
				int dx=x[i]-x[c],dy=y[i]-y[c];
				if(dx*dx+dy*dy<=d)
					merge(i,c);
			}
		}
		else
		{
			int a,b;
			scanf("%d %d",&a,&b);
			if(status[a]&&status[b]&&test(a,b))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
		getchar();
	}
	return 0;
}
