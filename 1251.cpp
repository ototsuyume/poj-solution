#include<iostream>
#include<algorithm>
using namespace std;

int set[27];

struct edge{
    int v,x,y;
    edge(){};
    edge(int xx,int yy,int vv):x(xx),y(yy),v(vv){};
};

edge e[1000];

int find(int i){
    if(set[i]==i)
        return i;
    set[i] = find(set[i]);
    return set[i];
}

bool merge(int i,int j){
    int pi = find(i), pj = find(j);
    set[pi] = set[pj] = pi;
    if(pi==pj)return true;
    else return false;
}

bool cmp(const edge &a, const edge &b){
    return a.v < b.v;
}

int main(){
    int n;
    while(cin>>n && n>0){
        int ec = 0;
        for(int i=0;i<n-1;++i){
            char s,t;
            int k,v;
            cin>>s>>k;
            for(int j=0;j<k;++j){
                cin>>t>>v;
                e[ec++] = edge(s-'A',t-'A',v);
            }
            set[i]=i;
        }
        set[n-1] = n-1;
        sort(e,e+ec,cmp);
        int ans = 0;
        for(int i=0;i<ec;++i){
            if(!merge(e[i].x,e[i].y))
                ans+=e[i].v;
        }
        cout<<ans<<endl;
    }
    return 0;
}
