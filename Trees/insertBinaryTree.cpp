/*
Constructing a tree
Input:
User inputs number of nodes N
Next N lines consists of inputs "p c a" where p is parent,c is child,a is either L(left) or R(right)

Output:
Inorder traversal of constructed binary tree
*/

#include<bits/stdc++.h>
using namespace std;
struct tree
{
    int data;
    struct tree *r;
    struct tree *l;
};
typedef struct tree * node;
node getnode(int d)
{
    node n=new struct tree;
    n->data=d;
    n->r=n->l=NULL;
    return n;
}
void inorder(node root){
    if(!root)
        return;
    inorder(root->l);
    cout<<root->data<<" ";
    inorder(root->r);
}
int main()
{
    map<int,node> m;
    int p,c,n;
    char a;
    node root=NULL;
    node parent,child;
    cin>>n;
    while(n--){
        cin>>p>>c;
        getchar();
        cin>>a;
        if(m.find(p)==m.end()){
            parent=getnode(p);
            m[p]=parent;
            if(!root)
                root=parent;
        }
        else
            parent=m[p];
        child=getnode(c);
        if(a=='L')
            parent->l=child;
        else
            parent->r=child;
        m[c]=child;
    }
    inorder(root);
    cout<<endl;
}
