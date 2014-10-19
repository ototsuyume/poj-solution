#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;
#define  MAX_INT   0x7fffffff;
int flow[375][375];
int path[375],s,t;

bool bfs(){
    bool visited[375]={false};
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front();q.pop();
        for(int i=1;i<375;++i){
            if(!visited[i]&&flow[cur][i]>0){
                path[i] = cur;
                if(i==374)
                    return true;
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}


bool solve(int target){
    int ans=0;
    while(bfs()){
        int cur = MAX_INT;
        for(int i=374;i!=0;i=path[i]){
            cur = min(cur,flow[path[i]][i]);
        }
        if(cur==0)break;
        for(int i=374;i!=0;i=path[i]){
            flow[path[i]][i]-=cur;
            flow[i][path[i]]+=cur;
        }
        ans+=cur;
    }
    return ans==target;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int fc=0,total=0;
        memset(flow,0,sizeof(flow));
        scanf("%d",&fc);
        for(int j=1;j<=fc;++j){
            int days[7],d,w;
            scanf("%d%d%d%d%d%d%d%d%d",&days[0],&days[1],&days[2],&days[3],&days[4],&days[5],&days[6],&d,&w);
            total += d;
            flow[0][j] = d;
            for(int k=0;k<7;++k){
                if(days[k]){
                    for(int l=0;l<w;++l){
                        int cur = fc+l*7+k+1;
                        flow[j][cur] = 1;
                        flow[cur][374] = 1;
                    }
                }
            }
        }
        printf("%s\n",solve(total)?"Yes":"No");
    }
    return 0;
}



