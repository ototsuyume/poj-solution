#include<stdio.h>
#include<algorithm>

using namespace std;

struct edge{
    int val,v1,v2;
};

edge e[250*510];
int g[510][510],n,uf[510];

bool cmp(const edge &a,const edge &b){
    return a.val<b.val;
}

int find(int a){
    if(uf[a]==a)return a;
    int b = find(uf[a]);
    uf[a]=b;
    return b;
}

bool merge(int a,int b){
    int pa=find(a),pb=find(b);
    if(pa==pb)return false;
    uf[pa]=pb;
    return true;
}


int main(){
    int m;
    scanf("%d",&m);
    for(int c=0;c<m;++c){
        scanf("%d",&n);
        int pos=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d",&g[i][j]);
                if(j>i){
                    e[pos].val = g[i][j];
                    e[pos].v1 = i;
                    e[pos++].v2 = j;
                }
            }
            uf[i]=i;
        }
        sort(e,e+pos,cmp);
        int ans=0;
        for(int i=0;i<pos;++i)
            if(merge(e[i].v1,e[i].v2))
                ans=max(ans,e[i].val);
        printf("%d\n",ans);
    }
    return 0;
}

