#include"dsa_stack.cpp"

void sortedInsert(STACK<int> &st, int value){
    if(value>st.Top()||st.isEmpty()){
        st.push(value);
        return;
    }
    int a = st.Top();
    st.pop();
    sortedInsert(st,value);
    st.push(a);
    return;

}

void sort_stack(STACK<int> &st){

    if(st.isEmpty()){
        return ;
    }

    int a = st.Top();
    st.pop();
    sort_stack(st);
    sortedInsert(st,a);

}

int main(int argc, char const *argv[])
{
    STACK<int> st1(20);
    int num;
    cout << "how many numbers u want to take input: " << endl;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int data;
        cin >> data;
        st1.push(data);
    }
    sort_stack(st1);
    st1.display();
    return 0;
}