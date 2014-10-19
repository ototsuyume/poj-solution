#include<iostream>
#include<string.h>

using namespace std;

const int max_n = 50;

struct point{
    int x,y;
};

point result[max_n][max_n];

bool chess[max_n][max_n],used[max_n][max_n];

int m,n,k;

bool augument(int x,int y){
    static int move[4][2]={-1,0,1,0,0,-1,0,1};

    for(int i=0;i<4;++i){
        int nx = x+move[i][0], ny = y+move[i][1];
        if(nx<0||nx>=m||ny<0||ny>=n||used[nx][ny]||chess[nx][ny])
            continue;
        used[nx][ny] = true;
        point &t = result[nx][ny];
        if(t.x==-1||augument(t.x,t.y)){
            t.x = x, t.y = y;
            return true;
        }
    }
    return false;
}

bool solve(){
    int ans=0;
    memset(result,-1,sizeof(result));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(chess[i][j]||(i+j)&1)
                continue;
            memset(used,0,sizeof(used));
            if(augument(i,j))
                ++ans;
        }
    }
    return ans*2+k==m*n;
}

int main(){
    while(cin>>m>>n>>k){
        memset(chess,0,sizeof(chess));
        for(int i=0;i<k;++i){
            int x,y;
            cin>>y>>x;
            chess[x-1][y-1]=true;
        }

        if((m*n-k)&1||!solve())
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
