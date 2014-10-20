#include<cstdio>
#include<algorithm>
#include<string.h>

using namespace std;

int data[110][110],dp[110][110],m,n;
int step[4][2]={1,0,0,1,0,-1,-1,0};

int dfs(int x,int y){
    if(dp[x][y]>0)
        return dp[x][y];
    int ans=1;
    for(int i=0;i<4;++i){
        int nx = x+step[i][0], ny = y+step[i][1];
        if(nx>=m||nx<0||ny>=n||ny<0||data[nx][ny]<=data[x][y])continue;
        ans = max(ans,dfs(nx,ny)+1);
    }
    dp[x][y] = ans;
    return ans;
}

int main(){
    while(scanf("%d%d",&m,&n)!=EOF){
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&data[i][j]),dp[i][j]=0;
        int ans=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(dp[i][j]>0)continue;
                bool valley = true;
                for(int k=0;k<4;++k){
                    int nx = i+step[k][0], ny = j+step[k][1];
                    if(nx>=m||nx<0||ny>=n||ny<0)continue;
                    if(data[nx][ny]<data[i][j]){
                        valley = false;break;
                    }
                }
                if(valley)
                    ans = max(ans,dfs(i,j));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
