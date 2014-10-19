#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

double solved(double h,double t){
    double hh=h-t;
    double e=hh/0.5555+10.0;
    double tmp = 1/273.16-log(e/6.11)/5417.753;
    return 1/tmp-273.16;
}

double solveh(double t,double d){
    double e=6.11*exp(5417.753*(1/273.16-1/(d+273.16)));
    double hh=0.5555*(e-10.0);
    return hh+t;
}

double solvet(double h,double d){
    double e=6.11*exp(5417.753*(1/273.16-1/(d+273.16)));
    double hh=0.5555*(e-10.0);
    return h-hh;
}

int main(){
    char c;
    while(1){
        double t=-1.0,h=-1.0,d=-1.0;
        cin>>c;
        if(c=='E')break;
        if(c=='T')
            cin>>t;
        else if(c=='D')
            cin>>d;
        else if(c=='H')
            cin>>h;
        cin>>c;
        if(c=='T')
            cin>>t;
        else if(c=='D')
            cin>>d;
        else if(c=='H')
            cin>>h;
        if(h==-1)
            h = solveh(t,d);
        else if(d==-1)
            d = solved(h,t);
        else
            t = solvet(h,d);
        printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);
    }
    return 0;
}
