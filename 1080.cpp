#include<iostream>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;

int dp[110][110];

map<char,map<char,int> > score;

void init(){
    score['A']['C']=-1;
    score['A']['G']=-2;
    score['A']['T']=-1;
    score['A'][' ']=-3;
    score['C']['A']=-1;
    score['C']['G']=-3;
    score['C']['T']=-2;
    score['C'][' ']=-4;
    score['G']['A']=-2;
    score['G']['C']=-3;
    score['G']['T']=-2;
    score['G'][' ']=-2;
    score['T']['A']=-1;
    score['T']['C']=-2;
    score['T']['G']=-2;
    score['T'][' ']=-1;
    score['A']['A']=5;
    score['C']['C']=5;
    score['G']['G']=5;
    score['T']['T']=5;
}


int main(){
    int n=0;
    init();
    cin>>n;
    for(int i=0;i<n;++i){
        int ls1,ls2;
        char s1[110],s2[110];
        cin>>ls1;
        for(int j=0;j<ls1;++j)
            cin>>s1[j];
        cin>>ls2;
        for(int j=0;j<ls2;++j)
            cin>>s2[j];
        dp[0][0]=0;
        for(int j=0;j<ls1;++j)
            dp[j+1][0]=dp[j][0]+score[s1[j]][' '];
        for(int j=0;j<ls2;++j)
            dp[0][j+1] = dp[0][j]+score[s2[j]][' '];
        for(int j=0;j<ls1;++j){
            for(int k=0;k<ls2;++k){
                dp[j+1][k+1] = max(dp[j][k]+score[s1[j]][s2[k]],max(dp[j][k+1]+score[s1[j]][' '],dp[j+1][k]+score[s2[k]][' ']));
            }
        }
        cout<<dp[ls1][ls2]<<endl;
    }
    return 0;
}

