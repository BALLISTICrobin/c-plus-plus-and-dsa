#include "heap.hpp"
heap<int> result;
heap<int> &join(heap<int> &pq1, heap<int> &pq2)
{
    int len1 = pq1.length();
    int len2 = pq2.length();
    for (int i = 1; i <= len1; i++)
    {
        int temp = pq1.ExtractMax();
        result.insert(temp);
        
    }
    for (int i = 1; i <= len2; i++)
    {
        int temp = pq2.ExtractMax();
        result.insert(temp);
        // pq2.Delete();
    }

    return result;
}

int main()
{
    heap<int> h1;
    heap<int> h2;
    int n1, n2;
    cin >> n1 >> n2;
    for (int i = 1; i <= n1; i++)
    {
        int val;
        cin >> val;
        h1.insert(val);
    }
    for (int i = 1; i <= n2; i++)
    {
        int val;
        cin >> val;
        h2.insert(val);
    }

    heap<int> ans;
    ans = join(h1, h2);
    cout << endl
         << "output: ";
    ans.print_arr();
    return 0;
}
