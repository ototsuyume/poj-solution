#include<stdio.h>
#include<string.h>


int n,r;
int graph[26][26],g[26][26],res[26];
bool visited[26];

int solve(){
    int pos=0,ret=0;
    memset(visited,0,sizeof(visited));
    memcpy(g,graph,sizeof(graph));
    while(pos<n){
        int tmp[26]={0},tpos=0;
        for(int i=0;i<n;++i){
            if(visited[i])continue;
            int indegree=0;
            for(int j=0;j<n;++j){
                if(j==i)continue;
                else if(g[j][i]){
                    ++indegree;
                    break;
                }
            }
            if(indegree==0){
                //printf("find  %d %d\n",tmp,i);
                tmp[tpos++]=i;
                if(tpos>1)
                    ret=-1;
            }
        }
        if(tpos==0)return 1;
        for(int j=0;j<tpos;++j){
            int t=tmp[j];
            res[pos++]=t;
            visited[t]=true;
            for(int i=0;i<n;++i){
                g[t][i] = 0;
            }
        }
    }
    return ret;
}
int main(){
    while(scanf("%d %d",&n,&r)!=EOF){
        if(n==0&&r==0)break;
        memset(graph,0,sizeof(graph));
        getchar();
        bool ans = false;
        for(int i=0;i<r;++i){
            char s[12];
            scanf("%s",s);
            if(ans)continue;
            graph[s[0]-'A'][s[2]-'A']=1;
            //printf("round:%d\n",i);
            int ret = solve();
            if(ret==0){
                printf("Sorted sequence determined after %d relations: ",i+1);
                for(int i=0;i<n;++i){
                    putchar('A'+res[i]);
                }
                printf(".\n");
                ans=true;
            }
            else if(ret==1){
                printf("Inconsistency found after %d relations.\n",i+1);
                ans=true;
            }
        }
        if(!ans)
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
