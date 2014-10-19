#include<iostream>

using namespace std;

bool prime[1000001]={false};

void init(){
    for(int i=2;i<=500000;++i){
        if(prime[i])continue;
        int j=i+i;
        while(j<=1000000){
            prime[j]=true;
            j+=i;
        }
    }
    prime[1]=true;
}

int main(){
    int a,d,n;
    init();
    while(cin>>a>>d>>n){
        if(a==0||d==0||n==0)break;
        int c=0,v=a;
        while(v<1000000&&c<n){
            if(!prime[v]){
                ++c;
            }
            v+=d;
        }
        if(c==n)
            cout<<v-d<<endl;
    }
    return 0;
}
