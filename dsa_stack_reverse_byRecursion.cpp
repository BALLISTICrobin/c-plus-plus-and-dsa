#include"dsa_stack.cpp"
void solve(STACK<int> &st, int c, int n, int value)
{
    if (c == n)
    {
        st.push(value);
        return;
    }

    int a = st.Top();
    st.pop();
    solve(st, c + 1, n, value);
    st.push(a);
}
void insert_atBottom(STACK<int> &st, int value)
{
    int count = 0;
    int size = st.size();
    solve(st, count, size, value);
}

void revRecurr(STACK<int> &st)
{
    if(st.isEmpty()){
        return;
    }
    
    int a = st.Top();
    st.pop();
    revRecurr(st);
    // st.push(a);
    insert_atBottom(st,a);

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
    revRecurr(st1);
    st1.display();
    return 0;
}
