#include<iostream>
#include<string.h>

using namespace std;

bool g[510][510],used[510];
int result[510],n,m;

bool augument(int x){
    for(int i=0;i<n;++i){
        if(!g[x][i]||used[i])continue;
        used[i]=true;
        if(result[i]==-1||augument(result[i])){
            result[i]=x;
            return true;
        }
    }
    return false;
}

int solve(){
    int ans=0;
    memset(result,-1,sizeof(result));
    for(int i=0;i<n;++i){
        memset(used,0,sizeof(used));
        if(augument(i))
            ++ans;
    }
    return ans;
}

int main(){
    while(cin>>n>>m){
        memset(g,0,sizeof(g));
        for(int i=0;i<m;++i){
            int x,y;
            cin>>x>>y;
            g[x-1][y-1]=true;
        }
        cout<<solve()<<endl;
    }
    return 0;
}
