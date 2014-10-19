#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int d[10],n;
    while(scanf("%d",&n)&&n!=0){
        getchar();
        for(int i=0;i<n;++i)
            scanf("%d",&d[i]);
        getchar();
        if(n&1){
            printf("1\n");
            continue;
        }
        sort(d,d+n);
        bool win=true;
        for(int i=0;i<n;i+=2)
            if(d[i]!=d[i+1]){
                win=false;
                break;
            }
        printf("%d\n",win?0:1);
    }
    return 0;
}
