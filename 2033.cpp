#include<iostream>
#include<string.h>
using namespace std;

char s[11000];
int dp[11000];

int main(){
    while(cin>>s){
        if(s[0]=='0')break;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;s[i]!=0;++i){
            if(s[i]=='0'){
                if(s[i-1]==0||s[i-1]>'2')
                    break;
                else
                    dp[i]=i>1?dp[i-2]:1;
            }
            else{
                if(s[i-1]=='0')
                    dp[i]=dp[i-1];
                else{
                    int v=(s[i-1]-'0')*10+s[i]-'0';
                    if(v<=26)
                        dp[i]=(i>1?dp[i-2]:1)+dp[i-1];
                    else
                        dp[i]=dp[i-1];
                }
            }
        }
        cout<<dp[strlen(s)-1]<<endl;
    }
    return 0;
}
