#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//create nodes
class NODE{
    int data;
    NODE *left,*right;

    public:
    NODE(){}
    NODE(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
    friend NODE* BuildTree(NODE* &);
    friend void levelOrderTraveral(NODE *);
    friend void reverseLevelOrderTraversal(NODE *);
    friend void inorder(NODE *);
    friend void preorder(NODE *);
    friend void postorder(NODE *);

    friend void BuildTreeFromLevelOrder(NODE *&);
    friend int countLeaves(NODE*);
};

//build tree using recursion
NODE* BuildTree(NODE* &root){
    cout<<"enter the data "<<endl;
    int value;
    cin>>value;
    root = new NODE(value);
    if(value==-1){
        return NULL;
    }
    cout<<"enter data for inserting in the left of "<<value<<endl;
    root->left =  BuildTree(root->left);
    cout<<"enter for inserting in the right of "<<value<<endl;
    root->right =  BuildTree(root->right);
    return root;

}

//level order traversal of binary tree
void levelOrderTraveral(NODE *root){
    queue<NODE*> q1;
    q1.push(root);
    q1.push(NULL);

    while(!q1.empty()){
        NODE *temp = q1.front();
        q1.pop();
        if(temp==NULL){
            //finishing of a level
            cout<<endl;
            if(!q1.empty()){
                q1.push(NULL);
            }

        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q1.push(temp->left);
            }

            if(temp->right){
                q1.push(temp->right);
            }

        }
    }
}

//reverse level order traversal from binary tree
void reverseLevelOrderTraversal(NODE *root){
    queue<NODE*> q;
    stack<int> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        NODE *temp = q.front();
        q.pop();

        if(temp!=NULL){
            s.push(temp->data);

            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }

            // q.push(NULL);
        }
        else if(temp==NULL && !q.empty()){
            q.push(NULL);
            s.push(0);
        }
    }

    while(!s.empty()){
        if(s.top()==0)
        cout<<endl;
        else
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

}

//inorder traversal of a binary tree
void inorder(NODE *root){

    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

////preorder traversal of a binary tree
void preorder(NODE *root){

    if(root==NULL)
    return;

    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
    return;
}

//postorder traversal of a binary tree
void postorder(NODE *root){

    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
    return;
}

//build tree by level order inputs
void BuildTreeFromLevelOrder(NODE *&root){
    queue<NODE*> q;
    int data;
    cout<<"enter value for root: "<<endl;
    cin>>data;
    if(data!=-1){
        root = new NODE(data);
    q.push(root);
    }
    else
    q.push(NULL);
    

    while(!q.empty()){
        NODE *temp = q.front();
        q.pop();

        if(temp!=NULL){
            cout<<"enter left data for: "<<temp->data<<endl;
            int leftData;
            cin>>leftData;
            if(leftData!=-1){
                temp->left = new NODE(leftData);
                q.push(temp->left);
            }
            else{
                temp->left = NULL;
                
            }

            cout<<"enter right data for: "<<temp->data<<endl;
            int rightData;
            cin>>rightData;
            if(rightData!=-1){
                temp->right = new NODE(rightData);
                q.push(temp->right);
            }
            else{
                temp->right = NULL;
                
            }
            
        }

    }
}

//count leaves of a binary tree
int countLeaves(NODE* root){
    queue<NODE*> q;
    q.push(root);
    int countLeaves = 0;
    while(!q.empty()){
        NODE *temp = q.front();
        q.pop();

       
        if(temp->left==NULL && temp->right==NULL)
        countLeaves++;
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    return countLeaves;
}


int main(int argc, char const *argv[])
{
    NODE *root = NULL;
    root = BuildTree(root);
    cout<<"level order traversal: "<<endl;
    levelOrderTraveral(root);
    cout<<endl<<"reverse Level order traversal:"<<endl;
    reverseLevelOrderTraversal(root);
    cout<<"inorder traversal: "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal: "<<endl;
    postorder(root);
    cout<<endl;
    BuildTreeFromLevelOrder(root);
    cout<<"level order traversal: "<<endl;
    levelOrderTraveral(root);
    cout<<endl<<countLeaves(root)<<endl;
    return 0;
}
