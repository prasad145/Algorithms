#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* createNode(int data)
{
    Node* newNode = new Node();
    if(!newNode)
    {
        cout << "Erro" ;
        return NULL;
    }
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data)
{
    if(root == NULL) //if tree is empty
    {
        root = createNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    //doing level order traversal inorder to find the empty node
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp -> left != NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp -> left = createNode(data);
            return root;
        }
        
        if(temp -> right != NULL)
        {
            q.push(temp -> right);
        }
        else
        {
            temp -> right = createNode(data);
            return root;
        }   
    }
}

void inorderTraversal(Node* root)
{
    if(root == NULL)
        return;

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

int main()
{
    Node* root = createNode(10);
    root -> left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
    cout << "Inorder traversal before insertion: ";
    inorderTraversal(root);
    cout << endl;
   
    int key = 15;
    root = insertNode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorderTraversal(root);
    cout << endl;
 
    return 0;
}
