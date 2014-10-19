#include <stdio.h>
#include <string.h>

int findroot(int A[],int n)
{
	if(A[n]==n)
		return n;
	A[n]=findroot(A,A[n]);
	return A[n];
}

bool same(int A[],int a,int b)
{
	return findroot(A,a)==findroot(A,b); 
}

void merge(int A[],int a,int b)
{
	int ra = findroot(A,a);
	A[ra] = findroot(A,b);
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int *set = new int [3*n];
	for(int i=0;i<n;++i)
	{
		set[i]=i;
		set[i+n]=i+n;
		set[i+2*n]=i+2*n;
	}
	int res=0;
	for(int i=0;i<k;++i)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(b>n||b<1||c>n||c<1)
			++res;
		else if(a==1)
		{
			--b;
			--c;
			if(same(set,b,c+n)||same(set,c,b+n))
			{
				++res;
			}
			else
			{
				merge(set,c,b);
				merge(set,c+n,b+n);
				merge(set,c+2*n,b+2*n);
			}
		}
		else
		{
			--b;
			--c;
			if(same(set,b,c)||same(set,c,b+n))
				++res;
			else
			{
				merge(set,b,c+n);
				merge(set,b+n,c+2*n);
				merge(set,b+2*n,c);
			}
		}
	}
	printf("%d\n",res);
	delete [] set;
	return 0;
}


