#include <iostream>
#include<climits>
#include<algorithm>
#include <queue>
#include<vector>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    friend Node *inputBst(Node *, int);
    friend void levelOrderTraveral(Node *);
    friend bool searchInBST(Node *, int);
    friend int maxVal(Node *);
    friend int minVal(Node *);
    friend int inorderPred(Node *, int);
    friend int inorderSucc(Node *, int);
    friend Node *deleteInBst(Node *, int);
    friend void postorder(Node *);
    friend void preorder(Node *);
    friend void inorder(Node *);
    friend void Print(Node *);
    friend void PrintBST(Node *);
    friend bool IsValid(Node *,int, int);
    friend int KST(Node *,int,int &);
    friend int LCA(Node*,int,int);
    
    friend void HelpingtwoSum(Node*,vector<int> &);
    friend void helpingFBST(Node*,vector<Node*> &);
    friend Node* flattenBST(Node *);
    friend int findHeight(Node *);
    friend pair<int,int> helpingDia(Node *);
    friend pair<bool,int> helpingBalanced(Node*);
    friend bool checkSameTree(Node *, Node *);
};
Node *inputBst(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (val > root->data)
    {
        root->right = inputBst(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = inputBst(root->left, val);
    }
    return root;
}

void takeInput(Node *&root)
{
    int NodeVal;
    cin >> NodeVal;

    while (NodeVal != -1)
    {
        root = inputBst(root, NodeVal);

        cin >> NodeVal;
    }
}
void levelOrderTraveral(Node *root)
{
    queue<Node *> q1;
    q1.push(root);
    q1.push(NULL);

    while (!q1.empty())
    {
        Node *temp = q1.front();
        q1.pop();
        if (temp == NULL)
        {
            // finishing of a level
            cout << endl;
            if (!q1.empty())
            {
                q1.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q1.push(temp->left);
            }

            if (temp->right)
            {
                q1.push(temp->right);
            }
        }
    }
}
//inorder 
void inorder(Node *root){

    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
////preorder traversal of a binary tree
void preorder(Node *root){

    if(root==NULL)
    return;

    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
    return;
}

//postorder traversal of a binary tree
void postorder(Node *root){

    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
    return;
}

bool searchInBST(Node *root, int val)
{
    while (root != NULL)
    {
        if (root->data == val)
            return true;
        else if (val < root->data)
        {
            root = root->left;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
    }
    return false;
}
int maxVal(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

int minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int inorderPred(Node *root, int key)
{
    Node *temp = root;
    int z;
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            temp = temp->left;
        }
        else if (temp->data < key)
        {
            z = temp->data;
            temp = temp->right;
        }
    }

    // left subtree max value
    Node *leftSubtree = temp->left;
    if(leftSubtree!=NULL){
        z = maxVal(leftSubtree);
    }
    
    return z;
}

int inorderSucc(Node *root, int key)
{
    Node *temp = root;
    int z;
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            z = temp->data;
            temp = temp->left;
        }
        else if (temp->data < key)
        {
            temp = temp->right;
        }
    }

    // right subtree min value
    Node *rightSubtree = temp->right;
    if(rightSubtree!=NULL){
        z = minVal(rightSubtree);
    }
    
    return z;
}

// deletion
Node *deleteInBst(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        if(root->left==NULL && root->right!=NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right==NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // 2 children
        if(root->left!=NULL && root->right!=NULL){
            int max = maxVal(root->left);
            root->data = max;
            root->left = deleteInBst(root->left,max);
        }
    }
    else if(root->data>val){
        root->left = deleteInBst(root->left,val);
        
    }
    else{
        root->right = deleteInBst(root->right,val);
        
    }
    return root;
}
void PrintBST(Node *root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data;
    if(root->left!=NULL||root->right!=NULL){
        cout<<"(";
        PrintBST(root->left);
    }
    
    if(root->right!=NULL||root->left!=NULL){
        cout<<",";
        PrintBST(root->right);
        cout<<")";
    }
    
}

void Print(Node *root){
    
    cout<<"(";
    PrintBST(root);
    cout<<")";
}

bool IsValid(Node *root,int min, int max){
    if(root==NULL){
        return true;
    }

    if(root->data>=min && root->data<=max){
        bool left = IsValid(root->left,min,root->data);
        bool right = IsValid(root->right,root->data,max);
        return left && right;
    }
    else
    return false;
}

bool valid_BST(Node *root){
    return IsValid(root,INT_MIN,INT_MAX);
}
int KST(Node *root,int k,int &i){
    if(root==NULL){
        return -1;
    }

    int left = KST(root->left,k,i);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    
    int right = KST(root->right, k,i);
    return right;

}
//Kth smallest term
int kthSmallestTerm(Node*root,int k){
    int i=0;
    return KST(root,k,i);
}

//LCA
int LCA(Node* root,int a, int b){
    
    while(root!=NULL){
        if(root->data>a && root->data>b){
            root = root->left;
        }
        else if(root->data<a && root->data<b){
            root = root->right;
        }
        else{
            return root->data;
        }
    }
    return -1;
}
void HelpingtwoSum(Node* root,vector<int> &v){
    if(root==NULL){
        return;
    }

    HelpingtwoSum(root->left,v);
    v.push_back(root->data);
    HelpingtwoSum(root->right,v);

}
bool TwoSumAtBST(Node* root,int sum){
    vector<int> inVal;
    HelpingtwoSum(root,inVal);
    auto start = inVal.begin();
    auto end = inVal.end();
    end--;
    while(start<end){
        if((*start + *end) == sum)
        return true;
        else if((*start + *end)>sum){
            end--;
        }
        else
        start++;
    }
    return false;

}
void helpingFBST(Node* root,vector<Node*> &v){
    if(root==NULL){
        return;
    }
    helpingFBST(root->left,v);
    v.push_back(root);
    helpingFBST(root->right,v);
}
Node* flattenBST(Node *root){
    vector<Node*> inVal;
    helpingFBST(root,inVal);
    for(auto it= inVal.begin(); it!=inVal.end(); it++){
        (*it)->left = NULL;
        if(it==(inVal.end()-1))
        (*it)->right = NULL;
        else
        (*it)->right = (*(it+1));
    }
    return *inVal.begin();
}

int findHeight(Node *root){

    if(root==NULL)
    return 0;

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    return max(left,right)+1;

}
pair<int,int> helpingDia(Node *root){
    if(root==NULL){
        pair<int,int> temp = make_pair(0,0);
        return temp;
    }
    pair<int,int> left = helpingDia(root->left);
    pair<int,int> right = helpingDia(root->right);

    //these 3 lines only for diameter
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second+right.second+1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;
    return ans;
}
int findDiameter(Node *root){
    return helpingDia(root).first;
}

pair<bool,int> helpingBalanced(Node* root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = helpingBalanced(root->left);
    pair<bool,int> right = helpingBalanced(root->right);

    bool diff = abs(left.second-right.second)<=1;

    pair<bool,int> ans;
    ans.second = max(left.second,right.second)+1;
    if(left.first and right.first and diff){
        ans.first = true;
    }
    else
    ans.first = false;

    return ans;
}

bool checkBalnced(Node *root){
    return helpingBalanced(root).first;
}

bool checkSameTree(Node *root1, Node *root2){
    if(root1==NULL && root2 == NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL)
    return false;

    if(root1!=NULL && root2==NULL)
    return false;

    bool left = checkSameTree(root1->left,root2->left);
    bool right = checkSameTree(root1->right,root2->right);
    bool value = root1->data==root2->data;

    if(left && right && value)
    return true;
    else
    return false;
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    takeInput(root);
    cout << "level order traversal: " << endl;
    levelOrderTraveral(root);
    cout<<endl;
    cout << " inorder traversal: " << endl;
    inorder(root);
    cout<<endl;
    cout << "preorder traversal: " << endl;
    preorder(root);
    cout<<endl;
    cout << "postorder traversal: " << endl;
    postorder(root);
    cout<<endl;
    cout << "which value u want to find? " << endl;
    int n;
    cin >> n;
    if (searchInBST(root, n))
        cout << "found it" << endl;
    else
    {
        cout << "cant't find" << endl;
    }
    cout << "maximum value: " << maxVal(root) << endl;
    cout << "minimum value: " << minVal(root) << endl;
    int key;
    cout << "enter key for which u want to find inorder successor and predecessor: " << endl;
    cin >> key;

    cout << "inorder predecessor: " << inorderPred(root, key) << endl;
    cout << "inorder successor: " << inorderSucc(root, key) << endl;
    cout<<"which Node u want to delete? "<<endl;
    int m;
    cin>>m;
    root = deleteInBst(root,m);
    levelOrderTraveral(root);
    Print(root);
    cout<<endl;
    if(valid_BST(root)){
        cout<<"the bst is valid"<<endl;
    }
    else{
        cout<<"the BST is not valid"<<endl;
    }
    int k;
    cout<<"enter the value of k to find kth smallest term: "<<endl; 
    cin>>k;
    cout<<"the kth smallest term: "<<kthSmallestTerm(root,k)<<endl;
    int a,b;
    cout<<"enter nodes for which u want to find lowest(deepest) common ancestors: "<<endl;
    cin>>a>>b;
    cout<<"LCA: "<<LCA(root,a,b)<<endl;
    int sum;
    cout<<"enter target sum for searching two sum: "<<endl;
    cin>>sum;
    if(TwoSumAtBST(root,sum))
    cout<<"exist"<<endl;
    else
    cout<<"doesn't exist"<<endl;
    root = flattenBST(root);
    cout<<"BST after flattening: "<<endl;
    levelOrderTraveral(root);

    cout<<"height of bst: "<<findHeight(root)<<endl;
    cout<<"diameter of bst: "<<findDiameter(root)<<endl;

    if(checkBalnced(root))
    cout<<"the bst is balnced"<<endl;
    else
    cout<<"the bst is not balanced"<<endl;
    return 0;
}
