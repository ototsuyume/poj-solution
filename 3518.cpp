#include<cstdio>
#include<string.h>
using namespace std;


bool data[1299720];

void init(){
    memset(data,0,sizeof(data));
    data[1]=true;
    for(int i=2;i<sizeof(data);++i){
        if(data[i])continue;
        int p=i+i;
        while(p<sizeof(data))
            data[p]=true,p+=i;
    }
}

inline int getcap(int i){
    if(!data[i])
        return 0;
    int l=i-1,r=i+1;
    while(data[l])--l;
    while(data[r])++r;
    return r-l;
}

int main(){
    init();
    int d;
    while(scanf("%d",&d)!=EOF){
        if(d==0)break;
        printf("%d\n",getcap(d));
    }
    return 0;
}
