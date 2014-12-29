#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

int data[101][101],dp[101],n;


int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&data[i][j]);
        int ans=0;
        for(int left = 0;left<n;++left){
            memset(dp,0,sizeof(dp));
            for(int right=left;right<n;++right){
                for(int i=0;i<n;++i)
                    dp[i]+=data[i][right];
                int cur = dp[0];
                ans = max(ans,cur);
                for(int i=1;i<n;++i){
                    cur = max(cur+dp[i],dp[i]);
                    ans = max(cur,ans);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
