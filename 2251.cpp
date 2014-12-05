#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
struct Point{
    int x,y,z;
    Point(int xx,int yy,int zz):x(xx),y(yy),z(zz){};
};

char maze[30][30][35];
bool used[30][30][30];
int l,r,c;

int bfs(int x,int y,int z){
    static const int move[6][3] = {1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};
    memset(used,0,sizeof(used));
    queue<Point> q;
    int q1 = 1,q2 = 0,ans = 0;
    q.push(Point(x,y,z));
    used[x][y][z]=true;
    while(!q.empty()){
        Point &p = q.front();q.pop();
        --q1;
        int x=p.x,y=p.y,z=p.z;
        for(int i=0;i<6;++i){
            int nx = x+move[i][0], ny = y+move[i][1], nz = z+move[i][2];
            if(nx>=l||ny>=r||nz>=c||nx<0||ny<0||nz<0||used[nx][ny][nz]||maze[nx][ny][nz]=='#')continue;
            if(maze[nx][ny][nz]=='E')
                return ans+1;
            q.push(Point(nx,ny,nz));
            used[nx][ny][nz] = true;
            q2++;
        }
        if(q1==0){
            swap(q1,q2);
            ++ans;
        }
    }

    return -1;
}

int main(){
    char buf[128];
    while(cin>>l>>r>>c){
        if(l==0)break;
        cin.getline(buf,sizeof(buf));
        for(int i=0;i<l;++i){
            for(int j=0;j<r;++j){
                cin.getline(maze[i][j],sizeof(maze[i][j]));
            }
            cin.getline(buf,sizeof(buf));
        }
        int si,sj,sk;
        for(int i=0;i<l;++i)
            for(int j=0;j<r;++j)
                for(int k=0;k<c;++k)
                    if(maze[i][j][k]=='S'){
                        si=i,sj=j,sk=k;
                        break;
                    }
        int ans = bfs(si,sj,sk);
        if(ans<0)
            cout<<"Trapped!"<<endl;
        else
            cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
    }
    return 0;
}
