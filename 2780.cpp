#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
const double INF=99999.9999;
const double EPLISON=0.0001;
int x[2000],y[2000],n;
double slope[2000];
bool cmp(double a,double b){
    if(b-a>EPLISON)return true;
    return false;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i)
            scanf("%d %d",&x[i],&y[i]);
        if(n<=2){
            printf("%d\n",n);
            continue;
        }
        int ans=2;
        for(int i=0;i<n;++i){
            int index=0;
            for(int j=i+1;j<n;++j){
                if(x[i]==x[j])
                    slope[index++]=INF;
                else
                    slope[index++]=double(y[i]-y[j])/double(x[i]-x[j]);
            }
            sort(slope,slope+index,cmp);
            int line=2;
            for(int j=1;j<index;++j){
                if(slope[j]-slope[j-1]<EPLISON)
                    ++line;
                else{
                    ans = max(ans,line);
                    line=2;
                }
            }
            ans=max(ans,line);
        }
        printf("%d\n",ans);
    }
    return 0;
}
