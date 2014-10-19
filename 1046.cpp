#include<stdio.h>
#include<cmath>

using namespace std;
const double INF=9999999.999999;
int r[16],g[16],b[16];


int main(){
    for(int i=0;i<16;++i)
        scanf("%d %d %d",&r[i],&g[i],&b[i]);
    int cr,cg,cb;
    while(scanf("%d %d %d",&cr,&cg,&cb)!=EOF){
        if(cr==-1||cg==-1||cb==-1)break;
        double val=INF;
        int index = -1;
        for(int i=0;i<16;++i){
            double cur = sqrt(double((r[i]-cr)*(r[i]-cr)+(g[i]-cg)*(g[i]-cg)+(b[i]-cb)*(b[i]-cb)));
            if(cur<val){
                val = cur;
                index=i;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",cr,cg,cb,r[index],g[index],b[index]);
    }
    return 0;
}
