#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

enum{
	back,
	forward,
	other,
};
int main()
{
	vector<string> stack(100);
	int sp=0,max=0;
	string last="http://www.acm.org/";
	char buff[80];
	int action = other; 
	while(1)
	{
		scanf("%s",buff);
		if(strcmp(buff,"QUIT")==0)
			break;
		else if(strcmp(buff,"VISIT")==0)
		{
			scanf("%s",buff);
			if(action==back)
				++sp;
			if(!last.empty())
			{
				stack[sp++]=last;
				
				string().swap(last);
			}
			printf("%s\n",buff);
			last = buff;
			action = other;
			max = sp;
		}
		else if (strcmp(buff,"BACK")==0)
		{
			if(sp==0||(action==forward&&sp==1))
			{
				printf("Ignored\n");
				continue;
			}
			//printf("%d\n",sp);
			if(!last.empty())
			{
				stack[max++]=last;
				//max = sp+1;
				string().swap(last);
			}
			if(action==forward)
				--sp;
			action = back;
			printf("%s\n",stack[--sp].c_str());
		}
		else if(strcmp(buff,"FORWARD")==0)
		{
			if(max==sp||(action==back&&sp-1==max))
			{
				
				printf("Ignored\n");
				continue;
			}
			
			if(action==back)
				++sp;
			action=forward;
			printf("%s\n",stack[sp++].c_str());
		}
	}
	return 0;
}