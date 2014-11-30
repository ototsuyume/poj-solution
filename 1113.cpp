#include<iostream>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;

struct Point{
    int x,y;
};
Point p[1010];

int stack[1010],top,n,r;
bool used[1010];

bool cmp(const Point &a, const Point &b) {
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}

bool clockwise(const Point &a,const Point &b,const Point &c){
    return (b.y-a.y)*(c.x-b.x)>=(c.y-b.y)*(b.x-a.x);
}

double dist(const Point &a,const Point &b){
    return sqrt(double((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

void graham(){
    sort(p,p+n,cmp);
    memset(used,0,sizeof(used));
    stack[0]=0,stack[1]=1,top=2;
    used[1]=true;
    int i=2,dir=0;
    while(1){
        if(!used[i]){
            while(top-2>=0){
                if(clockwise(p[stack[top-2]],p[stack[top-1]],p[i])){
                    used[i]=true;
                    stack[top++]=i;
                    break;
                }
                --top;
                used[stack[top]]=false;
            }
            if(top-2<0)
                used[stack[1]]=false,stack[1]=i,top=2;
        }
        if(dir==0)++i;
        else --i;
        if(i==n)dir=1,--i;
        else if(i<0)break;
    }
}

int main(){
    while(cin>>n>>r){
        for(int i=0;i<n;++i)
            cin>>p[i].x>>p[i].y;
        graham();
        double ans=0;dist(p[stack[0]],p[stack[top-1]]);
        for(int i=1;i<top;++i){
            //cout<<p[stack[i]].x<<" "<<p[stack[i]].y<<endl;
            ans+=dist(p[stack[i]],p[stack[i-1]]);
        }
        ans+=2*double(r)*3.141592653;
        cout<<int(ans+0.5)<<endl;
    }
    return 0;
}


