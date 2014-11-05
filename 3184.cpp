#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int num[10],n,s;

int sum(){
    int data[2][10],p1=0,p2=1;
    memcpy(data[0],num,sizeof(num));
    for(int i=1;i<n;++i){
        for(int j=0;j<n-i;++j)
            data[p2][j]=data[p1][j]+data[p1][j+1];
        swap(p1,p2);
    }
    return data[p1][0];
}

int main(){
    while(cin>>n>>s){
        for(int i=0;i<n;++i)
            num[i]=i+1;
        while(sum()!=s)
            next_permutation(num,num+n);
        for(int i=0;i<n;++i){
            cout<<num[i];
            if(n-1>i)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
