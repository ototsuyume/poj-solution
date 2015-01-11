#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

LL data[20000];

int main(){
    LL a,b,c;
    int n;
    while(cin>>a>>b>>c>>n){
        int x=0,y=0,z=0;
        data[0]=1;
        for(int i=1;i<=n;++i){
            LL xv = data[x]*a, yv = data[y]*b, zv = data[z]*c;
            data[i] = min(xv,min(yv,zv));
            if(data[i]==xv)
                ++x;
            if(data[i]==yv)
                ++y;
            if(data[i]==zv)
                ++z;
        }
        cout<<data[n]<<endl;
    }
    return 0;
}
