#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

const int MAX_INT=10001;

struct edge{
    int s,e,t;
    edge(){};
    edge(int ss,int ee,int tt):s(ss),e(ee),t(tt){};
};

int dist[1010],n,m,w;
edge ed[5500];


int main(){
    int f;
    scanf("%d",&f);
    while(f-- > 0){
        scanf("%d %d %d",&n,&m,&w);
        for(int i=0;i<m;++i){
            int s,e,t;
            scanf("%d %d %d",&s,&e,&t);
            ed[i*2] = edge(s-1,e-1,t);
            ed[i*2+1] = edge(e-1,s-1,t);
        }

        for(int i=0;i<w;++i){
            int s,e,t;
            scanf("%d %d %d",&s,&e,&t);
            ed[m*2+i] = edge(s-1,e-1,-t);
        }
        for(int i=1;i<n;++i)
            dist[i] = MAX_INT;
        dist[0]=0;
        bool ans = false;
        for(int i=0;i<n;++i){
            for(int j=0;j<m*2+w;++j){
                if(dist[ed[j].e]>dist[ed[j].s]+ed[j].t){
                    dist[ed[j].e] = dist[ed[j].s]+ed[j].t;
                    if(i==n-1){
                        ans = true;
                        break;
                    }
                }
            }
        }
        printf("%s\n",ans?"YES":"NO");

    }
    return 0;
}
