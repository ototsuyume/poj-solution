#include<stdio.h>
#include<map>
#include<string>

using namespace std;

int main()
{
	int total=0;
	char name[40];
	map<string,int> tree;
	while(scanf("%[^\n]",name)!=EOF)
	{
		string treename(name);
		++tree[treename];
		++total;
		getchar();
	}

	for(map<string,int>::iterator it = tree.begin();
			it!=tree.end();++it)
	{
		printf("%s %.04f\n",it->first.c_str(),(double)it->second*100/(double)total);
	}
	return 0;
}
