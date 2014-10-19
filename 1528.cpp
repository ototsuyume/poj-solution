#include<stdio.h>
#include<math.h>

int solve(int n)
{
    int ret = 1;
    if(n==1)return 0;
    for(int i=2;i<sqrt(float(n));++i){
        if(n%i==0){
            ret=ret+i+n/i;
        }
    }
    return ret;
}

int main()
{
    int val;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&val)&&val!=0){
        int res = solve(val);
        if(res == val)
            printf("%5d  %s\n",val,"PERFECT");
        else if(res<val)
            printf("%5d  %s\n",val,"DEFICIENT");
        else
            printf("%5d  %s\n",val,"ABUNDANT");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
