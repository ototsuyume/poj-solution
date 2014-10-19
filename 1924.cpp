#include<stdio.h>

typedef struct monster_data
{
	char type;
	char count;
	char *x;
	char *y;
}md;

int main()
{
	char map[100][100] = {0};
	struct md ml[100]  = {0};	
	char width,height,mcount;
	
	while(1)
	{
		scanf("%d  %d",&height,width);
		if(height==0 && width==0)
			break;
		for(int i=0;i<height;++i)
			scanf("%s",map[i]);
		scanf("%d",&mcount);
		for(int i=0;i<mcount;++i)
		{
			int sc;
			scanf("%d",);
		}
	}

}

