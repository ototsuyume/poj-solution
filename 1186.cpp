#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
const int MAX_SIZE = 10000000;
int vhash[MAX_SIZE],chash[MAX_SIZE],k[6],p[6],n,m,ans;

int find(int val){
    int pos = val%MAX_SIZE;
    if(pos<0)pos=-pos;
    for(int i=0;i<MAX_SIZE;++i,++pos){
        if(pos>=MAX_SIZE)
            pos%=MAX_SIZE;
        if(chash[pos]>0&&vhash[pos]==val)
            return chash[pos];
        else if(chash[pos]==0)
            return 0;
    }
    return 0;
}

void insert(int val){
    int pos = val%MAX_SIZE;
    if(pos<0)pos=-pos;
    for(int i=0;i<MAX_SIZE;++i,++pos){
        if(pos>=MAX_SIZE)
            pos%=MAX_SIZE;
        if(chash[pos]==0||vhash[pos]==val){
            vhash[pos]=val,chash[pos]++;
            return;
        }
    }
}


void calleft(int val,int cur,int end){
    if(cur==end){
        insert(val);
        return;
    }
    for(int i=1;i<=m;++i){
        int tmp = val+pow(double(i),p[cur])*k[cur];
        calleft(tmp,cur+1,end);
    }
}

void calright(int val,int cur,int end){
    if(cur>=end){
        ans+=find(-val);
        return;
    }

    for(int i=1;i<=m;++i){
        int tmp = val+pow(double(i),p[cur])*k[cur];
        calright(tmp,cur+1,end);
    }
}


int main(){
    while(cin>>n){
        cin>>m;
        for(int i=0;i<n;++i)
            cin>>k[i]>>p[i];
        ans = 0;
        memset(vhash,0,sizeof(vhash));
        memset(chash,0,sizeof(chash));
        calleft(0,0,n/2);
        calright(0,n/2,n);
        cout<<ans<<endl;
    }
    return 0;
}

