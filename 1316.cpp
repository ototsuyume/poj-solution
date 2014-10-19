#include<stdio.h>

char num[10001]={0};

int main(){
    for(int i=1;i<=10000;++i){
        int cur=i,sum=i;
        while(cur){
            sum+=cur%10;
            cur/=10;
        }
        if(sum<10000)
            num[sum]=1;
    }
    for(int i=1;i<10000;++i){
        if(num[i]==0)
            printf("%d\n",i);
    }
    return 0;
}
