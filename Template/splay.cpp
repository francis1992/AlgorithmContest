#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
template <class T>
struct Splay
{
    static const int oo=1111;
    static const int maxn=500010;
    T a[maxn];
    struct node
    {
        int size,rev;
        T val,sum,same,lma,rma,ma;
        node *ch[2],*fa;
    }buffer[maxn],*pt,*root,*Null,*sta[maxn],*que[maxn];
    int top;
    void init()
    {
        top=0;
        pt=buffer;
        Null=newnode(-oo);
        Null->size=0;Null->sum=0;
        Null->fa=Null->ch[0]=Null->ch[1]=Null;
        root=newnode(-oo);
        root->ch[1]=newnode(-oo);
        root->ch[1]->fa=root;
        pushup(root);
    }
    void REV(node* x)
    {
        if(x==Null)return;
        x->rev^=1;
        swap(x->ch[0],x->ch[1]);
        swap(x->lma,x->rma);
    }
    void SAME(node* x,T c)
    {
        if(x==Null)return;
        x->val=x->same=c;
        x->sum=x->size*c;
        x->lma=x->rma=x->ma=max(c,x->sum);
    }
    void pushup(node* x)
    {
        if(x==Null)return;
        x->size=1+x->ch[0]->size+x->ch[1]->size;
        x->sum=x->ch[0]->sum+x->val+x->ch[1]->sum;
        x->lma=max(x->ch[0]->lma,x->ch[0]->sum+x->val+max(0,x->ch[1]->lma));
        x->rma=max(x->ch[1]->rma,x->ch[1]->sum+x->val+max(0,x->ch[0]->rma));
        x->ma=max(max(x->ch[0]->ma,x->ch[1]->ma),max(0,x->ch[0]->rma)+x->val+max(0,x->ch[1]->lma));
    }
    void pushdown(node* x)
    {
        if(x==Null)return;
        if(x->same!=oo)
        {
            SAME(x->ch[0],x->same);
            SAME(x->ch[1],x->same);
            x->same=oo;
            x->rev=0;
        }
        else if(x->rev)
        {
            REV(x->ch[0]);
            REV(x->ch[1]);
            x->rev=0;
        }
    }
    void select(int k,node* f)
    {
        node* now=root;
        while(1)
        {
            pushdown(now);
            int x=now->ch[0]->size;
            if(k<=x)now=now->ch[0];
            else if(k==x+1)break;
            else k-=x+1,now=now->ch[1];
        }
        splay(now,f);
    }
    void SAME(int l,int r,T c)
    {
        select(l-1,Null);
        select(r+1,root);
        SAME(root->ch[1]->ch[0],c);
        pushup(root->ch[1]);
        pushup(root);
    }
    void REVERSE(int l,int r)
    {
        select(l-1,Null);
        select(r+1,root);
        REV(root->ch[1]->ch[0]);
        pushup(root->ch[1]);
        pushup(root);
    }
    void INSERT(int pos,int n)
    {
        select(pos,Null);
        select(pos+1,root);
        root->ch[1]->ch[0]=make_tree(1,n,root->ch[1]);
        pushup(root->ch[1]);
        pushup(root);
    }
    void DELETE(int l,int r)
    {
        select(l-1,Null);
        select(r+1,root);
        CLEAR(root->ch[1]->ch[0]);
        root->ch[1]->ch[0]=Null;
        pushup(root->ch[1]);
        pushup(root);
    }
    T SUM(int l,int r)
    {
        select(l-1,Null);
        select(r+1,root);
        return root->ch[1]->ch[0]->sum;
    }
    void CLEAR(node* x)
    {
        int l=1,r=1;
        que[1]=x;
        while(l<=r)
        {
            x=que[l++];
            sta[top++]=x;
            if(x->ch[0]!=Null)que[++r]=x->ch[0];
            if(x->ch[1]!=Null)que[++r]=x->ch[1];
        }
    }
    node* make_tree(int l,int r,node* f)
    {
        if(l>r)return Null;
        int mid=(l+r)/2;
        node* x=newnode(a[mid]);
        x->fa=f;
        x->ch[0]=make_tree(l,mid-1,x);
        x->ch[1]=make_tree(mid+1,r,x);
        pushup(x);
        return x;
    }
    node* newnode(T val)
    {
        node* now;
        if(top)now=sta[--top];
        else now=pt++;
        now->size=1;
        now->lma=now->rma=now->ma=now->sum=now->val=val;
        now->rev=0;now->same=oo;
        now->fa=now->ch[0]=now->ch[1]=Null;
        return now;
    }
    void rotate(node* x,int f)
    {
        node* y=x->fa;
        pushdown(y);pushdown(x);
        x->fa=y->fa;if(x->fa!=Null)y->fa->ch[y->fa->ch[1] == y]=x;
        if(x->ch[f]!=Null)x->ch[f]->fa=y;y->ch[!f]=x->ch[f];
        y->fa=x;x->ch[f]=y;
        pushup(y);
    }
    void splay(node* x,node* f)
    {
        pushdown(x);
        while(x->fa!=f)
        if(x->fa->fa==f)rotate(x,x->fa->ch[0]==x);
        else
        {
            node *y=x->fa,*z=y->fa;
            if(z->ch[0]==y)
            if(y->ch[0]==x)rotate(y,1),rotate(x,1);
            else rotate(x,0),rotate(x,1);
            else
            if(y->ch[1]==x)rotate(y,0),rotate(x,0);
            else rotate(x,1),rotate(x,0);
        }
        if(f==Null)root=x;
        pushup(x);
    }
};
