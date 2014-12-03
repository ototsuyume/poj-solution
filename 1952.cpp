#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

int data[5010],dp[5010],times[5010];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i)
            scanf("%d",&data[i]);
        dp[0]=times[0]=1;
        for(int i=1;i<n;++i){
            int best=0,c=1;
            for(int j=0;j<i;++j){
                if(data[j]>data[i]){
                    if(best<dp[j])
                        best = dp[j],c= times[j];
                    else if(best==dp[j])
                        c+=times[j];
                }else if(data[j]==data[i]){
                    best = 0,c = 0;
                }
            }
            dp[i]=best+1,times[i] = c;
        }

        int ans=0,count=0;
        for(int i=0;i<n;++i){
            //printf("%d ",dp[i]);
            if(dp[i]>ans)
                ans = dp[i], count=times[i];
            else if(dp[i]==ans)
                count+=times[i];
        }
        /*
        printf("\n");
        for(int i=0;i<n;++i)
            printf("%d ",times[i]);
        */
        printf("%d %d\n",ans,count);
    }
    return 0;
}
