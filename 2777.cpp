#include<stdio.h>
#include<algorithm>

using namespace std;

struct node{
    int c,l,r;
};

node tree[500000];

void build(int p,int l,int r){
    if(l>r)return;
    tree[p].l=l,tree[p].r=r,tree[p].c=1;
    if(l==r)return;
    int mid= (l+r)/2;
    build(2*p+1,l,mid);
    build(2*p+2,mid+1,r);
}


int setcolor(int p,int l,int r,int c){
    if(l<=tree[p].l&&r>=tree[p].r){
        tree[p].c = c;
    }
    else if(l>tree[p].r||r<tree[p].l||tree[p].c==c||l>r)
        return tree[p].c;
    else if(tree[p].c>0){
        tree[p*2+1].c = tree[p].c;
        tree[p*2+2].c = tree[p].c;
        tree[p].c=0;
        setcolor(2*p+1,l,r,c);
        setcolor(2*p+2,l,r,c);
    }
    else{
        int sl = setcolor(2*p+1,l,r,c),sr = setcolor(2*p+2,l,r,c);
        if(sl==sr&&sl>0)
            tree[p].c=c;
    }
    return tree[p].c;
}

int getcolor(int p,int l,int r){
    if(tree[p].l>r||tree[p].r<l)
        return 0;
    else if(tree[p].c>0)
        return 1<<(tree[p].c-1);
    int sl = getcolor(p*2+1,l,r),sr=getcolor(p*2+2,l,r);
    return sl|sr;
}

int main(){
    int L,T,O;
    while(scanf("%d %d %d",&L,&T,&O)!=EOF){
        build(0,1,L);
        for(int i=0;i<O;++i){
            char cmd[16];
            scanf("%s",cmd);
            if(cmd[0]=='C'){
                int l,r,c;
                scanf("%d %d %d",&l,&r,&c);
                if(l>r)swap(l,r);
                setcolor(0,l,r,c);
            }
            else{
                int l,r;
                scanf("%d%d",&l,&r);
                if(l>r)swap(l,r);
                int t=getcolor(0,l,r),ans=0;
                for(int i=0;i<T;++i){
                    if(t&1)++ans;
                    t>>=1;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
