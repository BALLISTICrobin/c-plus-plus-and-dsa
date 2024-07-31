#include "dsa_stack.cpp"
#include <string>
#include <stdbool.h>

bool isValid(string paranthesis)
{
    //cout<<paranthesis.length()<<endl;
    int len = paranthesis.length();
    STACK<char> st1(20);
    for (int i = 0; i < len; i++)
    {
        if (paranthesis.at(i) == '(' || paranthesis.at(i) == '{' || paranthesis.at(i) == '[')
           {
            st1.push(paranthesis.at(i));
            //cout<<st1.Top()<<endl;
           } 
        else

        {   //cout<<st1.Top()<<endl;
            if (paranthesis.at(i) == ')')
            {

                char br = '(';
                if (br == st1.Top() && !st1.isEmpty())
                {
                    st1.pop();
                }
                else
                return false;
            }
            else if (paranthesis.at(i) == '}')
            {
                char br = '{';
                if (br == st1.Top()&& !st1.isEmpty())
                {
                    st1.pop();
                }
                else
                return false;
            }
            else if (paranthesis.at(i) == ']')
            {
                char br = '[';
                if (br == st1.Top()&& !st1.isEmpty())
                {
                    st1.pop();
                }
                else
                return false;
            }
            
        }
    }

    if(st1.isEmpty()){
        return true;
    }
    else
    return false;

    return true;
}

int main(int argc, char const *argv[])
{
    string bracket;
    cin >> bracket;
    if (isValid(bracket))
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "not valid" << endl;
    }
    return 0;
}
