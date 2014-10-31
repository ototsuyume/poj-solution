#include<cstdio>
#include<cmath>

using namespace std;
double circle = 2*3.141592653;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int c;
        double R,r,s;
        scanf("%lf%d",&R,&c);
        s = sin(circle*0.5/c);
        r = R*s/(1+s);
        printf("Scenario #%d:\n%.3lf\n\n",i+1,r);
    }
    return 0;
}
