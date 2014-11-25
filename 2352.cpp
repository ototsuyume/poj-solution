#include<cstdio>
#include<string.h>
using namespace std;

const int MAXN = 32010;
int tree[MAXN<<3],ans[MAXN];

int search(int i,int x,int l=0,int r=MAXN){
    tree[i]++;
    if(x==r)return tree[i]-1;
    int mid = (l+r)/2;
    if(mid>=x)return search(i*2+1,x,l,mid);
    else return tree[i*2+1]+search(i*2+2,x,mid+1,r);
}


int main(){
    int n,x,y;
    while(scanf("%d",&n)!=EOF){
        memset(tree,0,sizeof(tree));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;++i){
            scanf("%d %d",&x,&y);
            ans[search(0,x)]++;
        }
        for(int i=0;i<n;++i)
            printf("%d\n",ans[i]);
    }
    return 0;
}
