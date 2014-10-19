#include<stdio.h>
#include<algorithm>
using namespace std;
#define LL long long 

int main()
{
    LL a,b;
    while(scanf("%lld %lld",&a,&b))
    {
        if(a==0&&b==0)
            break;
        bool ok=true;
        while(1){
            if(a<b)swap(a,b);
            if(a%b==0)break;
            else if(a-b>b)break;

            a-=b;
            ok=!ok;
        }
        printf("%s wins\n",ok?"Stan":"Ollie");
    }
    return 0;
}
