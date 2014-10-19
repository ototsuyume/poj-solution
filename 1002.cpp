#include<cstdio>
#include<map>
using namespace std;
char table[]={2,3,4,5,6,7,8,9};

int main(int argc,char* argv[])
{
	int c,len,data;
	char input[64],*p,ic,str[9];
	map<int,int> v;
	
	scanf("%d\n",&c);
	for(int i=0;i<c;++i)
	{
		scanf("%s",input);
		p=input;
		len=0;
		str[8]=0;
		data=0;
		while(*p)
		{
			if(*p>='A'&&*p<='Y')
			{
				ic = *p-'A';
				if(ic>=17)
					data=data*10+table[(ic-1)/3];
				else
					data=data*10+table[ic/3];
			}
			else if(*p=='-')
			{
				++p;
				continue;
			}
			else
			{
				data=data*10+*p-'0';
			}
			++p;
		}

//		if(v.find(a)!=v.end())
		v[data]++;
//		else
//			v.insert(pair<int,int>(a,1));
		
	}
	len=0;
	for(map<int,int>::iterator itor=v.begin();itor!=v.end();++itor)
	{
		if(itor->second>1)
		{
			printf("%03d-%04d %d\n",itor->first/10000,itor->first%10000,itor->second);
			++len;
		}
	}
	if(len==0)
		printf("No duplicates.\n");
	return 0;
}
