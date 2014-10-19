#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;


int add[30000],get[30000],m,n;

int main()
{
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;++i)
		scanf("%d",&add[i]);
	for(int i=0;i<n;++i)
		scanf("%d",&get[i]);

	priority_queue<int,vector<int>,greater<int> > minheap;
	priority_queue<int> maxheap;
	int pos=0;
	for(int i=0,j=0;i<=m;++i)
	{
		while(j<n&&i==get[j])
		{
			++j;
			if(maxheap.size()>pos)
			{
				while(maxheap.size()>pos+1)
				{
					minheap.push(maxheap.top());
					maxheap.pop();
				}
				printf("%d\n",maxheap.top());
			}
			else
			{
				int pos2 = pos-maxheap.size();
				while(pos2-->0)
				{
					maxheap.push(minheap.top());
					minheap.pop();
				}
				printf("%d\n",minheap.top());
			}
			++pos;
		}
		if(i==m)break;
		if(!maxheap.empty()&&add[i]<=maxheap.top())
			maxheap.push(add[i]);
		else
			minheap.push(add[i]);
	}
	return 0;
}
