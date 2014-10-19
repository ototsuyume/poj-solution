#include<stdio.h>

int n,q;
int cows[50001];

struct node
{
	node(int cur,int ll,int rr):l(ll),r(rr),min(cur),max(cur){};
	int l,r;
	int min,max;
	node *left,*right;
};

inline int max(int a,int b)
{
	return a>b?a:b;
}

inline int min(int a,int b)
{
	return a<b?a:b;
}


node* build(int l,int r)
{
	if(l>r)
		return NULL;
	int mid = (l+r)/2;
	node *root = new node(cows[mid],l,r);
	if(l==r)
		return root;
	int lmin=0x7fffffff,lmax=0,rmin=0x7fffffff,rmax=0;
	
	if(root->left = build(l,mid))
	{
		lmin = root->left->min;
		lmax = root->left->max;
	}
	
	if(root->right = build(mid+1,r))
	{
		rmin = root->right->min;
		rmax = root->right->max;
	}
	root->min = min(rmin,min(lmin,root->min));
	root->max = max(rmax,max(lmax,root->max));
	
	return root;
}

void finddif(node *t,int l,int r,int &mx,int &mn)
{
	mx=0,mn=0x7fffffff;
	if(l<=t->l&&r>=t->r)
	{
		mx = t->max;
		mn = t->min;
	}
	else 
	{
		int mx1=0,mn1=0x7fffffff,mx2=0,mn2=0x7fffffff;
		if(t->left&&!(t->left->l>r||t->left->r<l))
		{
			finddif(t->left,l,r,mx1,mn1);
		}
		if(t->right&&!(t->right->l>r||t->right->r<l))
		{
			finddif(t->right,l,r,mx2,mn2);
		}
		mx = max(mx1,mx2);
		mn = min(mn1,mn2);
	}
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&cows[i]);
	}
	node *tree = build(0,n-1);

	for(int i=0;i<q;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int mn,mx;
		finddif(tree,l-1,r-1,mx,mn);
		if(mn==0x7fffffff)
			mn=0;
		printf("%d\n",mx-mn);
	}
	return 0;
}
