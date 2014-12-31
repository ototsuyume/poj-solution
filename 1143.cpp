#include<cstdio>
#include<string.h>

using namespace std;

int dp[0x1fffff+10],ans[21];

int getnext(int state,int num){
    int old = state;
    for(int i=1;i*num<=20;++i){
        state&=(~(1<<i*num));
        for(int j=2;(j+i*num)<=20;++j)
            if((old&(1<<j))==0)
                state&=(~(1<<(j+i*num)));
    }
    return state;
}

bool dfs(int state){
    if(dp[state]!=0)
        return dp[state]==1;
    for(int i=2;i<=20;++i){
        if(state&(1<<i)){
            int next = getnext(state,i);
            if(dfs(next)){
                dp[state] = -1;
                return false;
            }
        }
    }
    dp[state]=1;
    return true;
}

int main(){
    int n,tmp,seq=1;
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    while(scanf("%d",&n)!=EOF&&n){
        int state = 0;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            state|=(1<<tmp);
        }
        int len = 0;
        for(int i=2;i<=20;++i){
            if(state&(1<<i)){
                int next = getnext(state,i);
                    //printf("aaaaaaaaaaa %d\n",next);
                if(dfs(next))
                    ans[len++]=i;
            }
        }
        printf("Test Case #%d\n",seq++);
        if(len==0)
            printf("There's no winning move.\n\n");
        else{
            printf("The winning moves are:");
            for(int i=0;i<len;++i)
                printf(" %d",ans[i]);
            printf("\n\n");
        }
    }
    return 0;
}
