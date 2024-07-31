#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node *right;

    
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};

class cmp{
    public:
    bool operator()(node* a, node* b){
        return a->data>b->data;
    }
};

void findHuffmancode(node* root,vector<string> &ans, string temp) {
    if(root->left == NULL && root->right == NULL){
        ans.push_back(temp);
        return;
    }

    findHuffmancode(root->left,ans,temp+"0");
    findHuffmancode(root->right,ans, temp+"1");
    return;
}


int main(int argc, char const *argv[])
{
    string text;
    cin>>text;
    vector<int> freq;
    for(int i=0; i<text.size(); i++){
        int val;
        cin>>val;
        freq.push_back(val);
    }

    priority_queue<node*, vector<node*>, cmp> pq;
    for(int i=0; i<freq.size(); i++){
        node *newNode = new node(freq[i]);
        pq.push(newNode);
    }
    
    while(pq.size()>1){
        node* left = pq.top();
        pq.pop();

        node *right = pq.top();
        pq.pop();

        node *newNode = new node(left->data+right->data);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    //remaining 1 item will be root of huffman tree
    node *root = pq.top();

    vector<string> ans;
    string temp ="";
    findHuffmancode(root,ans,temp);
    for(auto i: ans){
        cout<<i<<endl;
    }
    return 0;
}
