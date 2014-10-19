#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;


char maze[60][61],visited[60][61];
struct edge{
    int v1,v2,val;
    edge(){};
    edge(int vv1,int vv2,int len):v1(vv1),v2(vv2),val(len){};
};
edge e[110*110];
bool used[110][110];
int m,n,le,lc,set[110];

void bfs(int sx,int sy){
    memset(visited,0,sizeof(visited));
    visited[sx][sy]=1;
    static int move[4][2]={0,1,0,-1,-1,0,1,0};
    int ans=0,q1=1,q2=0;
    queue<int> qx,qy;
    qx.push(sx),qy.push(sy);
    while(!qx.empty()){
        int x=qx.front(),y=qy.front();
        qx.pop(),qy.pop(),--q1;
        for(int i=0;i<4;++i){
            int nx=x+move[i][0],ny=y+move[i][1];
            if(nx<0||ny<0||nx>=m||ny>=n||visited[nx][ny]||maze[nx][ny]==-1)continue;
            int s1=maze[sx][sy],s2=maze[nx][ny];
            if(maze[nx][ny]>0&&!used[s1][s2]){
                e[le++]=edge(s1,s2,ans+1);
                used[s1][s2]=used[s2][s1]=true;
            }
            visited[nx][ny]=1;
            qx.push(nx),qy.push(ny),++q2;
        }
        if(q1==0)
            q1=q2,q2=0,ans++;
    }
}

bool cmp(const edge &a, const edge &b){
    return a.val<b.val;
}

int find(int x){
    if(set[x]==x)return x;
    set[x] = find(set[x]);
    return set[x];
}

bool merge(int x,int y){
    int px=find(x),py=find(y);
    set[px]=py;
    return px==py;
}

int solve(){
    memset(used,0,sizeof(used));
    le=0,lc=1;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(maze[i][j]=='A'||maze[i][j]=='S')
                set[lc]=lc,maze[i][j]=lc++;
            else if(maze[i][j]=='#')
                maze[i][j]=-1;
            else
                maze[i][j]=0;
        }
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(maze[i][j]>0)
                bfs(i,j);
        }
    }
    sort(e,e+le,cmp);
    int ans=0;
    for(int i=0;i<le;++i){
        if(!merge(e[i].v1,e[i].v2))
            ans+=e[i].val;
    }
    return ans;
}


int main(){
    int c;
    char tmp[128];
    cin>>c;
    for(int i=0;i<c;++i){
        cin>>n>>m;
        cin.getline(tmp,128);
        for(int j=0;j<m;++j)
            cin.getline(maze[j],61);
        cout<<solve()<<endl;
    }
    return 0;
}
