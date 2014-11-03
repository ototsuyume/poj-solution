#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

char input[2048][16];

struct edge{
    int v,a,b;
    edge(int vv,int aa,int bb):v(vv),a(aa),b(bb){};
    edge(){};
};

edge e[2048*2048];
int us[2048],n;

int find(int a){
    if(us[a]==a)
        return a;
    us[a] = find(us[a]);
    return us[a];
}

bool merge(int a,int b){
    int pa = find(a), pb = find(b);
    bool ret =  (pa==pb);
    us[pa] = pb;
    return ret;
}

bool cmp(const edge &a,const edge &b){
    return a.v<b.v;
}

int main(){
    while(cin>>n){
        if(n==0)break;
        cin.getline(input[0],16);
        for(int i=0;i<n;++i)
            cin.getline(input[i],16);
        int pos = 0;
        for(int i=0;i<n;++i){
            us[i]=i;
            for(int j=i+1;j<n;++j){
                int d = 0;
                for(int k=0;k<7;++k){
                    if(input[i][k]!=input[j][k])
                        ++d;
                }
                e[pos++] = edge(d,i,j);
            }
        }
        sort(e,e+pos,cmp);
        int ans=0;

        for(int i=0;i<pos;++i){
            if(!merge(e[i].a,e[i].b))
                ans+=e[i].v;
        }
        cout<<"The highest possible quality is 1/"<<ans<<'.'<<endl;
    }
    return 0;
}
