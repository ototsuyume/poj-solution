#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int dp[2][4510];


int main(){
    int m,n;
    while(cin>>m>>n){
        int cur=0,nxt=1;
        memset(dp,0,sizeof(dp));
        dp[0][1]=0;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(i>j) dp[nxt][j] = dp[cur][j];
                else if(i==j) dp[nxt][j]=dp[cur][j]+1;
                else dp[nxt][j] = dp[cur][j]+dp[nxt][j-i];
                if(dp[nxt][j]>=1000000007) dp[nxt][j]-=1000000007;
            }
            swap(cur,nxt);
        }
        cout<<dp[cur][n]<<endl;
    }
    return 0;
}
