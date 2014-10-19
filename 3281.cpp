#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

#define ENDPOINT  999
#define STARTPOINT 998


int graph[1000][1000],n,f,d;
int path[1000];
bool visited[1000];

bool bfs(){
    memset(path,0,sizeof(path));
    memset(visited,0,sizeof(visited));
    queue<int> q;
    path[STARTPOINT]=-1;
    q.push(STARTPOINT);
    visited[STARTPOINT]=true;
    while(!q.empty()){
        int pos = q.front();q.pop();
        for(int i=0;i<1000;++i){
            if(graph[pos][i]&&!visited[i]){
                //printf("find path from %d to %d\n",pos,i);
                path[i] = pos;
                visited[i] = true;
                if(i==ENDPOINT)return true;
                q.push(i);
            }
        }
    }
    return false;
}

int findflow(){
    int ans = 0;
    while(bfs()){
        int pos = ENDPOINT;
        while(path[pos]!=-1){
            graph[pos][path[pos]]++;
            graph[path[pos]][pos]--;
            pos = path[pos];
        }
        ans++;
    }

    return ans;
}

int main(){
    while(scanf("%d %d %d",&n,&f,&d)!=EOF){
        memset(graph,0,sizeof(graph));
        for(int i=0;i<n;++i){
            int a,b,c,f1=f+i,f2=n+f+i;

            scanf("%d %d",&a,&b);
            graph[f1][f2] = 1;
            for(int j=0;j<a;++j){
                scanf("%d",&c);
                graph[c-1][f1]=1;
            }

            for(int j=0;j<b;++j){
                scanf("%d",&c);
                graph[f2][2*n+f+c-1] = 1;
            }
        }
        for(int i=0;i<f;++i){
            graph[STARTPOINT][i]= 1;
        }

        for(int i=0;i<d;++i){
            graph[2*n+f+i][ENDPOINT] = 1;
        }
        printf("%d\n",findflow());
    }
    return 0;
}
