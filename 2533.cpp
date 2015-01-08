#include<cstdio>
#include<algorithm>
using namespace std;
int data[1010],dp[1010],n;

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i)
            scanf("%d",&data[i]);

        dp[0]=1;
        int ans = 1;
        for(int i=1;i<n;++i){
            int cur = 1;
            for(int j=i-1;j>=0;--j){
                if(data[j]<data[i]&&dp[j]>=cur)
                    cur = dp[j]+1;
            }
            dp[i] = cur;
            ans = max(ans,dp[i]);
        }

        printf("%d\n",ans);
    }
    return 0;
}
