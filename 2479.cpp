#include<stdio.h>
#include<algorithm>
#define MIN_INT  0x80000000;
using namespace std;

int data[51000],dp1[51000],dp2[51000];

int main(){
    int n,size;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&size);
        for(int j=0;j<size;++j)
            scanf("%d",&data[j]);
        int cur=data[0],back=data[size-1];
        dp1[0]=cur;
        dp2[size-1]=back;
        for(int j=1;j<size;++j){
            cur+=data[j];
            if(cur<data[j])
                cur = data[j];
            dp1[j] = max(dp1[j-1],cur);
            back+=data[size-1-j];
            if(back<data[size-1-j])
                back=data[size-1-j];
            dp2[size-1-j]=max(dp2[size-j],back);
        }
        int ans = MIN_INT;
        for(int j=0;j<size-1;++j)
            ans = max(ans,dp1[j]+dp2[j+1]);
        printf("%d\n",ans);
    }
    return 0;
}
