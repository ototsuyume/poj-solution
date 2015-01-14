#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

int m[21][21],n,ans;
bool state[21];

void dfs(int t,int data){
    int cur=data;
    state[t] = true;
    for(int i=0;i<n;++i)
        if(!state[i])
            cur+=m[t][i];
        else
            cur-=m[t][i];
    ans = max(ans,cur);
    if(cur>data){
        for(int i=t+1;i<n;++i){
            dfs(i,cur);
            state[i] = false;
        }
    }
}

int main(){
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&m[i][j]);
        ans = 0;
        memset(state,0,sizeof(state));
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
