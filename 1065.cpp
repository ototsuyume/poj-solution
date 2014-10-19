#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct stick
{
	int len;
	int wei;
};

bool cmp(stick a,stick b)
{
	if(a.len==b.len)
		return a.wei<b.wei;
	return a.len<b.len;
}

int main()
{
	int count;
	scanf("%d",&count);
	for(int i=0;i<count;++i)
	{
		int c;
		scanf("%d",&c);
		vector<stick> data;
		for(int j=0;j<c;++j)
		{
			stick s;
			scanf("%d %d",&s.len,&s.wei);
			data.push_back(s);
		}
		sort(data.begin(),data.end(),cmp);
		vector<char> bm(c,0);
		int total=0;
		for(int j=0;j<c;++j)
		{
			if(bm[j])
				continue;
			bm[j]=1;
			int l = j;
			for(int k=l+1;k<c;++k)
			{
				if(data[l].wei<=data[k].wei&&bm[k]==0){
					l = k;
					bm[k]=1;
				}
			}
			++total;
		}
		printf("%d\n",total);
	}
	return 0;
}
