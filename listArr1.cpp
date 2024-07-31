#include <iostream>
#include <cstdlib>
using namespace std;
int total_car, total_garage, maxCarPerGar;
class listArr
{
protected:
    int *arr, init_len, mem_size, curr_pos;

public:
    // array initialization
    void init()
    {
        curr_pos = 1;
        cin >> init_len >> mem_size;
        arr = (int *)malloc(mem_size * sizeof(int));
        for (int i = 0; i < init_len; i++)
        {
            cin >> arr[i];
        }
    }
    void Init()
    {

        curr_pos = 0;
        arr = (int *)malloc(1000 * sizeof(int));
        int i = 0;
        while (getchar() != '\n')
        {
            i++;
            cin >> arr[i-1];
        }
        init_len = i;
    }
    // display list
    void display()
    {
        cout << "<";
        int i, count = 0;
        if (init_len > 0)
        {
            for (i = 0; i < init_len - 1; i++)
            {
                if (i == curr_pos)
                {
                    count++;
                    cout << "|";
                }
                cout << arr[i];
                if (i != curr_pos - 1)
                    cout << ",";
            }
            if (i == curr_pos && count == 0)
                cout << "|";
            cout << arr[i];
        }
        cout << ">" << endl;
    }
    // insert at current position
    int insert(int item)
    {

        // if (curr_pos < 0)
        // {
        //     cout << "curr_pos is not valid";
        //     return -1;
        // }
        // if (curr_pos > init_len)
        // {
        //     cout << "the current position is not valid";
        //     return -1;
        // }
        init_len++;
        int i;
        for (i = init_len - 1; i >= curr_pos; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = item;
        return -1;
    }

    int remove()
    {
        // if (curr_pos < 0)
        // {
        //     cout << "curr_pos is not valid";
        //     return -1;
        // }
        // if (curr_pos >= init_len)
        // {
        //     cout << "the current position is not valid";
        //     return -1;
        // }
        int ret = arr[curr_pos];
        for (int i = curr_pos; i < init_len; i++)
        {
            arr[i] = arr[i + 1];
        }

        init_len--;
        
        return ret;
    }

    int moveToStart()
    {
        curr_pos = 0;
        return -1;
    }
    int moveToEnd()
    {
        curr_pos = init_len - 1;
        return -1;
    }
    int prev()
    {
        curr_pos--;
        // if (curr_pos < 0)
        // {
        //     cout << "curr_pos is not valid";
        //     curr_pos++;
        //     return -1;
        // }
        return -1;
    }
    int Next()
    {
        curr_pos++;
        // if (curr_pos > init_len)
        // {
        //     cout << "the current position is not valid";
        //     curr_pos--;
        //     return -1;
        // }
        return -1;
    }
    int length()
    {
        return init_len;
    }
    int currPos()
    {
        return curr_pos;
    }

    int moveToPos(int pos)
    {
        curr_pos = pos;
        // if (curr_pos < 0)
        // {
        //     cout << "curr_pos is not valid";
        //     curr_pos = 1;
        //     return -1;
        // }
        // if (curr_pos > init_len)
        // {
        //     cout << "the current position is not valid";
        //     curr_pos = 1;
        //     return -1;
        // }
        return -1;
    }

    int getValue()
    {
        return arr[curr_pos];
    }
    int clear()
    {
        init_len = 0;
        return -1;
    }

    int append(int item)
    {
        arr[init_len] = item;
        init_len++;
        return -1;
    }

    int search(int item)
    {

        int low = 0;
        int high = init_len - 1;
        int mid = (high + low) / 2;
        while (high >= low)
        {
            if (item == arr[mid])
            {
                return 1;
            }
            else if (item > arr[mid])
            {
                low = mid + 1;
            }
            else if (item < arr[mid])
            {
                high = mid - 1;
            }

            mid = (high + low) / 2;
        }

        return -1;
    }
    friend void print(listArr);
} L;

listArr *gar = new listArr[maxCarPerGar*10];
void print(listArr gar)
{
    for (int i = 0; i < gar.length(); i++)
    {
        cout << gar.arr[i]<<" ";
    }
    cout << endl;
}

int pos_min(listArr gar)
{
    if (gar.length() == 0)
        return -1;
    else
    {
        gar.moveToStart();

        int min = gar.getValue();

        int c_pos = 0;
        int index = gar.currPos() + 1;
        gar.Next();
        while (gar.currPos() < gar.length())
        {

            if (gar.getValue() < min)
            {

                min = gar.getValue();
                c_pos = gar.currPos();
            }
            gar.Next();
        }
        return c_pos;
    }
}

int pos_max(listArr gar)
{

    if (gar.length() == maxCarPerGar)
        return -1;
    else if (gar.length() == 0)
    {
        return 0;
    }
    else
    {

        gar.moveToStart();

        int max = gar.getValue();

        int c_pos = 0;
        int index = gar.currPos() + 1;
        gar.Next();
        while (gar.currPos() < gar.length())
        {

            if (gar.getValue() > max)
            {

                max = gar.getValue();
                c_pos = gar.currPos();
            }
            gar.Next();
        }
        return c_pos;
    }
}
