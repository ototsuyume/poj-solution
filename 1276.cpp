#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

bool f[2][100010]={false};

int main(){
    int n,c,nk[20],bills[20];
    while(scanf("%d %d",&n,&c)!=EOF){
        for(int i=0;i<c;++i)
            scanf("%d %d",&nk[i],&bills[i]);
        memset(f,0,sizeof(f));
        bool *cur = f[1], *last = f[0];
        last[0]=true;
        for(int j=0;j<c;++j){
            memcpy(cur,last,n+1);
            for(int i=0;i<=n;++i){
                if(!last[i])continue;
                for(int k=0,p=i+bills[j];k<nk[j]&&p<=n;++k,p+=bills[j])
                {
                    cur[p] = true;
                }
            }
            swap(last,cur);
        }
        int ans = n;
        for(;ans>0&&!last[ans];--ans);
        printf("%d\n",ans);
    }
    return 0;
}
