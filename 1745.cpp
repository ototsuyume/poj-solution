#include<iostream>
#include<string.h>
using namespace std;

bool dp[10000][100];
int data[10000],n,k;

int mod(int dd,int dv){
    if(dd>=0)return dd%dv;
    return ((-dd/dv+1)*dv+dd)%dv;
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>data[i];
    memset(dp,0,sizeof(dp));
    dp[0][mod(data[0],k)] = true;
    for(int i=1;i<n;++i){
        for(int j=0;j<k;++j){
            if(dp[i-1][j]){
                int tmp = mod(j+data[i],k);
                dp[i][tmp] = true;
                tmp = mod(j-data[i],k);
                dp[i][tmp] = true;
            }
        }
    }
    if(dp[n-1][0])
        cout<<"Divisible"<<endl;
    else
        cout<<"Not divisible"<<endl;
    return 0;
}

