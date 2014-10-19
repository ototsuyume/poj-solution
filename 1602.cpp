#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<list>
#include<string.h>
using namespace std;

typedef struct {
	char head;
	char tail;
	int  pos;
}data;

bool comp(const data& a,const data& b)
{
	if(a.head==b.head)
		return a.pos<b.pos;
	else
		return a.head < b.head;
}

bool comp2(char a,char b)
{
	return a<b;
}

void printlist(list<data> &l)
{
	for(list<data>::iterator itor=l.begin();
			itor!=l.end();
			++itor)
	{
		printf("%c   %c\n",itor->head,itor->tail);
	}
}

char find(list<data>& l,char c)
{
	char t=0;
	for(list<data>::iterator itor=l.begin();itor!=l.end();++itor)
	{
		if(itor->head == c)
		{
			t = itor->tail;
			l.erase(itor);
			break;
		}
	}
	return t;
}

int main()
{
	char type;
	int size,begin;
	char *a;
	data d;
	scanf("%c",&type);
	scanf("%d",&size);
	a = new char [size+1];

	scanf("%s",a);
	if(type=='A')
	{
		vector<data> vec;
		for(int i=0;i<size;++i)
		{
			d.head = a[i];
			d.pos  = i;
			d.tail = a[(size-1+i)%size];
			vec.push_back(d);
		}
		sort(vec.begin(),vec.end(),comp);
		for(int i=0;i<size;++i)
		{
			if(vec[i].pos == 1||size==1)
				begin = i+1;
			a[i] = vec[i].tail;
		}
		printf("%s\n%d\n",a,begin);
	}
	else if(type=='B')
	{
		list<data> lis;
		scanf("%d",&begin);
		char *b = new char [size];
		memcpy(b,a,size+1);
		sort(b,b+size,comp2);
		for(int i=size-1;i>=0;--i)
		{
			d.head = b[i];
			d.tail = a[i];
			lis.push_back(d);
		}
		b[0] = a[begin-1];
		list<data>::iterator tmp;
	
		
		for(list<data>::iterator itor = lis.begin();itor!=lis.end();++itor)
		{
			if(itor->head == a[begin-1])
				tmp = itor;
		}
		b[size-1] = tmp->tail;
		lis.erase(tmp);
		/*
		for(int i=2;i<size;++i)	
		{

		printlist(lis);
		printf("--------\n");
			b[i] = find(lis,b[i-1]);
		}
		*/

		for(int i=size-2;i>=0;--i)
		{
			b[i]=find(lis,b[i+1]);
		}
		b[size]=0;
		printf("%s\n",b);
	}

	return 0;
}
