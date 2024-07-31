#include "stackByQueue.cpp"


template <typename T>
void task()
{
    
    Stack<T> s;
    while (true)
    {
        int func_num;

        T parameter, z;
        cout << "operations of queue:" << endl
             << "0.end" << endl
        << "1.push(item)" << endl
        << "2.pop()" << endl
        << "3.length()" << endl
        
        << "4.top()" << endl
        << "5.isempty()" << endl
        << "6.clear()" << endl;
        cout << "enter function number:";
        cin >> func_num;
        switch (func_num)
        {
        case 0:
            exit(0);

            break;
        case 1:
            cout << "enter parameter: ";
            cin >> parameter;
            s.display();
            s.push(parameter);
            s.display();
            break;
        case 2:
            s.display();
            if (s.isEmpty())
                cout << "the stack is empty" << endl;
            else
            {

                z =  s.pop();
                s.display();
                cout<<z<<endl;
            }

            break;
        case 3:
            s.display();
             z = s.length();

            s.display();
            cout << z << endl;
            break;
       
        case 4:
            s.display();
            if (s.isEmpty())
                cout << "the stack is empty" << endl;
            else
            {
                z = s.Top();
                s.display();
                cout << z << endl;
            }
            break;
        case 5:
            s.display();
            if (s.isEmpty())
                cout << "The stack is Empty" << endl;
            else
                cout << "The stack is not Empty" << endl;
            break;
        case 6:
            s.display();
            s.clear();
            s.display();
            break;
        default:
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    int button;
    cout << "select your datatype: " << endl
         << "1.integer" << endl
         << "2.double" << endl
         << "3.string" << endl
         << "4.character" << endl;
    cin >> button;
    getchar();
    switch (button)
    {
    case 1:

        task<int>();
        break;
    case 2:
        task<double>();

        break;
    case 3:
        task<string>();

        break;

    case 4:
        task<char>();

        break;
    default:
        break;
    }

    return 0;
    
}
