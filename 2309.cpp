#include<cstdio>

using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int node;
        scanf("%d",&node);
        printf("%d %d\n",(node&(node-1))+1,(node^(node-1))|node);
    }
    return 0;
}
