#include "heap.hpp"

template <typename T>
void task()
{
    heap<T> h;
    cout << "Welcome to HEAP datastructure! " << endl;
    cout << "1. INSERT" << endl
         << "2. FIND MAX" << endl
         << "3. EXTRACT MAX" << endl
         << "4. INCREASE KEY" << endl
         << "5. DECREASE KEY" << endl
         << "6. PRINT" << endl
         << "8. SORTING" << endl
         << "7. TERMINATE" << endl;
    freopen("in1.txt", "r", stdin);
    freopen("heapout.txt", "w", stdout);
    int choice;
    T tempVal, parameter, newkey1, newkey2;
    while (true)
    {
        cin >> choice;

        switch (choice)
        {
        case 1:

            cin >> parameter;
            h.insert(parameter);

            break;

        case 2:
            cout << "Max: " << h.find_max() << endl;

            break;

        case 3:
            tempVal = h.ExtractMax();
            cout << "Max: " << tempVal << " has been extracted." << endl;
            break;

        case 4:
            int index1;
            cin >> index1 >> newkey1;
            if (h.increase_key(index1, newkey1))
            {
                cout << "Key increased!" << endl;
            }
            else
                cout << "New key is not larger than the previous key" << endl;

            break;

        case 5:
            int index2;
            cin >> index2 >> newkey2;
            if (h.decrease_key(index2, newkey2))
            {
                cout << "Key decreased!" << endl;
            }
            else
                cout << "New key is not smaller than the previous key" << endl;
            break;

        case 6:
            h.Print();
            break;

        case 7:
            h.heapSort();
            h.Print();
            exit(0);
            break;

        default:
            break;
        }
    }
}

int main(int argc, char const *argv[])
{

    cout << "select your datatype:" << endl
         << "1. int" << endl
         << "2. double" << endl
         << "3. char" << endl
         << "4. string" << endl;
    int dataType;
    cin >> dataType;
    switch (dataType)
    {
    case 1:
        task<int>();
        break;
    case 2:
        task<double>();
        break;
    case 3:
        task<char>();
        break;
    case 4:
        task<string>();
        break;

    default:
        cout << "undefined datatype" << endl;
        break;
    }

    // 1 for Insert, 2 for FindMax, 3 for ExtractMax, 4 for IncreaseKey, 5 for
    // DecreaseKey, 6 for Print, 7 for terminate.
    return 0;
}