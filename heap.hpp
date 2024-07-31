#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>
#include <cmath>
#define MAXSIZE 1000
using namespace std;

template <typename T>
class heap
{
    T *arr;
    int size;
    int mem_size;

public:
    heap()
    {

        mem_size = MAXSIZE;
        arr = (T *)malloc(MAXSIZE * sizeof(T));
        size = 0;
        arr[size] = -1;
    }

    void reinitialize()
    {
        mem_size = mem_size * 2;
        arr = (T *)realloc(arr, mem_size * sizeof(T));
    }

    // max heap;
    // insertion
    void insert(T value)
    {
        size++;
        if (size == mem_size)
            reinitialize();
        arr[size] = value;
        int child_index = size;
        while (child_index > 1)
        {
            int parent_index = child_index / 2;
            if (arr[parent_index] < arr[child_index])
            {
                swap(arr[parent_index], arr[child_index]);
                child_index = parent_index;
            }
            else
                return;
        }
    }

    void Print()
    {
        cout << "No of elements: " << size << endl;
        int level = 1;
        for (int i = 1; i <= size; i++)
        {
            if (i < pow(2, level))
            {
                cout << arr[i];
                if (i != 1)
                    cout << '\t';
            }
            else
            {
                level++;
                cout << endl;
                cout << arr[i] << '\t';
            }
        }
        cout << endl;
    }

    // deletion
    T ExtractMax()
    {
        T temp = arr[1];

        arr[1] = arr[size];
        size--;
        int parent_index = 1;
        while (parent_index < size)
        {

            T left = arr[parent_index * 2];
            T right = arr[parent_index * 2 + 1];
            int larger_index = left > right ? parent_index * 2 : parent_index * 2 + 1;
            if (arr[parent_index] < arr[larger_index])
            {
                swap(arr[parent_index], arr[larger_index]);
                parent_index = larger_index;
            }
            else
            {

                break;
            }
        }
        return temp;
    }
    // build heap using heapify algorithm
    void Max_heapify(int i, int n)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <= n && arr[largest] < arr[left])
        {
            largest = left;
        }

        if (right <= n && arr[largest] < arr[right])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            Max_heapify(largest, n);
        }
    }

    // heap sort
    void heapSort()
    {
        int n = size;
        while (n > 1)
        {
            swap(arr[1], arr[n]);
            n--;
            Max_heapify(1, n);
        }
    }

    T find_max()
    {
        return arr[1];
    }
    bool increase_key(int index, T newKey)
    {
        if (arr[index] > newKey)
        {
            return false;
            // cout << "New key is not larger than the previous key" << endl;
        }
        else
        {
            arr[index] = newKey;
            int child_index = index;
            while (child_index > 1)
            {
                int parent_index = child_index / 2;
                if (arr[parent_index] < arr[child_index])
                {
                    swap(arr[parent_index], arr[child_index]);
                    child_index = parent_index;
                }
                else
                {

                    return true;
                }
            }

            return true;
        }
    }

    bool decrease_key(int index, T newKey)
    {
        if (arr[index] < newKey)
        {
            return false;
        }
        else
        {

            arr[index] = newKey;
            Max_heapify(index, size);
            return true;
        }
    }
    T top()
    {
        return arr[1];
    }
    int length()
    {
        return size;
    }
    void print_arr()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

#endif
