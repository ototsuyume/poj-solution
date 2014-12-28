#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

int data[110][2],dp[110][1010];


int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t-- >0){
        scanf("%d",&n);
        memset(dp,0xff,sizeof(dp));
        int maxb = 0;
        for(int i=0;i<n;++i){
            scanf("%d",&m);
            for(int j=0;j<m;++j){
                scanf("%d%d",&data[j][0],&data[j][1]);
                maxb = max(maxb,data[j][0]);
            }
            if(i==0){
                for(int j=0;j<m;++j)
                    dp[0][data[j][0]] = data[j][1];
                continue;
            }

            for(int j=0;j<=maxb;++j){
                if(dp[i-1][j]!=-1){
                    for(int k=0;k<m;++k){
                        int b = min(j,data[k][0]);
                        if(dp[i][b]==-1)
                            dp[i][b] = dp[i-1][j]+data[k][1];
                        else
                            dp[i][b] = min(dp[i][b],dp[i-1][j]+data[k][1]);
                    }
                }
            }
        }
        double ans=0;
        for(int i=0;i<=maxb;++i){
            if(dp[n-1][i]!=-1)
                ans = max(ans,1.0*i/dp[n-1][i]);
        }
        printf("%.03f\n",ans+0.0005);
        printf("%.03f\n",ans);//+0.0005);
    }
    return 0;
}
