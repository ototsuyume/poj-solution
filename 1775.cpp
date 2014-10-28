#include<iostream>
using namespace std;

int fact[10];

bool data[1000010]={false};

int main(){
    int n,base=1;
    fact[0]=1;
    for(int i=1;i<10;++i){
        base*=i;
        fact[i]=base;
    }
    for(int i=1;i<(1<<10);++i){
        int v=0,tmp = i,pos=0;
        while(tmp){
            if(tmp&1)
                v+=fact[pos];
            tmp>>=1;
            pos++;
        }
        data[v]=true;
    }
    while(cin>>n){
        if(n<0)break;
        if(data[n])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
