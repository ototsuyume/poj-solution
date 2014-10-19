#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const double inf = 1e100,eplison = 1e-8;

struct Point{
    double x,y;
    char flag;
};

Point data[200100];
Point ydata[200100];


bool cmp(const Point &a,const Point &b){
    return a.x<b.x;
}

bool cmpy(const Point &a,const Point &b){
    return a.y<b.y;
}

double dis(const Point &a,const Point &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double solve(int l,int r){
    if(l>=r)return inf;
    else if(l+1==r){
        if(data[l].flag==data[r].flag)return inf;
        return dis(data[l],data[r]);
    }
    int mid=(l+r)/2;
    double ans = min(solve(l,mid),solve(mid+1,r));
    int num=0;
    for(int i=l;i<=r;++i){
        if(fabs(data[i].x-data[mid].x)<ans){
            ydata[num++]=data[i];
        }
    }
    sort(ydata,ydata+num,cmpy);
    for(int i=l;i<num;++i){
        int k=0;
        for(int j=i+1;j<num;++j){
            if(k>6||fabs(ydata[i].y-ydata[j].y)>ans)
                break;
            ++k;
            if(ydata[j].flag!=ydata[i].flag){
                ans=min(ans,dis(ydata[i],ydata[j]));
            }
        }
    }
    return ans;


}

int main(){
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%d",&n);
        for(int j=0;j<n;++j){
            scanf("%lf %lf",&(data[j].x),&(data[j].y));
            data[j].flag = 0;
        }
        for(int j=0;j<n;++j){
            scanf("%lf %lf",&(data[n+j].x),&(data[n+j].y));
            data[j+n].flag=1;
        }
        sort(data,data+2*n,cmp);
        printf("%.03f\n",solve(0,2*n-1));
    }
    return 0;
}
