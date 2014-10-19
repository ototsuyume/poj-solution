#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;

typedef pair<int,float> node;

int n;
float total;
map<string,float> s2n;
vector<node> graph[20000];
bool visited[20000]={false};


class cmp{
    public:
        bool operator () (node a,node b){
            return a.second > b.second;
        }
};

float solve(){
    float ans = 0.0;
    int count = 1;
    priority_queue<node,vector<node>,cmp>  q;

    visited[0]=true;
    for(int i=0;i<graph[0].size();++i){
        q.push(graph[0][i]);
    }
    while(!q.empty()&&count<n){
        node cur = q.top();
        q.pop();
        int vertex = cur.first;
        float len = cur.second;
        visited[vertex] = true;
        ans+=len;
        ++count;
        for(vector<node>::iterator it=graph[vertex].begin();
                it!=graph[vertex].end();++it){
            if(visited[it->first])continue;
            q.push(*it);
        }
    }
    return n==count?ans:1000000.0;
} 

int main(){

    char src[26],dest[26];
    int  line=0;
    scanf("%f %d",&total,&n);
    for(int i=0;i<n;++i){
        scanf("%s",src);
        s2n[src] = i;
    }
    scanf("%d",&line);
    for(int i=0;i<line;++i){
        float len;
        scanf("%s %s %f",src,dest,&len);
        int sno = s2n[src],dno = s2n[dest];
        graph[sno].push_back(node(dno,len));
        graph[dno].push_back(node(sno,len));
    }
    float ans = solve();
    if(ans>total)
        printf("Not enough cable\n");
    else
        printf("Need %.1f miles of cable\n",ans);
    return 0;
}
