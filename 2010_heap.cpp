#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

int n,c,f;

struct data{
	int s,f;
};

bool cmp(const data &a,const data &b)
{
	return a.s<b.s;
}

data d[100000];
int bf[100000],ff[100000];

int main()
{
	scanf("%d %d %d",&n,&c,&f);
	for(int i=0;i<c;++i)
		scanf("%d %d",&d[i].s,&d[i].f);
	sort(d,d+c,cmp);
	int bs=-1,total=0;
	priority_queue<int> front,back;
	if(n>1){
		for(int i=0;i<c;++i)
		{
			if(front.size()<n/2)
			{
				total+=d[i].f;
				front.push(d[i].f);
			}
			else if(front.top()>d[i].f)
			{
				total-=front.top();
				total+=d[i].f;
				front.pop();
				front.push(d[i].f);
			}
			if(front.size()==n/2)
				ff[i]=total;
		}
		total=0;
		for(int i=c-1;i>=0;--i)
		{
			if(back.size()<n/2)
			{
				total+=d[i].f;
				back.push(d[i].f);
			}
			else if(back.top()>d[i].f)
			{
				total-=back.top();
				total+=d[i].f;
				back.pop();
				back.push(d[i].f);
			}
			if(back.size()==n/2)
				bf[i]=total;
		}
	}
	for(int i=n/2;i<c-n/2;++i)
	{
		int fa=0;
		if(n!=1)
			fa = ff[i-1]+bf[i+1]+d[i].f;
		else
			fa=d[i].f;

		if(fa<=f)
			bs=d[i].s;
	}
	printf("%d\n",bs);
	return 0;
}
