#include <stdio.h>
#include <map>
using namespace std;
int data[1000000];
int p,d;
int main()
{
	d =0 ;
	scanf("%d",&p);
	map<int,int> hash;
	for(int i=0;i<p;++i)
	{
		scanf("%d",&data[i]);
		if(hash[data[i]]==0)
			++d;
		hash[data[i]] = 1;
	} 
	hash.clear();
	int head=0,tail=0,ret=0x7fffffff,cur=0;
	for(int i=0;i<p;++i)
	{
		if(hash[data[i]]==0)
			++cur;
		++hash[data[i]];
		if(cur==d)
		{
			while(head<=i)
			{
				hash[data[head]]--;
				++head;
				if(hash[data[head-1]]==0)
					break;
			}
			int len = i-head+2;
			ret = ret>len?len:ret;
			--cur;
		}
	}
	printf("%d\n",ret);
	return 0;
}
