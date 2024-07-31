#include"2105019_BST.cpp"


template <typename T>
void task()
{
    BST<T> b;
    char info;T val; string st;
    ifstream in("2105019_in.txt");
    while (!in.eof())
    {
        in>>info;
        if(info=='T'){
            in>>st;
            // cout<<st<<endl;
            if(st=="In"){
                b.inorder();
            }
            else if(st=="Pre"){
                b.preorder();
            }
            else if(st=="Post"){
                b.postorder();
            }
        }

        else if(info == 'I')
        {
            in>>val;
            // cout<<val<<endl;
            b.insert(val);
            b.Print();

        }
        else if(info == 'F'){
            in>>val;
            // cout<<val<<endl;
            if(b.find(val))
            out<<"found"<<endl;
            else
            out<<"not found"<<endl;
        }
        else if(info=='D'){
            in>>val;
            // cout<<val<<endl;
            b.Delete(val);
            b.Print();
        }
    }
    in.close();
    out.close();
    
}

int main(int argc, char const *argv[])
{
    int button;
    cout << "select your datatype: " << endl
         << "1.integer" << endl
         << "2.double" << endl
        
         << "3.character" << endl;
    cin >> button;
    getchar();
    switch (button)
    {
    case 1:
       
        task<int>();
        cout<<"completed"<<endl;
        break;
    case 2:
    task<double>();
        cout<<"completed"<<endl;
        break;
   

    case 3:
    task<char>();
        cout<<"completed"<<endl;
        break;
    default:
        break;
    }

    return 0;
}
