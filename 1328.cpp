#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;


struct point{
    double left,right;
};

point data[2000];

int n,d;
bool cmp(const point &a, const point &b){
    if(a.left==b.left)
        return a.right<b.right;
    return a.left<b.left;
}

int solve(){
    int ans=1;
    double cur = data[0].right;
    for(int i=1;i<n;++i){
        if(data[i].left>cur){
            ans++;
            cur = data[i].right;
        }
        else if(data[i].right<cur)
            cur = data[i].right;
    }
    return ans;
}

int main(){
    int seq=1;
    while(scanf("%d%d",&n,&d),n>0){
        bool notsolve = false;
        for(int i=0;i<n;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            if(notsolve||y>d){
                notsolve = true;
                continue;
            }
            double dx = sqrt(double(d*d-y*y));
            data[i].left = x-dx;
            data[i].right = x+dx;
        }
        printf("Case %d: ",seq++);
        if(notsolve){
            printf("-1\n");
            continue;
        }
        sort(data,data+n,cmp);
        printf("%d\n",solve());
    }
    return 0;
}
