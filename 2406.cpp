#include<stdio.h>
#include<string.h>
char str[1000001];
int kmp[1000001];

int build(){
    int i=0,j=1;
    kmp[0]=0;
    while(str[j]){
        if(str[i]==str[j]){
            kmp[j]=kmp[j-1]+1;
            ++i;
        }
        else{
            if(i>0){
                i=0;
                --j;
            }
            kmp[j]=0;
        }
        ++j;
    }
    return j;
}


int main(){
    while(scanf("%s",str)!=EOF){
        if(strcmp(str,".")==0)break;
        int len = build(),ans=1;
        int res = len-kmp[len-1];
        if(len%res==0)
            ans = len/res;
        printf("%d\n",ans);
    }
    return 0;
}
