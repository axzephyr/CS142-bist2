#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
    node* parent;
    //constructor
    node(int i)
    {
        left=NULL;
        data=i;
        right=NULL;
        parent=NULL;
    }
};

class BiST
{
public:
    node * root;
    BiST()
    {
        root=NULL;
    }
    //the function for the inserting
    void insrt(int value)
    {
        inserthelper(root,value);
    }
    void inserthelper(node * current, int value)
    {
        //the case for the root
        if(current==NULL)
        {
            current=new node(value);
            if (root==NULL)
            {
                root=current;
            }
        }
        //the case for all others
        else if (value<current->data)
        {
            if(current->left==NULL)
            {
                current->left= new node(value);
                (current->left)->parent=current;
            }
           else inserthelper(current->left,value);
        }
        else
        {
            if (current->right==NULL)
            {
                current->right=new node(value);
                (current->right)->parent=current;
            }
            else inserthelper(current->right,value);
        }

    }

    void display1()
    {
        display2(root);
    }
    void display2(node* current)
    {
        if(current->left!= NULL)
        {
            display2(current->left);
        }
        cout<<current->data<<",";
        if(current->right!= NULL)
        {
            display2(current->right);
        }
    }

    node* search1(int v)
    {
        return search2(root,v);
    }

    node* search2(node* current,int v)
    {
        if (current==NULL)
        {
           cout<<endl;
            cout<<v<<" is not present in the Binary Search Tree! "<<endl;
            return NULL;
        }
        else
        {
              if(v==current->data)
            {
                cout<<endl;
                cout<<v<<" found! "<<endl;
                return current;
            }
            else if(v<current->data)
            {
                return search2(current->left,v);
            }
            else
            {
               return search2(current->right,v);
            }
        }
    }

    node* findmin1(int v)
    {
        node* current=search1(v);
        return findmin(current);
    }

    node* findmin(node* curr)
    {
        if(curr->left != NULL)
        {
            return findmin(curr->left);
        }
        else
        {
            return curr;
        }
    }

    int counter1()
    {
        return counter2(root);
    }

    int counter2(node* current)
    {
        int i=1;
        if(current->left!= NULL)
        {
            i+=counter2(current->left);
        }
        if(current->right!= NULL)
        {
            i+=counter2(current->right);
        }
        return i;
    }


    void replace_at_parent(node* a,node* b)
    {

    }

    void deletenode(int val)
    {
        deletehelper(root,val);
    }

    node* deletehelper(node* curr, int val)
    {
    // base case
    if (curr == NULL)
     {
            return curr;
     }

    if (val < curr->data)
        {
            curr->left = deletehelper(curr->left, val);
        }

    else if (val > root->data)
       {
           curr->right = deletehelper(curr->right, val);
       }
    else
    {

        if (curr->left == NULL)
        {
             node *temp = curr->right;
            delete curr;
            return temp;
        }
        else if (curr->right == NULL)
        {
             node *temp = curr->left;
            delete curr;
            return temp;
        }


         node* temp = findmin1((curr->right)->data);


        curr->data = temp->data;


        curr->right = deletehelper(curr->right, temp->data);
    }
    return curr;
    }
};


int main()
{

    BiST s1;
    s1.insrt(10);
    s1.insrt(2);
    s1.insrt(12);
    s1.insrt(3);
    s1.insrt(1);
    s1.insrt(13);
    s1.insrt(5);
    s1.display1();
    cout<<s1.search1(1);
    cout<<s1.search1(9)<<endl;
    s1.deletenode(10);
    s1.display1();
    cout<<s1.findmin1(2)<<endl;
    cout<<s1.counter1()<<endl;
    return 0;
}




