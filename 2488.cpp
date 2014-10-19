#include<stdio.h>
#include<string.h>
#include<utility>

using namespace std;

typedef pair<int,int> act;

int board[26][26],p,q;
int direction[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
act path[26*26];

bool dfs(int x,int y,int step){
    if(board[x][y])
        return false;
    if(step==p*q){
        path[step-1].first  = x;
        path[step-1].second = y;
        return true;
    }
    board[x][y]=1;
    for(int i=0;i<8;++i){
        int nx = x+direction[i][0],ny = y+direction[i][1];
        if(nx>=0&&nx<p&&ny>=0&&ny<q&&dfs(nx,ny,step+1)){
            path[step-1].first  = x;
            path[step-1].second = y;
            return true;
        }
    }
    board[x][y]=0;
    return false;
}


int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&p,&q);
        memset(board,0,sizeof(board));
        printf("Scenario #%d:\n",i+1);
        if(dfs(0,0,1)){
            for(int j=0;j<p*q;++j)
                printf("%c%d",path[j].second+'A',path[j].first+1);
            printf("\n\n");
        }
        else
            printf("impossible\n\n");
    }
    return 0;
}
