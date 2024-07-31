#include<iostream>
#include<fstream>
#include<string>

using namespace std;


template<typename T>
class Node
{
public:
	T data;
    Node *left;
    Node *right;
	Node(){
        data = 0;
		this->left = NULL;
        this->right = NULL;
	}

    Node(T value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
    
	
};
ofstream out("2105019_out.txt");
template<typename T>
class BST{
	Node<T> *root;

	public:
	BST(){
		root = NULL;
        
	}

	Node<T>* inputBST(Node<T>* rt,T value){
		if(rt == NULL){
			rt = new Node<T>(value);
			return rt;
		}
		else if(rt->data>value){
			rt->left = inputBST(rt->left,value);
		}

		else if(rt->data<value){
			rt->right = inputBST(rt->right,value);
		}
		return rt;
	}
	void insert(T value){
        
		root = inputBST(root,value);
	}
	//inorder 
void Inorder(Node<T> *rt){

    if(rt==NULL)
    return;

    Inorder(rt->left);
    out<<rt->data<<" ";
    Inorder(rt->right);
    return;
}
void inorder(){

    Inorder(root);
    out<<endl;
}
////preorder traversal of a binary tree
void Preorder(Node<T> *rt){

    if(rt==NULL)
    return;

    out<<rt->data<<" ";
    Preorder(rt->left);
    
    Preorder(rt->right);
    return;
}

void preorder(){
	Preorder(root);
    out<<endl;
}

//postorder traversal of a binary tree
void Postorder(Node<T> *rt){

    if(rt==NULL)
    return;

    Postorder(rt->left);
    Postorder(rt->right);
    out<<rt->data<<" ";
    
    return;
}
void postorder(){
	Postorder(root);
    out<<endl;
}

bool find( T val)
{
    Node<T> *rt = root;
    while (rt != NULL)
    {
        if (rt->data == val)
            return true;
        else if (val < rt->data)
        {
            rt = rt->left;
        }
        else if (val > rt->data)
        {
            rt = rt->right;
        }
    }
    return false;
}

T maxVal(Node<T> *rt)
{
    Node<T> *temp = rt;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

T minVal(Node<T> *rt)
{
    Node<T> *temp = rt;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
Node<T> *deleteInBst(Node<T> *rt, T val)
{
    if (rt == NULL)
    {
        return rt;
    }
    if (rt->data == val)
    {
        // 0 child
        if (rt->left == NULL && rt->right == NULL)
        {
            delete rt;
            return NULL;
        }
        // 1 child
        else if(rt->left==NULL && rt->right!=NULL){
            Node<T> *temp = rt->right;
            delete rt;
            return temp;
        }
        else if(rt->left!=NULL && rt->right==NULL){
            Node<T> *temp = rt->left;
            delete rt;
            return temp;
        }

        // 2 children
        else if(rt->left!=NULL && rt->right!=NULL){
            int min = minVal(rt->right);
            rt->data = min;
            rt->right = deleteInBst(rt->right,min);
        }
    }
    else if(rt->data>val){
        rt->left = deleteInBst(rt->left,val);
        
    }
    else{
        rt->right = deleteInBst(rt->right,val);
        
    }
    return rt;
}

void Delete(T value){
    root = deleteInBst(root,value);
}
void PrintBST(Node<T> *rt){
    if(rt==NULL){
        return;
    }
    
    out<<rt->data;
    if(rt->left!=NULL||rt->right!=NULL){
        out<<"(";
        PrintBST(rt->left);
    }
    
    if(rt->right!=NULL||rt->left!=NULL){
        out<<",";
        PrintBST(rt->right);
        out<<")";
    }
    
}

void Print(){
    
    out<<"(";
    PrintBST(root);
    out<<")"<<endl;
}

};