#ifndef RED_BLACKTREE_HPP
#define RED_BLACKTREE_HPP
#include <iostream>
#include"colors.hpp"

using namespace std;
#define RED 1
#define BLACK 0
class Node
{
public:
    int key;
    string value;
    Node *parent;
    Node *left;
    Node *right;
    int color;
};

class RedBlackTree
{
private:
    Node *root;
    Node *NIL;
    int sizeOfTree;
    void initialization(Node *node, Node *parent)
    {
        node->key = 0;
        node->value = "";
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = BLACK;
    }

    void preOrderHelper(Node *node)
    {
        if (node == NIL)
        {
            return;
        }
        if(node->color==RED){
            cout<< colors::red << node->key << "_" << node->value<< colors::reset;
        }
        else{
            cout<<node->key << "_" << node->value;
        }
        
        if (node->left != NIL || node->right != NIL)
        {
            cout << "(";
            preOrderHelper(node->left);
        }

        if (node->right != NIL || node->left != NIL)
        {
            cout << ",";
            preOrderHelper(node->right);
            cout << ")";
        }
    }

    void fixDelete(Node *x)
    {
        Node *s;
        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                s = x->parent->right;
                if (s->color == RED)
                {

                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == BLACK && s->right->color == BLACK)
                {

                    s->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (s->right->color == BLACK)
                    {

                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else
            {
                s = x->parent->left;
                if (s->color == RED)
                {

                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == BLACK && s->right->color == BLACK)
                {

                    s->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (s->left->color == BLACK)
                    {

                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    void transplant(Node *u, Node *v)
    {
        if (u->parent == nullptr)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    bool deleteNodeHelper(Node *node, int key)
    {

        Node *z = NIL;
        Node *x, *y;
        while (node != NIL)
        {
            if (node->key == key)
            {
                z = node;
            }

            if (node->key <= key)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }

        if (z == NIL)
        {
            //cout << "Couldn't find key in the tree" << endl;
            return false;
        }
        
        y = z;
        int y_original_color = y->color;
        if (z->left == NIL)
        {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == NIL)
        {
            x = z->left;
            transplant(z, z->left);
        }
        else
        {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        sizeOfTree--;
        if (y_original_color == BLACK)
        {
            fixDelete(x);
        }
        return true;
    }

    void fixInsert(Node *k)
    {
        Node *u;
        while (k->parent->color == RED)
        {
            if (k->parent == k->parent->parent->right)
            {
                u = k->parent->parent->left;
                if (u->color == RED)
                {

                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                else
                {
                    if (k == k->parent->left)
                    {

                        k = k->parent;
                        rightRotate(k);
                    }

                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            }
            else
            {
                u = k->parent->parent->right;

                if (u->color == RED)
                {

                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                else
                {
                    if (k == k->parent->right)
                    {

                        k = k->parent;
                        leftRotate(k);
                    }

                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root)
            {
                break;
            }
        }
        root->color = BLACK;
    }
    void clearHelper(Node *rootNode)
    {
        if (rootNode != NIL) {
            
			//cout<<rootNode->key<<" ";
			clearHelper(rootNode->left);
            
			clearHelper(rootNode->right);
            
            delete rootNode;
            
		} 
       
    }
    void inorderHelper(Node* rootNode){
        if (rootNode == NIL)
        {
            return;
        }

        
        if (rootNode->left != NIL || rootNode->right != NIL)
        {
            
            inorderHelper(rootNode->left);
        }
        if(rootNode->color==RED){
            cout<< colors::red << rootNode->key << "=>" << rootNode->value<< colors::reset<<endl;
        }
        else{
            cout<<rootNode->key << "=>" << rootNode->value<<endl;
        }
        if (rootNode->right != NIL || rootNode->left != NIL)
        {
            
            inorderHelper(rootNode->right);
            
        }
    }
public:
    RedBlackTree()
    {
        NIL = new Node;
        NIL->color = BLACK;
        NIL->left = nullptr;
        NIL->right = nullptr;
        root = NIL;
        sizeOfTree = 0;
    }

    void preorder()
    {
        preOrderHelper(this->root);
    }

    Node *minimum(Node *node)
    {
        while (node->left != NIL)
        {
            node = node->left;
        }
        return node;
    }

    Node *maximum(Node *node)
    {
        while (node->right != NIL)
        {
            node = node->right;
        }
        return node;
    }

    void leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != NIL)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            this->root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node *x)
    {
        Node *y = x->left;
        x->left = y->right;
        if (y->right != NIL)
        {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            this->root = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insert(int key, string value)
    {
        sizeOfTree++;
        Node *node = new Node;
        node->parent = nullptr;
        node->key = key;
        node->value = value;
        node->left = NIL;
        node->right = NIL;
        node->color = RED;

        Node *y = nullptr;
        Node *x = this->root;

        while (x != NIL)
        {
            y = x;
            if (node->key < x->key)
            {
                x = x->left;
            }
            else if(node->key>x->key)
            {
                x = x->right;
            }
            else{
                x->value = node->value;
                sizeOfTree--;
                return; 
            }
        }

        node->parent = y;
        if (y == nullptr)
        {
            root = node;
        }
        else if (node->key < y->key)
        {
            y->left = node;
        }
        else
        {
            y->right = node;
        }

        if (node->parent == nullptr)
        {
            node->color = BLACK;
            return;
        }

        if (node->parent->parent == nullptr)
        {
            return;
        }
        
        fixInsert(node);
    }

    Node *getRoot()
    {
        return this->root;
    }

    // delete the node from the tree
    bool deleteNode(int key)
    {
        return deleteNodeHelper(this->root, key);
    }

    bool find(int key)
    {
        Node *temp = root;
        while (temp != NIL)
        {
            if (temp->key > key)
                temp = temp->left;
            else if (temp->key < key)
                temp = temp->right;
            else
                return true;
        }
        return false;
    }
    int size()
    {
        return sizeOfTree;
    }
    bool clear()
    {
        if (size() == 0)
            return false;
        else
        {
            clearHelper(this->root);
            sizeOfTree = 0;
            root = NIL;
            return true;
        }
    }
    bool empty(){
        if(sizeOfTree==0){
            return true;
        }
        else{
            return false;
        }
    }
    void Inorder(){
        inorderHelper(this->root);
    }
};

#endif

