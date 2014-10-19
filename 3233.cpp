#include<stdio.h>
#include<string.h>


void mulmatrix(long long a[30][30],long long b[30][30],long long n,long long mod){
    long long c[30][30];
    for(long long i=0;i<n;++i){
        for(long long j=0;j<n;++j){
            long long ans=0;
            for(long long k=0;k<n;++k)
                ans+=a[i][k]*b[k][j];
            c[i][j]=ans%mod;
            //prlong longf("%d %d %d\n",i,j,c[i][j]);
        }
    }
    memcpy(a,c,sizeof(c));
}

void addmatrix(long long a[30][30],long long b[30][30],long long n,long long mod){
    for(long long i=0;i<n;++i){
        for(long long j=0;j<n;++j){
            a[i][j]+=b[i][j];
            a[i][j]%=mod;
        }
    }
}

void powmatrix(long long a[30][30],long long k,long long n,long long mod){
    if(k==1)return;
    long long b[30][30];
    memcpy(b,a,sizeof(b));
    mulmatrix(b,a,n,mod);
    powmatrix(b,k>>1,n,mod);
    if(k&1)mulmatrix(b,a,n,mod);
    memcpy(a,b,sizeof(b));
}
/*
void pm(long long a[30][30],long long n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n-1;++j)
            printf("%I64d ",a[i][j]);
        printf("%I64d\n",a[i][n-1]);
    }
}
*/

void cal(long long a[30][30],long long k,long long n,long long mod){
    if(k==1)return;
    long long b[30][30],c[30][30],d[30][30];
    memcpy(b,a,sizeof(b));
    cal(b,k/2,n,mod);
    memcpy(c,a,sizeof(c));
    powmatrix(c,k/2,n,mod);
    memcpy(d,b,sizeof(d));
    mulmatrix(d,c,n,mod);
    addmatrix(b,d,n,mod);
    if(k&1){
        powmatrix(a,k,n,mod);
        addmatrix(b,a,n,mod);
    }
    memcpy(a,b,sizeof(b));

}

int main(){
    long long n,m,k;
    long long a[30][30],b[30][30];
    scanf("%I64d %I64d %I64d",&n,&k,&m);
    for(long long i=0;i<n;++i){
        for(long long j=0;j<n;++j){
            scanf("%I64d",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    cal(a,k,n,m);

    for(long long i=0;i<n;++i){
        for(long long j=0;j<n-1;++j)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][n-1]);
    }
    return 0;
}
