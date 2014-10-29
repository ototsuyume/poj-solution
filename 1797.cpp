#include<iostream>
#include<queue>
using namespace std;

struct node{
    int num,capacity;
    node(int n,int c):num(n),capacity(c){};
};

class cmp{
    public:
        bool operator()(const node &a,const node &b){
            return a.capacity < b.capacity;
        }
};

int visited[1100];
vector<node> graph[1100];
int n,m;


int main(){
    int count=0;
    cin>>count;
    for(int k=0;k<count;++k){
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            graph[i].clear(),visited[i]=0;
        for(int i=0;i<m;++i){
            int a,b,c;
            cin>>a>>b>>c;
            node na(b,c);
            graph[a].push_back(na);
            na.num = a;
            graph[b].push_back(na);
        }

        priority_queue<node,vector<node>,cmp> q;
        node a=node(1,0x7fffffff);
        q.push(a);
        int ans=0;
        visited[1]=true;
        while(!q.empty()){
            node tmp = q.top();q.pop();
            if(tmp.num==n){
                ans = tmp.capacity;
                break;
            }
            for(int i=0;i<graph[tmp.num].size();++i){
                node ni = graph[tmp.num][i];
                int v = min(ni.capacity,tmp.capacity);
                if(visited[ni.num]<v){
                    visited[ni.num] = v;
                    node nn(ni.num,v);
                    q.push(nn);
                }
            }
        }
        if(n==1)ans=0;
        cout<<"Scenario #"<<k+1<<":"<<endl<<ans<<endl<<endl;
    }
    return 0;
}
