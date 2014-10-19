#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
struct data
{
	int l,v;
};
bool cmp(const data &a,const data &b)
{
	return a.l<b.l;
}
int main()
{
	int n,l,c;
	scanf("%d",&c);
	data *d = new data[c];
	for(int i=0;i<c;++i)
	{
		scanf("%d %d",&d[i].l,&d[i].v);
	}
	scanf("%d %d",&l,&n);
	priority_queue<int> q;
	sort(d,d+c,cmp);
	int ret = 0,i=c-1;
	while(n<l){
		while(i>=0&&(l-d[i].l)<=n){
			q.push(d[i--].v);
		}
		if(q.empty())
			break;
		n+=q.top();
		q.pop();
		++ret;
	}
	if(n<l)
		printf("-1\n");
	else
		printf("%d\n",ret);
	delete [] data;
	return 0;

}
