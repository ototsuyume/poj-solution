#include<iostream>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;

int diff[1100],dp[2][16000],n;
const int mid=8000,inf=1<<29;

int main(){
    while(cin>>n){
        int upsum=0,downsum=0;
        for(int i=0;i<n;++i){
            int u,d;
            cin>>u>>d;
            upsum+=u,downsum+=d;
            diff[i]=d-u;
        }
        int sum = upsum-downsum,ansval=inf,ans=inf,cur=0,pre=1;
        if(sum==0||n<=1){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<(n+1)*6;++i)
            dp[1][mid-i]=inf,dp[1][mid+i]=inf;
        dp[1][mid]=0;
        for(int i=0;i<n;++i){
            int v = diff[i];
            for(int j=1;j<(n+1)*6;++j){
                int pos = mid+j;
                dp[cur][pos] = min(dp[pre][pos],dp[pre][pos-v]+1);
                pos = mid-j;
                dp[cur][pos] = min(dp[pre][pos],dp[pre][pos-v]+1);
            }
            swap(cur,pre);
        }
        for(int i=1;i<(n+1)*6;++i){
            if(dp[pre][mid-i]<inf){
                int v = abs(sum-i*2);
                if(ansval==v)
                    ans = min(ans,dp[pre][mid-i]);
                else if(ansval>v)
                    ans = dp[pre][mid-i], ansval = v;
            }
            if(dp[pre][mid+i]<inf){
                int v = abs(sum+i*2);
                if(ansval==v)
                    ans = min(ans,dp[pre][mid+i]);
                else if(ansval>v)
                    ans = dp[pre][mid+i], ansval = v;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
