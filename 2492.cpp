#include<stdio.h>

int uf[4040];

int find(int a){
    if(uf[a]==a)return a;
    int t = find(uf[a]);
    uf[a]=t;
    return t;
}

void merge(int a,int b){
    int pa = find(a),pb = find(b);
    uf[pa] = pb;
}

bool same(int a,int b){
    int pa = find(a),pb = find(b);
    return pa==pb;
}


int main(){
    int c;
    scanf("%d",&c);
    for(int k=0;k<c;++k){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;++i)
            uf[i]=i,uf[i+n]=i+n;
        int ans=0;
        for(int i=0;i<m;++i){
            int a,b;
            scanf("%d %d",&a,&b);
            --a,--b;
            if(ans==0){
                merge(a,b+n),merge(b,a+n);
                bool ba = same(a,b),bb = same(a+n,b+n);
                if(ba||bb)
                {
                    ans=1;
                }
            }
        }

       printf("Scenario #%d:\n",k+1);
        if(ans)
            printf("Suspicious bugs found!\n\n");
        else
            printf("No suspicious bugs found!\n\n");
    }
    return 0;
}
