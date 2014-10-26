#include<iostream>
#include<algorithm>

using namespace std;

struct interval{
    int begin,end;
};

interval data[10010];

bool cmp(const interval &a, const interval &b){
    if(a.end==b.end)return a.begin<b.begin;
    return a.end<b.end;
}

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;++i)
            cin>>data[i].begin>>data[i].end;
        sort(data,data+n,cmp);
        int ans=0,count=0,c1=data[0].end-1,c2=data[0].end;
        for(int i=1;i<n;++i){
            if(c2<data[i].begin){
                ans+=2;
                c1 = data[i].end-1;
                c2 = data[i].end;
            }
            else if(c1<data[i].begin){
                ans++;
                c1 = c2,c2 = data[i].end;
            }
        }
        ans+=2;
        cout<<ans<<endl;
    }
    return 0;
}
