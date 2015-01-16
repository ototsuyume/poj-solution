#include<cstdio>
#include<algorithm>

using namespace std;

const int MIN_VAL = 0x80000000;

int back[100010],fw[100010],data[100010],n;


int main(){
    while(scanf("%d",&n)!=EOF&&n>0){
        for(int i=0;i<n;++i)
            scanf("%d",&data[i]);
        back[n-1] = data[n-1], fw[0] = data[0];
        int f = data[0], b = data[n-1];
        for(int i=1;i<n;++i){
            f = max(data[i],data[i]+f);
            fw[i] = max(fw[i-1],f);
            b = max(data[n-i-1],data[n-i-1]+b);
            back[n-i-1] = max(back[n-i],b);
        }
        int ans = MIN_VAL;
        for(int i=0;i<n-1;++i)
            ans = max(ans,fw[i]+back[i+1]);
        printf("%d\n",ans);
    }
    return 0;
}


