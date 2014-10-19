#include<stdio.h>

int data[1101]={0},prime[1101]={0},nofp[1101]={0};
int main(){
    for(int i=2;i<=1100;++i){
        for(int j=i*2;j<=1100;j+=i)
            data[j]=1;
    }
    int count=0;
    for(int i=1;i<=1100;++i){
        if(data[i]==0)
            prime[count++]=i;
    }
    --count;
    for(int i=1100;i>=1;--i){
        if(prime[count]>i)
            --count;
        nofp[i]=count+1;
    }
    int n,c;
    while(scanf("%d%d",&n,&c)!=EOF){
        int p = nofp[n],index=0,size=0;
        if(p&1){
            size=c*2-1;
            index = p/2-c+1;
        }
        else {
            size = c*2;
            index = p/2-c;
        }
        printf("%d %d:",n,c);
        if(index<0)index=0;
        for(int i=index;i<=index+size-1&&i<p;++i){
            printf(" %d",prime[i]);
        }
        printf("\n\n");
    }
    return 0;
}
