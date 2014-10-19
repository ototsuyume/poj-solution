#include<stdio.h>
#include<queue>

using namespace std;
class cmp
{
	public:
		bool operator()(int a,int b) const
		{
			return a>b;
		}
};

int main()
{
	int n=0;
	while(scanf("%d",&n)!=EOF){
	priority_queue<int,vector<int>,cmp> q;
	for(int i=0;i<n;++i)
	{
		int c;
		scanf("%d",&c);
		q.push(c);
	}
	unsigned long long ret=0;
	while(q.size()>1)
	{
		int v1=q.top();
		q.pop();
		int v2=q.top();
		q.pop();
		q.push(v1+v2);
		ret+=v1+v2;
	}
		printf("%lld\n",ret);
	}
	return  0;
}
