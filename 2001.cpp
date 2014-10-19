#include<stdio.h>
#include<string.h>

struct trie{
    int count;
    int next[26];
};


trie data[200000];
char input[10000][21];
int n=0,level=0;


void add(const char *s)
{
    int cur = 0;
    while(*s)
    {
        int c = *s-'a';
        ++data[cur].count;
        if(!data[cur].next[c])
        {
            data[cur].next[c] = ++level;
            memset(&data[level],0,sizeof(trie));
        }
        cur = data[cur].next[c];
        ++s;
    }
    ++data[cur].count;
}

void find(const char *s,char *res)
{
    int cur = 0, len = 0;
    while(*s&&data[cur].count>1){
        //printf("%c %d\n",*s,data[cur].count);
        res[len++]=*s;
        char c = *s-'a';
        cur = data[cur].next[c];
        ++s;
    }
    if(len==0)
        res[len++]=*s;
    res[len]=0;
}


int main()
{
    memset(&data[0],0,sizeof(trie));
    while(gets(input[n++]))
    {
        add(input[n-1]);
    }
    for(int i=0;i<n;++i)
    {
        char res[21];
        find(input[i],res);
        printf("%s %s\n",input[i],res);
    }
    return 0;
}
