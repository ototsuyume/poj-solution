#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<unsigned int,unsigned int> P;
struct edge{
	vector<P> v;
};

edge e[5000];
bool used[5000];

unsigned int mmin[5000];
unsigned int smin[5000];

class cmp
{
	public:
	bool operator ()(const P &a,const P &b) const
	{
		return a.second>b.second;
	}
};

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		e[a-1].v.push_back(P(b-1,c));
		e[b-1].v.push_back(P(a-1,c));
	}
	memset(mmin,0xff,sizeof(int)*5000);
	memset(smin,0xff,sizeof(int)*5000);
	memset(used,0,sizeof(bool)*5000);
	priority_queue<P,vector<P>,cmp> q;

	q.push(P(0,0));
	while(!q.empty())
	{
		P p = q.top();
		q.pop();
		unsigned int v=p.first,d=p.second;
		if(smin[v]<d)
			continue;
		for(int i=0;i<e[v].v.size();++i)
		{
			unsigned int nd = d+e[v].v[i].second,nv=e[v].v[i].first;
			if(nd<mmin[nv]){
				swap(nd,mmin[nv]);
				q.push(P(nv,mmin[nv]));
			}
			if(nd<smin[nv]){
				swap(nd,smin[nv]);
				q.push(P(nv,smin[nv]));
			}
		}
	}
	printf("%d\n",smin[n-1]);

}





