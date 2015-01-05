#include<cstdio>
using namespace std;

unsigned long data[100000];
int stack[100000];

int n,top;


int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i)
            scanf("%u",&data[i]);
        long long ans=0;
        top = 0;
        for(int i=0;i<n;++i){
            unsigned long d = data[i];
            while(top>0&&data[stack[top-1]]<=d)
                ans+=(long long)(i-stack[--top]-1);
            stack[top++]=i;
        }
        int p = stack[--top];
        --top;
        while(top>=0)
            ans+=(long long)(p-stack[top--]);

        printf("%lld\n",ans);
    }
    return 0;
}
