#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

char buf1[1010],buf2[1010],ans[1010];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s %s",buf1,buf2);
        int l1 = strlen(buf1), l2 = strlen(buf2);
        int pos = max(l1,l2)+2,c=0;
        ans[pos--] = 0;
        --l1,--l2;
        while(l1>=0&&l2>=0){
            int v = buf1[l1--]-'0'+buf2[l2--]-'0'+c;
            c = v/2;
            ans[pos--] = v%2+'0';
        }
        if(l1>=0||l2>=0){
            int len = max(l1,l2);
            char *tmp = (l1>=0)?buf1:buf2;
            while(len>=0){
                int v = tmp[len--]-'0'+c;
                c = v/2;
                ans[pos--] = v%2+'0';
            }
        }
        if(c>0)
            ans[pos--] = c+'0';
        ++pos;
        while(ans[pos]!=0&&ans[pos]=='0')++pos;
        printf("%d %s\n",i+1,(ans[pos]==0)?"0":(ans+pos));
    }
    return 0;
}
