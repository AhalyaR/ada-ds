#include <iostream>
#include<conio.h>
using namespace std;


typedef struct bst
{

    int data;
    int lth,rth;
    struct bst *left,*right;//left and right threads

}node;
class thread
{

private:
    node *dummy;//dummy node
    node *New,*root,*temp,*parent;
public:
    thread();
    void create();
    void display();
    void delet();
};
//constructor
thread::thread()
{

    root=NULL;
}
//function to create nodes in a tree
void thread::create()
{

    void insertnode(node *,node *);
    New=new node;
    New->left=NULL;
    New->right=NULL;
    New->lth=0;
    New->rth=0;
    cout<<"\nEnter the element to insert\n";
    cin>>New->data;
    if(root==NULL)
    {

        root=New;
        dummy=new node;
        dummy->data=-999;
        dummy->left=root;
        root->left=dummy;
        root->right=dummy;
    }
    else
        insertnode(root,New);
}
//function to create a binary search tree
void insertnode(node *root,node *New)
{

    if(New->data<root->data)
    {

        if(root->lth==0)
        {

            New->left=root->left;
            New->right=root;
            root->left=New;
            root->lth=1;

        }
        else{
            insertnode(root->left,New);
        }
    }
    if(New->data>root->data)
    {

        if(root->rth==0)
        {

            New->right=root->right;
            New->left=root;
            root->rth=1;
            root->right=New;
        }
        else
        {

            insertnode(root->right,New);
        }
    }
}
//function to display elements in a tree
void thread::display()
{

    void inorder(node *,node *dummy);
    if(root==NULL)
    {

        cout<<"\nEmpty tree";
    }
    else{
        cout<<"\nThe tree is: \n";
        inorder(root,dummy);
    }

}
//inorder traversal function
void inorder(node *temp,node *dummy)
{

    while(temp!=dummy)
    {

        while(temp->lth==1)
              temp=temp->left;
        cout<<" "<<temp->data;
        while(temp->rth==0)
        {

            temp=temp->right;
            if(temp==dummy)
                return;
            cout<<" "<<temp->data;
        }
        temp=temp->right;
    }
}
//delete function which calls the routine for deletion of an element
void thread::delet()
{

    void del(node *,node *,int);
    int key;
    cout<<"\n enter the element you want to delete";
    cin>>key;
    del(root,dummy,key);
}
//function to deleting a node from binary search tree
void del(node *root,node *dummy,int key)
{

    node *temp,*parent,*temp_succ;
    node *searching(node *,node *,int,node **);
    int flag=0;
    temp=searching(root,dummy,key,&parent);
     if(root==temp)
     {
       cout<<"\n Its Root Node Which Can Not Be Deleted!!";
       return;
     }
 //deleting a node with two children
  if(temp->lth==1&&temp->rth==1)
  {
   parent=temp;
   temp_succ=temp->right;//inorder successor
   while(temp_succ->lth==1)
   {
            flag=1;
            parent=temp_succ;
            temp_succ=temp_succ->left;
   }
   if(flag==0)
   {
            temp->data=temp_succ->data;
            parent->right=temp_succ->right;
            parent->rth=0;
  }
  else
  {
            temp->data=temp_succ->data;
            parent->rth=0;
            parent->lth=0;
            parent->left=temp_succ->left;
   }
   cout<<" Now Deleted it!";
   return;
  }
//deleting a node having only one child
//node having only left child
  if(temp->lth==1 &&temp->rth==0)
  {
   if(parent->left==temp)
   {
            (temp->left)->right=parent;
             parent->left=temp->left;
   }
   else
   {
            (temp->left)->right=temp->right;
            parent->right=temp->left;
   }
   temp=NULL;
   delete temp;
   cout<<" Now Deleted it!";
   return;
  }

//node to be deleted has a right child
  if(temp->lth==0 &&temp->rth!=0)
  {
   if(parent->left==temp)
   {
            parent->left=temp->right;
            (temp->right)->left=temp->left;
            (temp->right)->right=parent;
   }
   else
   {
            parent->right=temp->right;
            (temp->right)->left=parent;

   }
   temp=NULL;
   delete temp;
   cout<<" Now Deleted it!";
   return;
  }
//deleting node having no child
  if(temp->lth==0 &&temp->rth==0)
  {
            if(parent->left==temp)
            {
              parent->left=temp->left;
              parent->lth=0;
            }
            else
             {
               parent->right=temp->right;
               parent->rth=0;
             }
   cout<<" Now Deleted it!";
   return;
  }


}

//function to search element is present or not
node *searching(node *root,node *dummy,int key,node **parent)
{
  node *temp;
  int flag=0;
  temp=root;
  while((temp!=dummy))
  {
   if(temp->data==key)
   {
            cout<<"\n The "<<temp->data<<" Element is Present";
            flag=1;
            return temp;
  }
   *parent=temp;
   if(temp->data>key)
            temp=temp->left;
   else
            temp=temp->right;
  }
return NULL;
}

//main function
int main()
{
   int choice;
   char ans='N';
   thread th;
   do{
    cout<<"1.create\n2.display\n3.delete";
    cin>>choice;
    switch(choice)
    {

        case 1:do{

                    th.create();
                    cout<<"\nDo you want to insert more(y/n)";
                    cin>>ans;
                   }while(ans=='y');
                break;
        case 2:th.display();
                break;
        case 3:th.delet();
        break;

        }
        cout<<"\n want to repeat?(y/n)";
        cin>>ans;

    }while(ans=='y');
    return 0;
   }


