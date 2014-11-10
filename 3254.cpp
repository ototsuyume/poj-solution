#include<iostream>
#include<string.h>

using namespace std;
const int MOD = 100000000;
int row[12],dp[12][1000],state[1000];

int init(int n){
    int pos=0;
    for(int i=0;i<(1<<n);++i){
        if(!(i&(i<<1)))
            state[pos++]=i;
    }
    return pos;
}

int main(){
    int m,n;
    while(cin>>m>>n){
        memset(row,0,sizeof(row));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;++i){
            int k;
            for(int j=0;j<n;++j){
                cin>>k;
                row[i] += (k<<j);
            }
        }
        int nState = init(n);
        for(int i=0;i<nState;++i)
            dp[0][i] = ((row[0]&state[i])==state[i])?1:0;

        for(int i=1;i<m;++i){
            for(int j=0;j<nState;++j){
                if((row[i]&state[j])!=state[j])continue;
                for(int k=0;k<nState;++k){
                    if((state[j]&state[k])==0)
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<nState;++i)
            ans=(ans+dp[m-1][i])%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
