#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int n,m,newn=0,cur=1,top=0,total=0;
vector<int> rel[10010],newrel[10010];
int compressed[10010]={0},compcount[10010]={0},outdegree[10010]={0},dfn[10010]={0},low[10010]={0},stack[10010];
bool instack[10010] = { false }, visited[10010] = { false };

void tarjan(int x)
{
    dfn[x] = low[x] = cur++;
    instack[x]=true;
    stack[top++]=x;
    for(int i=0;i<rel[x].size();++i)
    {
        int next = rel[x][i];
        if(!dfn[next])
        {
            tarjan(next);
            low[x] = min(low[x],low[next]);
        }
        else if(instack[next])
            low[x] = min(low[x],dfn[next]);
    }

    if(dfn[x]==low[x])
    {
        int j=-1;
        do{
            j = stack[--top];
            instack[j]=false;
            compressed[j]=newn;
            compcount[newn]++;
        }while(j!=x);
        newn++;
    }
}

void buildgraph()
{
    for(int i=0;i<n;++i)
        if(!dfn[i])
            tarjan(i);
    for(int i=0;i<n;++i)
    {
        memset(visited,0,sizeof(visited));
        for(int j=0;j<rel[i].size();++j)
        {
            int x=compressed[rel[i][j]];
            if(!visited[x]&&x!=compressed[i]){
                visited[x]=true;
                ++outdegree[compressed[i]];
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        rel[a-1].push_back(b-1);
    }
    buildgraph();
    int res=0,target=-1;
    for(int i=0;i<newn;++i)
    {
        if(outdegree[i]==0){
            ++res;
            target=i;
        }
    }
    if(res>1)
        printf("0\n");
    else
        printf("%d\n",compcount[target]);
    return 0;
}
