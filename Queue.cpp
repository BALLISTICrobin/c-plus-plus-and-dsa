#include "queueByLL.cpp"
//#include"queueByArray.cpp"
template <typename T>
void task()
{
    
    Queue<T> q1;
    while (true)
    {
        int func_num;

        T parameter, z;
        cout << "operations of queue:" << endl
             << "0.end" << endl
        << "1.enqueue(item)" << endl
        << "2.dequeue()" << endl
        << "3.length()" << endl
        << "4.Front()" << endl
        << "5.back()" << endl
        << "6.isempty()" << endl
        << "7.clear()" << endl;
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
            q1.display();
            q1.enqueue(parameter);
            q1.display();
            break;
        case 2:
            q1.display();
            if (q1.isEmpty())
                cout << "the queue is empty" << endl;
            else
            {

                z =  q1.dequeue();
                q1.display();
                cout<<z<<endl;
            }

            break;
        case 3:
            q1.display();
             z = q1.length();

            q1.display();
            cout << z << endl;
            break;
        case 4:
            q1.display();
            if (q1.isEmpty())
                cout << "the queue is empty" << endl;
            else
            {
                z = q1.Front();
                q1.display();
                cout << z << endl;
            }

            break;
        case 5:
            q1.display();
            if (q1.isEmpty())
                cout << "the queue is empty" << endl;
            else
            {
                z = q1.end();
                q1.display();
                cout << z << endl;
            }
            break;
        case 6:
            q1.display();
            if (q1.isEmpty())
                cout << "The Queue is Empty" << endl;
            else
                cout << "The Queue is not Empty" << endl;
            break;
        case 7:
            q1.display();
            q1.Clear();
            q1.display();
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
