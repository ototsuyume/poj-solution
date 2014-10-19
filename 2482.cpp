#include<stdio.h>
#include<algorithm>

using namespace std;

struct node{
    long long l,r,add,val;
};

struct _star{
    long long x,y,val;
};

_star star[40000];
node tree[40000*8];
long long y[40000*2],ny,n,w,h;

bool cmp(const _star &a,const _star &b){
    if(a.x==b.x)return a.val<b.val;
    return a.x<b.x;
}

void build(long long pos,long long l,long long r){
    tree[pos].l=l;
    tree[pos].r=r;
    tree[pos].val = tree[pos].add = 0;
    if(l==r)return;
    long long mid=(l+r)/2;
    build(pos*2+1,l,mid);
    build(pos*2+2,mid+1,r);
}

long long find(long long t){
    long long l=0,r=ny-1;
    while(l<=r){
        long long mid = (l+r)/2;
        if(y[mid]==t)return mid;
        else if(y[mid]>t) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

long long update(long long pos,long long l,long long r,long long val){
    if(l<=tree[pos].l&&tree[pos].r<=r){
        tree[pos].val+=val;
        tree[pos].add+=val;
        return tree[pos].val;
    }
    if(tree[pos].add){
        tree[pos*2+1].val+=tree[pos].add;
        tree[pos*2+1].add+=tree[pos].add;
        tree[pos*2+2].val+=tree[pos].add;
        tree[pos*2+2].add+=tree[pos].add;
        tree[pos].add=0;
    }
    long long mid=(tree[pos].l+tree[pos].r)/2;
    if(mid>=l)update(pos*2+1,l,r,val);
    if(mid<r)update(pos*2+2,l,r,val);
    tree[pos].val = max(tree[pos*2+1].val,tree[pos*2+2].val);
    return tree[pos].val;
}


int main(){
    while(scanf("%lld %lld %lld",&n,&w,&h)!=EOF){
        if(n==0||w==0||h==0){
            printf("0\n");
            continue;
        }
        for(int i=0;i<n;++i){
            scanf("%lld %lld %lld",&star[i].x,&star[i].y,&star[i].val);
            star[i+n].x=star[i].x+w;
            star[i+n].y=star[i].y;
            star[i+n].val = -star[i].val;
            y[i] = star[i].y;
            y[i+n] = star[i].y+h;
        }
        sort(y,y+2*n);
        sort(star,star+2*n,cmp);
        ny=1;
        for(long long i=1;i<2*n;++i){
            if(y[i]!=y[ny-1])
                y[ny++] = y[i];
        }
        build(0,0,ny-1);
        long long ans=0;
        for(int i=0;i<2*n;++i){
            long long l = find(star[i].y),r=find(star[i].y+h)-1;
            ans = max(ans,update(0,l,r,star[i].val));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
