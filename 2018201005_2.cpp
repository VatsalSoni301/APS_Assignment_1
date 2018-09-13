#include<iostream>
#include<stdlib.h>
#define ll long long 
using namespace std;

static ll c;
ll smallest;
struct avl        // structure of avl tree
{
    ll data;    // data inside node
    ll h,bf,child;    // h=height and bf=balance factor and child=total childrean
    struct avl *left;    // left pointer
    struct avl *right;    // right pointer
};

struct avl* create_node(ll data)        // to create node having data x.
{
    struct avl *newEle=(struct avl*)malloc(sizeof(struct avl));
    newEle->data=data;
    newEle->h=1;
    newEle->bf=0;
    newEle->child=1;    
    return newEle;
}

int height(struct avl *root)    // to get height of the current node
{
    if(root==NULL)
        return 0;
    else
        return root->h;
}

int balanceFactor(struct avl *root)    // To get balance factor of the current node
{
    return height(root->left)-height(root->right);
}
int getchild(struct avl* root)
{
    if(root==NULL)
        return 0;
    else
        return root->child;
}

struct avl* RRrotation(struct avl* root)    // RRrotation
{
    struct avl *rootSuccessor=root->right;
    root->right=rootSuccessor->left;
    rootSuccessor->left=root;
    root->h = max(height(root->left), height(root->right))+1;
    root->bf=balanceFactor(root);
    rootSuccessor->h = max(height(rootSuccessor->left), height(rootSuccessor->right))+1;
    rootSuccessor->bf=balanceFactor(rootSuccessor);
    root->child=getchild(root->right)+getchild(root->left)+1;
    rootSuccessor->child=getchild(rootSuccessor->right)+getchild(rootSuccessor->left)+1;
    return rootSuccessor;
}
struct avl* LLrotation(struct avl* root)    // LLrotation
{
    struct avl *rootSuccessor=root->left;
    root->left=rootSuccessor->right;
    rootSuccessor->right=root;
    root->h = max(height(root->left), height(root->right))+1;
    root->bf=balanceFactor(root);
    rootSuccessor->h = max(height(rootSuccessor->left), height(rootSuccessor->right))+1;
    rootSuccessor->bf=balanceFactor(rootSuccessor);
    root->child=getchild(root->right)+getchild(root->left)+1;
    rootSuccessor->child=getchild(rootSuccessor->right)+getchild(rootSuccessor->left)+1;
    return rootSuccessor;
}
struct avl* LRrotation(struct avl* root)    // LRrotation
{
    struct avl *rootSuccessor=root->left;
    rootSuccessor=RRrotation(rootSuccessor);
    root->left=rootSuccessor;
    rootSuccessor=LLrotation(root);
    return rootSuccessor;
}
struct avl* RLrotation(struct avl* root)    // RLrotation
{
    struct avl *rootSuccessor=root->right;
    rootSuccessor=LLrotation(rootSuccessor);
    root->right=rootSuccessor;
    rootSuccessor=RRrotation(root);
    return rootSuccessor;
}

struct avl* insertNode(struct avl *root,ll data)    // insert into tree
{
    if(root==NULL)        // if tree null then create node which is root node and return root
    {
        struct avl *hh=create_node(data);
        return hh;
    }
    else
    {
        if(root->data<data)        // if root_data is less than key then choose right subtree.
        {
            root->right=insertNode(root->right,data);
        }
        else if(root->data>data)    // if root_data is greater than key then choose left subtree.
        {
            root->left=insertNode(root->left,data);
        }
        else
        {
            return root;
        }
        root->h=1+max(height(root->left),height(root->right));    // find height of current node
        
        int bf=balanceFactor(root);        // find balance factor.

        root->bf=bf;
        root->child=getchild(root->left)+getchild(root->right)+1;
        if(bf<-1 || bf>1)
        {
            struct avl *rootSuccessor;
            if(bf<-1)
            {
                rootSuccessor=root->right;
            }
            else
            {
                rootSuccessor=root->left;
            }
            if(bf>1 && rootSuccessor->bf>=0)
            {
                return LLrotation(root);
            }
            if(bf>1 && rootSuccessor->bf<0)
            {
                return LRrotation(root);
            }
            if(bf<-1 && rootSuccessor->bf<=0)
            {
                return RRrotation(root);
            }
            if(bf<-1 && rootSuccessor->bf>0)
            {
                return RLrotation(root);
            }
        }
        return root;
    }
}
void findsmallestElement(struct avl *root,int key)        // inorder traversal to determine nth smallest element.
{
    struct avl *root1=root;
    while(root1)
    {
        int ch=getchild(root1->left)+1;
        //cout<<root1->data<<" lll "<<ch<<" ";
        if(ch==key)
        {
            smallest=root1->data;
            break;
        }
        else if(key>ch)
        {
            key=key-ch;
            root1=root1->right;
        }
        else
        {
            root1=root1->left;
        }
    }
}
void printTree(struct avl *root)    // To print whole tree in inorder manner
{
    if(root!=NULL)
    {
        printTree(root->left);
        //cout<<root->data<<" "<<root->h<<" "<<root->bf<<endl;
        printTree(root->right);
    }
}
int searchElement(struct avl *root,ll key)    // find whether element present or not
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        if(root->data==key)
        {
            return 1;
        }
        else if(root->data>key)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
        return searchElement(root,key);
    }
}
struct avl* findMin(struct avl* root)    // find max element
{
    struct avl *root1=root;
    while (root1->left != NULL)
        root1 = root1->left;
 
    return root1;
}
struct avl* deleteNode(struct avl *root,ll data)    // delete node from the tree having ket data.
{
    if(root==NULL)
    {
        return root;
    }
    else
    {
        if(root->data<data)        // if root_data is less than key then choose right subtree.
        {
            root->right=deleteNode(root->right,data);
        }
        else if(root->data>data)    // if root data is greater than key then choose left subtree.
        {
            root->left=deleteNode(root->left,data);
        }
        else         // If root_data and key equal.
        {
            if((root->left == NULL) && (root->right == NULL))    // if node is leaf
            {
                root=NULL;
            }
            else if((root->left == NULL) || (root->right == NULL))    // if node is non leaf but have only one subtree.
            {
                if(root->left!=NULL)
                    root=root->left;
                else
                    root=root->right;
            }
            else         // if node has both subtree.
            {
                struct avl* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if(root==NULL)
        {
            return root;
        }

        root->h=1+max(height(root->left),height(root->right));
        int bf=balanceFactor(root);

        root->bf=bf;
        root->child=getchild(root->left)+getchild(root->right)+1;
        if(bf<-1 || bf>1)
        {
            struct avl *rootSuccessor;
            if(bf<-1)
            {
                rootSuccessor=root->right;
            }
            else
            {
                rootSuccessor=root->left;
            }
            if(bf>1 && rootSuccessor->bf>=0)
            {
                return LLrotation(root);
            }
            if(bf>1 && rootSuccessor->bf<0)
            {
                return LRrotation(root);
            }
            if(bf<-1 && rootSuccessor->bf<=0)
            {
                return RRrotation(root);
            }
            if(bf<-1 && rootSuccessor->bf>0)
            {
                return RLrotation(root);
            }
        }
        return root;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,i,m,q,x,temp,ans;
    struct avl *head=NULL;    // root node of the tree
    cin>>n;        // number of elements that user wants to insert into tree
    cin>>m;        // number of queries
    for(i=0;i<n;i++)
    {
        cin>>temp;
        head=insertNode(head,temp);        // insert element into tree
    }
    for(i=0;i<m;i++)
    {
        cin>>q;
        cin>>x;
        if(q==1)
        {
            head=insertNode(head,x);    // insert element into tree
        }
        else if(q==2)
        {
            ans=searchElement(head,x);    // If element is present in tree or not
            cout<<ans<<endl;
        }
        else if(q==3)
        {
            findsmallestElement(head,x);        // xth smallest element
            cout<<smallest<<endl;
            deleteNode(head,smallest);    // delete smallest
            //cout<<"Start";
            //printTree(head);
        }
    }
    return 0;
}