#include<cstdio>
#include<string.h>
using namespace std;

double graph[110][110];
double dp[110];

int stack[200],sp=0;

int main(){
    int n,m;
    scanf("%d",&n);
    while(scanf("%d",&m)!=EOF){
        memset(graph,0,sizeof(graph));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;++i){
            int a,b;double p;
            scanf("%d%d%lf",&a,&b,&p);
            graph[a][b] = graph[b][a] = p;
        }
        stack[0]=1;
        sp = 1;
        dp[1]=100.0;
        while(sp>0){
            int cur = stack[--sp];
            for(int i=1;i<=n;++i){
                if(graph[cur][i]==0)continue;
                double k = dp[cur]*graph[cur][i]/100.0;
                if(k>dp[i]){
                    dp[i] = k;
                    stack[sp++] = i;
                }
            }
        }
        printf("%.06lf percent\n",dp[n]);
        scanf("%d",&n);
    }
    return 0;
}
