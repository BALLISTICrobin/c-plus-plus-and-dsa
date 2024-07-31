
#include "listArr1.cpp"
//#include "listLL1.cpp"

int main(int argc, char const *argv[])
{

    cin >> total_car >> total_garage >> maxCarPerGar;
    getchar();

    for (int i = 0; i < total_garage; i++)
    {
        cout << "garage ";
        int garage_num;

        cin >> garage_num;
        gar[garage_num - 1].Init();
    }
    for (int i = 0; i < total_garage; i++)
    {
        cout << i + 1 << " ";
        print(gar[i]);
    }
    do
    {
        string customer;
        int car_numm;
        cin >> customer;

        if (customer == "end")
        {
             delete []gar;//delete
    
            return 1;
        }
        else if (customer == "ret")
        {
            cin >> car_numm;
            int count = 0;
            for (int i = total_garage - 1; i >= 0; i--)
            {
                int flag = pos_max(gar[i]);
                if (flag == -1)
                {
                    continue;
                }
                else
                {
                    count++;
                    if (flag == 0 && gar[i].length() == 0)
                    {
                        gar[i].moveToPos(flag);
                        gar[i].insert(car_numm);
                        for (int j = 0; j < total_garage; j++)
                        {
                            print(gar[j]);
                        }
                        break;
                    }
                    else
                    {
                        gar[i].moveToPos(flag + 1);
                        gar[i].insert(car_numm);
                        for (int j = 0; j < total_garage; j++)
                        {
                            print(gar[j]);
                        }
                        break;
                    }
                }
            }
            if (count == 0)
            {
                cout << "all garages are full" << endl;
            }
        }
        else if (customer == "req")
        {
            int count = 0;
            for (int i = 0; i < total_garage; i++)
            {
                int flag = pos_min(gar[i]);
                if (flag == -1)
                {
                    continue;
                }
                else
                {
                    count++;
                    gar[i].moveToPos(flag);
                    gar[i].remove();
                    for (int j = 0; j < total_garage; j++)
                    {
                        print(gar[j]);
                    }
                    break;
                }
            }
            if (count == 0)
            {
                cout << "all garages are empty" << endl;
            }
        }
    } while (true);
    
   
    return 0;
}
