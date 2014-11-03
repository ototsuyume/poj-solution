#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

const int INF=0x7fffffff,MAXN=510;

int graph[MAXN][MAXN],dist[MAXN],n;
bool visited[MAXN],reduce[MAXN];


int merge(int &s,int &t){
    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(dist));

    s = t = -1;
    int ret = -1, cur=0;
    for(int i=0;i<n;++i){
        int mx=-1;
        for(int j=0;j<n;++j){
            if(!visited[j]&&!reduce[j]&&dist[j]>mx){
                cur = j,mx = dist[j];
            }
        }

        if(cur==t)
            return ret;
        s = t,t=cur;
        ret = mx;
        visited[t]=true;
        for(int j=0;j<n;++j){
            if(!reduce[j]&&!visited[j]){
                dist[j]+=graph[t][j];
            }
        }
    }
    return ret;
}

int solve(){
    memset(reduce,0,sizeof(reduce));
    int ans=INF;
    for(int i=1;i<n;++i){
        int s,t;
        ans = min(ans,merge(s,t));
        reduce[t]=true;
        for(int j=0;j<n;++j){
            if(!reduce[j]){
                graph[s][j] += graph[t][j];
                graph[j][s] += graph[j][t];
            }
        }
    }
    return ans;
}

int main(){
    int e;
    while(scanf("%d%d",&n,&e)!=EOF){
        memset(graph,0,sizeof(graph));
        for(int i=0;i<e;++i){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            graph[a][b]+=c;
            graph[b][a]+=c;
        }
        printf("%d\n",solve());
    }
    return 0;
}
