#include"stack_offline.cpp"
template <class T>
void task(STACK<T> &s)
{
    int func_num;

    while (true)
    {
        cout << "1.clear()" << endl;
        cout << "2.push(item)" << endl;
        cout << "3.pop()" << endl;
        cout << "4.length()" << endl;
        cout << "5.topValue()" << endl;
        cout << "6.isEmpty()" << endl
             << endl;
        cout << "enter function number and parameter(if any):" << endl;
        cin >> func_num;
        if (func_num == 2)
            s.para();
        switch (func_num)
        {
        case 1:
            s.clear();
            s.display();
            break;
        case 2:
            s.push(s.getPara());
            s.display();
            break;
        case 3:
            cout << s.pop() << endl;
            s.display();
            
            break;
        case 4:
            s.display();
            cout << s.length() << endl;

            break;
        case 5:
            s.display();
            cout << s.topValue() << endl;
            break;
        case 6:
            s.display();
            if (s.isEmpty())
            {
                cout << "True" << endl;
            }
            else
                cout << "False" << endl;
            break;
        default:
            cout << "invalid function number" << endl;
            break;
        }
    }
}

template <class T>
void Stack(int mem_size,int length){
    STACK<T> s1(mem_size, length);
    s1.display();
    task(s1);
}
int main(int argc, char const *argv[])
{
    int mem_size, length;
    int type;
    cout << "enter memory size and length" << endl;
    while (true)
    {
        cin >> mem_size >> length;
        if (mem_size > length && mem_size > 0 && length > 0)
        {
            break;
        }
        cout << "invalid input, try again: " << endl;
    }
    cout << "which type of datatype will u enter?" << endl;
    cout << "1.integer" << endl;
    cout << "2.character" << endl;
    cout << "3.double" << endl;
    
    cout << "4.string" << endl;
    
    cin >> type;
    switch (type)
    {
    case 1:
        Stack<int>(mem_size,length);
        break;
    case 2:
        Stack<char>(mem_size, length);
       
        break;
    case 3:
        Stack<double>(mem_size, length);
        
        break;
    
    case 4:
        Stack<string>(mem_size, length);
        
        break;

    default:
        cout << "invalid" << endl;
        break;
    }

    return 0;
}