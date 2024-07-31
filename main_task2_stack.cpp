#include "stack_offline.cpp"
#include <cctype>

int prec(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
        return -1;
}

// template <class T>
// void infixToPostfix(STACK<T> &st,string str){
//     STACK<char> oper;
//     for(int i=0;i<str.length();i++){
//         if(str[i]>='0' && str[i]<='9'){
//             st.push(str[i]);
//         }
//         else if(str[i]=='('){
//             st.push(str[i]);
//         }
//         else if(str[i]==')'){
//             while(true){

//                 if(oper.topValue()!='('){
//                 st.push(oper.topValue());
//                 oper.pop();
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         else{

//         }
//     }

// }
int count_opr, count_oprnd;
double sum;
double infixEval(string expression)
{
    STACK<char> opr;
    STACK<double> opnd;
    int i = 0;

    while (i < expression.length())
    {
        // cout<<i<<endl;

        if (isdigit(expression[i]))
        {
            //    cout<<"hello1"<<endl;

            double num = 0.00;

            while (isdigit(expression[i]) && i < expression.length())
            {

                num = num * 10.00 + (expression[i] - '0');
                i++;
            }
            i--;
            opnd.push(num);
            // cout<<opnd.topValue()<<endl;
        }
        else if (expression[i] == '(')
        {
            // cout<<"hello"<<endl;
            opr.push('(');
            if (expression[i + 1] != '-')
                opr.push('+');
            opnd.push(0.00);
            // cout<<opr.topValue()<<" "<<opnd.topValue()<<endl;
        }
        else if (expression[i] == ')' && opr.isEmpty() == false)
        {
            // cout<<"hello2"<<endl;
            while (true)
            {
                if (opr.topValue() != '(' && opr.isEmpty() == false)
                {

                    double op1, op2;
                    op2 = opnd.pop();
                    op1 = opnd.pop();
                    switch (opr.topValue())
                    {
                    case '+':
                        opnd.push(op1 + op2);
                        break;
                    case '-':
                        opnd.push(op1 - op2);
                        break;
                    case '*':
                        opnd.push(op1 * op2);
                        break;
                    case '/':
                        opnd.push(op1 / op2);
                        break;

                    default:
                        break;
                    }
                    opr.pop();
                }
                else if (opr.topValue() == '(')
                {
                    opr.pop();
                    break;
                }
                else
                    break;
            }
        }
        else
        {
            // cout<<"hello3"<<endl;
            if (prec(expression[i]) > prec(opr.topValue()) || opr.isEmpty() == true)
            {
                opr.push(expression[i]);
                // cout<<opr.topValue()<<endl;
            }
            else
            {
                while (true)
                {

                    if (prec(expression[i]) <= prec(opr.topValue()) && opr.isEmpty() == false)
                    {
                        double op1, op2;
                        op2 = opnd.pop();
                        op1 = opnd.pop();
                        switch (opr.topValue())
                        {
                        case '+':
                            opnd.push(op1 + op2);
                            break;
                        case '-':
                            opnd.push(op1 - op2);
                            break;
                        case '*':
                            opnd.push(op1 * op2);
                            break;
                        case '/':
                            opnd.push(op1 / op2);
                            break;

                        default:
                            break;
                        }
                        opr.pop();
                    }

                    else
                    {
                        opr.push(expression[i]);
                        break;
                    }
                }
            }
        }
        i++;
        // cout<<"hello4"<<endl;
    }
    count_opr = opr.length();
    count_oprnd = opnd.length();
    // double sum = 0;
    if (opr.isEmpty() == true)
    {
        while (opnd.isEmpty() == false)
        {
            sum += opnd.pop();
        }
        return sum;
    }
    else
    {
        while (!opr.isEmpty())
        {
            double op1, op2;
            op2 = opnd.pop();
            op1 = opnd.pop();
            switch (opr.topValue())
            {
            case '+':
                opnd.push(op1 + op2);
                break;
            case '-':
                opnd.push(op1 - op2);
                break;
            case '*':
                opnd.push(op1 * op2);
                break;
            case '/':
                opnd.push(op1 / op2);
                break;

            default:
                break;
            }
            opr.pop();
        }
        sum = opnd.topValue();
        return sum;
        // cout << "result " << opnd.topValue() << endl;
    }
}

bool checkValid(string expression)
{
    if(expression[0]=='+'||expression[0]=='*'||expression[0]=='/'||expression[0]=='-')
    return false;
    int count = 0, fulfilled_requirement = 0;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if (isdigit(ch) || ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            count++;
    }
    if (count == expression.length())
        fulfilled_requirement++;

    STACK<char> bracket;
    // cout<<fulfilled_requirement<<endl;
    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if (c == '(')
        {
            bracket.push(c);
        }

        else if (c == ')')
        {
            if (bracket.topValue() == '(')
            {
                bracket.pop();
            }
            else if (bracket.isEmpty())
                return false;
        }
    }
    if (bracket.isEmpty())
        fulfilled_requirement++;

    // if(count_opr==0 && count_oprnd==0){
    //     fulfilled_requirement++;
    // }

    if (count_opr + 1 == count_oprnd)
        fulfilled_requirement++;

    int count_correspondent_bracket = 0,count_rep_optr=0,count_brac_op=0;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(' && expression[i + 1] == ')')
        {
            count_correspondent_bracket++;
            break;
        }
        else if (expression[i] == ')' && expression[i + 1] == '(')
        {
            count_correspondent_bracket++;
            break;
        }
        
        else if((expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/')&&(expression[i+1]=='+'||expression[i+1]=='-'||expression[i+1]=='*'||expression[i+1]=='/'))
        {
            count_rep_optr++;
            break;
        }
        else if(expression[i]=='('&&(expression[i+1]=='+'||expression[i+1]=='*'||expression[i+1]=='/'))
        {
            count_brac_op++;
            break;
        }

    }
    if (count_correspondent_bracket == 0)
        fulfilled_requirement++;

    if(count_rep_optr==0)
    fulfilled_requirement++;

    if(count_brac_op==0)
    fulfilled_requirement++;
    // cout<<fulfilled_requirement<<endl;
    if (fulfilled_requirement == 6)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{

    while (true)
    {
        count_opr = 0, sum = 0;
        count_oprnd = 0;
        string expression;
        cin >> expression;
        double z = infixEval(expression);
        if (checkValid(expression))
        {
            cout << "Valid Expression" << endl;
            cout <<"result "<< z << endl;
        }
        else
            cout << "Not Valid" << endl;
    }
    return 0;
}
