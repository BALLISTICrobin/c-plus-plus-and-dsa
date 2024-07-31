#include "dsa_stack.cpp"

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    STACK<int> st1(n);
    st1.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > st1.Top())
        {
            int temp = arr[i];
            arr[i] = st1.Top();
            st1.push(temp);
        }
        else{
            while(arr[i]<st1.Top()){
                st1.pop();
            }
            int temp = arr[i];
            arr[i] = st1.Top();
            st1.push(temp);
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
