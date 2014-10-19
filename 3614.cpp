#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int c,l;

pair<int,int> cow[2500],lotion[2500];

int main()
{
	scanf("%d %d",&c,&l);
	for(int i=0;i<c;++i)
		scanf("%d %d",&cow[i].first,&cow[i].second);
	for(int i=0;i<l;++i)
		scanf("%d %d",&lotion[i].first,&lotion[i].second);
	sort(cow,cow+c);
	sort(lotion,lotion+l);

	priority_queue<int,vector<int>,greater<int> > q;
	int j=0,ans=0;
	for(int i=0;i<l;++i)
	{
		while(j<c&&cow[j].first<=lotion[i].first){
			q.push(cow[j++].second);
		}
		while(!q.empty()&&lotion[i].second>0)
		{
			if(q.top()>=lotion[i].first){
				++ans;
				--lotion[i].second;
			}
			q.pop();
		}
	}
	printf("%d\n",ans);
	return 0;
}
