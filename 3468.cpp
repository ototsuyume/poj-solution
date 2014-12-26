#include<algorithm>
#include<cstdio>
using namespace std;

struct node{
    long long l,r,pval,sum;
};

node tree[500000];
int n,q;

void add(long long cur,long long l,long long r,long long v){
    if(tree[cur].l>=l&&tree[cur].r<=r){
        tree[cur].pval += v;
        tree[cur].sum += ((tree[cur].r-tree[cur].l+1)*v);
    }else if((tree[cur].l<=l&&l<=tree[cur].r)||(tree[cur].r>=r&&r>=tree[cur].l)){
        tree[cur].sum += (long long)((min(tree[cur].r,r)-max(l,tree[cur].l)+1)*v);
        add(cur*2+1,l,r,v);
        add(cur*2+2,l,r,v);
    }
}

long long get(long long cur,long long l,long long r){
   if(tree[cur].l>=l&&tree[cur].r<=r)
        return tree[cur].sum;
    else if((tree[cur].l<=l&&l<=tree[cur].r)||(tree[cur].r>=r&&r>=tree[cur].l)){
        if(tree[cur].pval!=0&&tree[cur].l<tree[cur].r){
            add(cur*2+1,tree[cur*2+1].l,tree[cur*2+1].r,tree[cur].pval);
            add(cur*2+2,tree[cur*2+2].l,tree[cur*2+2].r,tree[cur].pval);
            tree[cur].pval=0;
        }
        return get(cur*2+1,l,r)+get(cur*2+2,l,r);
    }
    else
        return 0;
}


void init(long long cur,long long l,long long r){
    if(r<l)return;
    tree[cur].l = l,tree[cur].r = r, tree[cur].sum = 0, tree[cur].pval=0;
    if(l==r)return;
    long long mid = l+(r-l)/2;
    init(cur*2+1,l,mid);
    init(cur*2+2,mid+1,r);
}


int main(){
    while(scanf("%d%d",&n,&q)!=EOF){
        init(0,1,n);
        long long l,r,v;
        for(int i=1;i<=n;++i){
            scanf("%I64d",&v);
            add(0,i,i,v);
        }
        char buf[16];
        for(int i=0;i<q;++i){
            scanf("%s",buf);
            if(buf[0]=='Q'){
                scanf("%I64d %I64d",&l,&r);
                printf("%I64d\n",get(0,l,r));
            }
            else{
                scanf("%I64d %I64d %I64d",&l,&r,&v);
                add(0,l,r,v);
            }
        }
    }
    return 0;
}
