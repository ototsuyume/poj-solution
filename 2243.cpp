#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

bool board[8][8];
struct point{
    int x,y;
};

int solve(int sx,int sy,int ex,int ey){
    static int move[8][2]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2};
    if(sx==ex&&ey==sy)
        return 0;
    memset(board,0,sizeof(board));
    queue<point> q;
    point p = {sx,sy};
    int ans=0,q1=1,q2=0;
    q.push(p);
    while(!q.empty()){
        point p = q.front();q.pop();
        --q1;
        for(int i=0;i<8;++i){
            int x = p.x+move[i][0], y = p.y+move[i][1];
            if(x<0||y<0||x>7||y>7||board[x][y])continue;
            board[x][y]=true;
            if(x==ex&&y==ey)
                return ans+1;
            point np = {x,y};
            q.push(np),++q2;
        }
        if(q1==0){
            q1=q2,q2=0,++ans;
        }
    }
    return -1;
}

int main(){
    char src[3],dest[3];
    while(cin>>src>>dest){
        int sx=src[0]-'a',sy=src[1]-'1',ex=dest[0]-'a',ey=dest[1]-'1';
        cout<<"To get from "<<src<<" to "<<dest<<" takes "<<solve(sx,sy,ex,ey)<<" knight moves."<<endl;
    }
    return 0;
}
