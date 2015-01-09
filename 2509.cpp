#include<cstdio>

using namespace std;

int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF){
        int ans = n;
        do{
            ans += n/k;
            n = n/k+n%k;
        }while(n>=k);
        printf("%d\n",ans);
    }
    return 0;
}
