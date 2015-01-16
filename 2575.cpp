#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;

bool used[3010];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int last,cur;
        memset(used,0,n);
        scanf("%d",&last);
        for(int i=1;i<n;++i){
            scanf("%d",&cur);
            int v = abs(cur-last);
            if(v<=n-1)used[v]=true;
            last = cur;
        }

        bool ans = true;
        for(int i=1;i<n;++i)
            if(!used[i]){
                ans = false;
                break;
            }
        printf("%s\n",ans?"Jolly":"Not jolly");
    }
    return 0;
}
