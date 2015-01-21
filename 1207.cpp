#include<cstdio>
#include<algorithm>
#include<string.h>

using namespace std;
int data[10010];
//dp need too many memory
/*
int len[1000000];

int find(int cur){
    if(cur==1)return 1;
    else if(len[cur]!=-1)
        return len[cur];
    else if(cur&1)
        len[cur] = find(cur*3+1)+1;
    else
        len[cur] = find(cur/2)+1;

    return len[cur];
}
*/

int main(){
    memset(data,0,sizeof(data));
    for(int i=1;i<10010;i++){
        int k=i;
        while(k!=1){
            data[i]++;
            if(k&1)
                k=k*3+1;
            else
                k/=2;
        }
        //data[i]++;
    }

    int i,j;
    while(scanf("%d %d",&i,&j)!=EOF){
        bool s = false;
        if(i>j)s=true,swap(i,j);
        int ans = 0;
        for(int a=i;a<=j;++a)
            ans = max(ans,data[a]);
        if(s)swap(i,j);

        printf("%d %d %d\n",i,j,ans+1);
    }
    return 0;
}
