#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int sv[9]={0,1,2,6,24,120,720,5040,40320};
bool used[400000]={false};

char dpath[400000],result[400000];
int path[400000];
struct state{
    char data[10];
    char pos;
};

int getstate(const char *str){
    int ans=0;
    for(int i=0;i<9;++i){
        int c = 0;
        for(int j=0;j<i;++j){
            if(str[i]>str[j])
                ++c;
        }
        ans+=c*sv[i];
    }
    return ans;
}

bool findtarget(const char *str){
    const char *target = "123456780";
    return memcmp(str,target,9)==0;
}
int addnext(state &s,queue<state> &q,int &len){
    static char offset[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
    static char dir[4]={'u','d','l','r'};
    int last = getstate(s.data);
    for(int i=0;i<4;++i){
        int x = s.pos%3, y = s.pos/3;
        int nx = x+offset[i][0], ny = y+offset[i][1];
        if(nx<0||ny<0||nx>2||ny>2)
            continue;
        int newpos = ny*3+nx;
        state ns = s;
        swap(ns.data[newpos],ns.data[s.pos]);
        int val = getstate(ns.data);
        if(used[val])
            continue;
        used[val] = true;
        path[val] = last;
        dpath[val] = dir[i];
        ns.pos=newpos;
        if(findtarget(ns.data))
            return val;
        ++len;
        //printf("%s  %s %d %d\n",s.data,ns.data,q.size(),total);
        q.push(ns);
        //printf("q:%d len:%d val:%d\n",q.size(),len,val);
    }
    return -1;
}

void bfs(state &s){
    queue<state> q;
    q.push(s);
    int q1=1;
    int solve=-1;
    while(!q.empty()){
        int q2=0;
        for(int i=0;i<q1;++i){
            state cur = q.front();q.pop();
            solve = addnext(cur,q,q2);
            if(solve!=-1)
               break;
        }
        if(solve!=-1)break;
        q1=q2;
    }

    if(solve!=-1){
        int pos=0;
        while(path[solve]!=-1){
            result[pos++] = dpath[solve];
            solve=path[solve];
        }
        pos--;
        while(pos>=0)
            putchar(result[pos--]);
        putchar('\n');
    }
    else
        printf("unsolvable\n");
}

int main(){
    char tmp[128];
    state s;
    for(int i=0;i<9;++i){
        scanf("%s",tmp);
        if(tmp[0]=='x'){
            tmp[0]='0';
            s.pos = i;
        }
        s.data[i]=tmp[0];
    }
    s.data[9] = 0;
    int v = getstate(s.data);
    used[v]=true;
    path[v]=-1;
    bfs(s);
    return 0;
}
