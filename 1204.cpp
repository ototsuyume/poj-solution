#include<stdio.h>
#include<string.h>

struct dirdata{
    int dx,dy;
};
const dirdata dpos[]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

struct trie{
    int tag,len,count;
    int next[26];
};

struct pos{
    int x,y,dir;
};

trie data[1000000];
pos res[1000];

char map[1000][1001];

int n,c,w,level=0;
bool debug=false;
void add(const char *s,int seq)
{
    int cur = 0,len = 0;
    while(*s){
        int c = *s-'A';
        if(!data[cur].next[c]){
            data[cur].next[c]=++level;
            memset(&data[level],0,sizeof(trie));
        }
        data[cur].len = len++;
        ++data[cur].count;
        cur = data[cur].next[c];
        ++s;
    }
    data[cur].tag = seq;
    ++data[cur].count;
    data[cur].len=len;
}

int dfs(int x,int y,int l,int dir)
{
    //if(debug)printf("tag:%d %d %d\n",x,y,data[l].tag);
    //if(x==0&&y==2&&l==0&&dir==2)debug=true;
    int count=0;
    if(data[l].tag)
    {
        int num = data[l].tag-1;
        res[num].x = x-dpos[dir].dx*data[l].len;
        res[num].y = y-dpos[dir].dy*data[l].len;
        res[num].dir = dir+'A';
        data[l].tag=0;
        ++count;
    }
    if(x<0||y<0||x>=n||y>=c)return count;
    int c = map[x][y]-'A';
    //if(debug)printf(" %d %d c:%c  %d %d %d\n",x,y,map[x][y],data[l].next[c],data[l].tag,data[l].count);
    if(data[l].next[c]&&data[l].count)
    {
        count+=dfs(x+dpos[dir].dx,y+dpos[dir].dy,data[l].next[c],dir);
    //if(debug)printf(" %d %d c:%c  %d %d %d\n",x,y,map[x][y],data[l].next[c],data[l].tag,data[l].count);
    }
    data[l].count-=count;
    return count;
}
int main()
{
    memset(&data[0],0,sizeof(trie));
    scanf("%d %d %d",&n,&c,&w);
    getchar();
    for(int i=0;i<n;++i)
        gets(map[i]);
    for(int i=0;i<w;++i){
        char tmp[1001];
        gets(tmp);
        add(tmp,i+1);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<c;++j)
        {
            for(int k=0;k<8;++k)
            {
                dfs(i,j,0,k);
                debug=false;
                if(data[0].count<=0){
                    for(int i=0;i<w;++i)
                        printf("%d %d %c\n",res[i].x,res[i].y,res[i].dir);
                    return 0;
                }
            }
            
        }
    }
    return 0;
}
