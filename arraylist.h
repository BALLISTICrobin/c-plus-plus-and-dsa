#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include<iostream>
using namespace std;


template<typename T>
class Arraylist{

   T *arr; 
   int init_len, curr_pos;

    public:
    int mem_size;
    Arraylist(){
        curr_pos = 0;
        init_len =0;
        cout<<"enter memory size"<<endl;
        cin >> mem_size;
        arr = (T *)malloc(mem_size * sizeof(T));
    }
    ~Arraylist(){
        delete []arr;
    }
    Arraylist(const Arraylist& original){
        arr = new T[mem_size];
        for(int i=0; i<original.init_len; i++){
            arr[i] = original.arr[i];
        }
    }

    // void insert(T item){
    //     arr[init_len++] = item;
    // }
    void reInitialize(){
        mem_size *= 2;
        arr = (T*)malloc(mem_size*sizeof(T));
        curr_pos = 0;
        init_len =0;
    }
    T remove(){
          T ret = arr[curr_pos];
        

        init_len--;
        
        return ret;
    }
    void append(T item)
    {
        
        arr[curr_pos] = item;
        init_len++;
        
    }
    void moveToStart()
    {
        curr_pos = 0;
    }

    void moveToEnd()
    {
        curr_pos = init_len - 1;
    }

    void prev()
    {
        if (curr_pos > 0)
            curr_pos--;
    }

    void Next()
    {
        if (curr_pos < init_len - 1)
            curr_pos++;
    }

    int length()
    {
        return init_len;
    }

    int currPos()
    {
        return curr_pos;
    }

    void moveToPos(int pos)
    {
        if (pos >= 0 && pos <mem_size)
            curr_pos = pos;
    }
    T getValue()
    {
        return arr[curr_pos];
    }

    void clear(){
        delete arr;
        arr = (T *)malloc(mem_size * sizeof(T));
        init_len =0;
        curr_pos =0;
    }
    

};


#endif