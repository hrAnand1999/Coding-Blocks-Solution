#include <bits/stdc++.h>
using namespace std;
class node{
     public:
    int data;
    node *left;
    node * right;
   
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node* buildTree()
{
    int d;
    cin >> d;
    if(d == -1)
        return NULL;
    node* root = new node(d);
    root -> left = buildTree();
    root -> right = buildTree();
    return root;
}
void rec_preorder(node * root)
{
    if(root == NULL)
    return;
    cout << root -> data << " ";
    rec_preorder(root -> left);
    rec_preorder(root -> right);
}
void rec_inorder(node * root)
{
    if(root == NULL)
      return;
    rec_inorder(root -> left);
    cout << root -> data << " ";
    rec_inorder(root -> right);
}
void rec_postorder(node * root)
{
    if(root == NULL)
    {
        return;
    }
    rec_postorder(root -> left);
    rec_postorder(root -> right);
    cout << root -> data << " ";
}
void iter_preorder(node* root)
{
    if(root == NULL)
       return;
    stack<node*> s;
    s.push(root);
    while(!s.empty())
    {
        node * temp = s.top();
        s.pop();
        cout << temp -> data << " ";
        if(temp -> right)
        {
            s.push(temp -> right);
        }
        if(temp -> left)
        {
            s.push(temp -> left);
        }
    }
}
void iter_inorder(node* root)
{
    if(root == NULL)
        return;
    stack<node*> s;
    while(!s.empty() || root != NULL)
    {
        if(root)
        {
            s.push(root);
            root = root -> left;
        }
        else
        {
            root = s.top();
            s.pop();
            cout << root -> data << " ";
            root = root -> right;
        }
    }
}
void iter_postorder(node* root)
{
    if(root == NULL)
        return;
    stack<node*> s, t;
    s.push(root);
    while(!s.empty())
    {
        node * temp = s.top();
        s.pop();
        t.push(temp);
         if(temp -> left)
        {
            s.push(temp -> left);
        }
        if(temp -> right)
        {
            s.push(temp -> right);
        }
       
    }
    while(!t.empty())
    {
        cout << t.top() -> data << " ";
        t.pop();
    }

}
int main() {
   node * root = buildTree();
   rec_preorder(root);
   cout << endl;
   rec_inorder(root);
   cout << endl;
   rec_postorder(root);
   cout << endl;
   iter_preorder(root);
   cout << endl;
   iter_inorder(root);
   cout << endl;
   iter_postorder(root);
   return 0;
}
