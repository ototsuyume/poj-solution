#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

bool visited[100005];
int n,k;

int main(){
    while(cin>>n>>k){
        if(k<=n){
            cout<<n-k<<endl;
            continue;
        }

        memset(visited,0,sizeof(visited));
        queue<int> q;
        int q1=1,q2=0,ans=0;
        q.push(n);
        while(!q.empty()){
            int v = q.front();q.pop();
            if(v==k)
                break;
            if(v-1>0&&!visited[v-1]){
                q.push(v-1);
                visited[v-1]=true;
                ++q2;
            }
            if(v+1<=k&&!visited[v+1]){
                q.push(v+1);
                visited[v+1]=true;
                ++q2;
            }
            if(v*2<100005&&!visited[v*2]){
                q.push(v*2);
                visited[v*2]=true;
                ++q2;
            }
            --q1;
            if(q1==0){
                swap(q1,q2);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
