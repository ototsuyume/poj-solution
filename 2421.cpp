#include<stdio.h>
#include<algorithm>

using namespace std;

int g[110][110],n,m;
int uf[110];

struct edge{
    int val,v1,v2;
};

edge e[5100];

bool cmp(const edge &a,const edge &b){
    return a.val<b.val;
}

int find(int i){
    if(uf[i]==i)
        return i;
    int tmp = find(uf[i]);
    uf[i]=tmp;
    return tmp;
}

bool merge(int a,int b){
    int pa = find(a), pb = find(b);
    if(pa==pb)return false;
    uf[pb]=pa;
    return true;
}


int main(){
    while(scanf("%d",&n)!=EOF){
        int pos=0;
        for(int i=0;i<n;++i){
            uf[i]=i;
            for(int j=0;j<n;++j){
                scanf("%d",&g[i][j]);
                if(i<j){
                    e[pos].val = g[i][j];
                    e[pos].v1 = i;
                    e[pos++].v2 = j;
                }
            }
        }
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            int a,b;
            scanf("%d %d",&a,&b);
            merge(a-1,b-1);
        }
        sort(e,e+pos,cmp);

        int ans=0;
        for(int i=0;i<pos;++i){
            if(merge(e[i].v1,e[i].v2))
                ans+=e[i].val;
        }
        printf("%d\n",ans);

    }
    return 0;
}
