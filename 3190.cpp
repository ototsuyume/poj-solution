#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

struct period{
	int num,time,type;     //type mean whether the period is start time or end time 
};

#define BEGIN 0
#define END   1

bool cmp(const period &a,const period &b)
{
	if(a.time==b.time)
	{
		if(a.type==b.type)
			return a.num<b.num;
		return a.type<b.type;
	}
	return a.time<b.time;
}


int cow[50000];
period t[100000];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d %d",&t[2*i].time,&t[2*i+1].time);
		t[2*i].num=i;
		t[2*i+1].num=i;
		t[2*i].type=BEGIN;
		t[2*i+1].type=END;
	}
	priority_queue<int,vector<int>,greater<int> > q;
	sort(t,t+2*n,cmp);
	int count=0;
	for(int i=0;i<2*n;++i)
	{
		if(t[i].type==BEGIN)
		{
			if(q.empty())
				cow[t[i].num]=++count;
			else{
				cow[t[i].num]=q.top();
				q.pop();
			}
		}
		else
		{
			q.push(cow[t[i].num]);
		}
	}
	printf("%d\n",count);
	for(int i=0;i<n;++i)
		printf("%d\n",cow[i]);
	return 0;
}
