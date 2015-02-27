#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
char data[100][110];

int main(){
    int m,n;
    scanf("%d",&m);
    getchar();
    while(m>0){
        --m;
        scanf("%d\n",&n);

        for(int i=0;i<n;++i){
            gets(data[i]);
        }
        if(n==1){
            printf("%d\n",strlen(data[0]));
            continue;
        }
        int size = strlen(data[0]), ans = 0;
        for(int i=0,len=size;i<size;i++,len--){
            if(len<=ans)break;
            for(int j=len;j>=1;j--){
                if(j<=ans)break;
                char tmp[110];
                memcpy(tmp,data[0]+i,j);
                tmp[j] = 0;
                bool res=true;
                for(int k=1;k<n;++k){
                    if(strstr(data[k],tmp)==NULL){
                        reverse(tmp,tmp+j);
                        if(strstr(data[k],tmp)==NULL){
                            res = false;
                            break;
                        }
                    }
                }
                if(res)
                    ans = j;
           }
        }
        printf("%d\n",ans);
    }
    return 0;
}
