#include"dsa_doubleEndedQueue.cpp"
#include"dsa_stack.cpp"
void reverseKelements(Queue<int> &q,int K){
    STACK<int> st(K);
    for(int i=1; i<=K; i++){
        int a = q.dequeFront();
        st.push(a);

    }
    while(!st.isEmpty()){
        int temp = st.Top();
        st.pop();
        q.enqueBack(temp);
    }

    for(int i=1; i<=(q.size-K); i++){
       int a = q.dequeFront();
       q.enqueBack(a);
    }
}

int main(int argc, char const *argv[])
{
    Queue<int> q1;
    int k;
    cin>>k;
    for(int i=0; i<q1.size; i++){
        int data;
        cin>>data;
        q1.enqueBack(data);
    }
    reverseKelements(q1,k);
    q1.display();
    return 0;
}
