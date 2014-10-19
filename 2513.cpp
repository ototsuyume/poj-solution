#include<stdio.h>
#include<string.h>


struct _trie{
	int child[26];
	int num,count;
};

_trie trie[2550000*2]; 
int set[510000];

int cur=1,diff=0,total=0,odd=0;

int find(int i)
{
	if(set[i]==-1)
		set[i]=i;
	if(set[i]==i)return i;
	
	set[i] = find(set[i]);
	return set[i];
}

int merge(int i,int j)
{
	int pj=find(j),pi=find(i);
	set[pi]=pj;
	return pj;
}

int insert(const char *str)
{
	int pos=0;
	while(*str)
	{
		int c=*str-'a';
		if(trie[pos].child[c]!=0)
			pos = trie[pos].child[c];
		else
		{
			trie[pos].child[c]=cur;
			pos = cur++;
			memset(&trie[pos],0,sizeof(_trie));
		}
		++str;
	}	
	trie[pos].count++;
	if(trie[pos].count==1)
		trie[pos].num = diff++;
	if(trie[pos].count%2==0)
		--odd;
	else
		++odd;
	return trie[pos].num;
}



int main()
{
	char c1[11],c2[11];
	memset(set,0xff,sizeof(set));
	while(scanf("%s %s",c1,c2)!=EOF)
	{
		getchar();
		int num1=insert(c1);
		int num2=insert(c2);		
		merge(num1,num2);
	}
	if(diff==0)
	{
		printf("Possible\n");
		return 0;
	}
	if(odd!=0&&odd!=2)
	{
		printf("Impossible\n");
		return 0;
	}
	int snum = find(0);
	for(int i=1;i<diff;++i)
		if(snum!=find(i))
		{
			printf("Impossible\n");
			return 0;
		}
	printf("Possible\n");
	return 0;
		
}
