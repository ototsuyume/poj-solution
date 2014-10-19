#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int input[20],n,t,ans[20];
bool used[20],isfind=false;

void dfs(int target,int pos,int size){
    if(target==0){
        printf("%d",ans[0]);
        for(int i=1;i<size;++i)
            printf("+%d",ans[i]);
        printf("\n");
        isfind=true;
        return;
    }
    if(target<0)return;
    for(int i=pos;i<n;++i){
        if(i>0&&!used[i-1]&&input[i]==input[i-1])continue;
        ans[size] = input[i];
        used[i]=true;
        dfs(target-input[i],i+1,size+1);
        used[i]=false;
    }
}

bool cmp(int a,int b){
    return a>b;
}

int main(){
    while(scanf("%d %d",&t,&n),n>0){
        for(int i=0;i<n;++i)
            scanf("%d",&input[i]);
        memset(used,0,sizeof(used));
        sort(input,input+n,cmp);
        printf("Sums of %d:\n",t);
        isfind=false;
        dfs(t,0,0);
        if(!isfind)
            printf("NONE\n");
    }
    return 0;
}
