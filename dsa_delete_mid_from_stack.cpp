#include"dsa_stack.cpp"
#include<string>
void solve(STACK<int>&st,int c,int n){
    if(c==n/2){
        st.pop();
        return; 
    }
    int temp = st.Top();
    st.pop();
    solve(st,c+1,n);
    st.push(temp);
    

}

void deleteMid(STACK<int> &st){
    int count =0;
    solve(st,count,st.size());
}


int main(int argc, char const *argv[])
{
    STACK<int> st(20);
    
    int length;
    cin>>length;
    for(int i=0; i<length; i++){
        int data;
        cin>>data;
        st.push(data);
    }
    deleteMid(st);
    st.display();
    return 0;
}
