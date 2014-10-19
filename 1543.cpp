#include<stdio.h>

int num[101];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;++i)
        num[i]=i*i*i;

    for(int i=6;i<=n;++i){
        int target = num[i];
        for(int j=2;j<i-2;++j){
            int v = num[j],low=j+1,up=i-1;
            while(low<up){
                int tmp = v+num[low]+num[up];
                if(tmp==target){
                    printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,low,up);
                    --up;
                    ++low;
                }
                else if(tmp>target)
                    --up;
                else
                    ++low;
            }
        }
    }
    return 0;
}
