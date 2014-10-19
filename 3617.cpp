#include<stdio.h>

char s[2001];
inline bool cmp(int l,int r)
{
	while(l<r&&s[l]==s[r])
	{
		++l,--r;
	}
	if(l>=r)return true;
	return s[l]<s[r];
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		s[i]=getchar();
		if(s[i]=='\n')
			--i;
	}
	int l=0,r=n-1,pos=0;
	while(pos<n)
	{
		if(cmp(l,r))
		{
			putchar(s[l++]);
		}
		else
		{
			putchar(s[r--]);
		}
		++pos;
		if(pos%80==0)
			putchar('\n');
	}
	if(pos%80)
		putchar('\n');
	return 0;
}
