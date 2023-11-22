#include <iostream>
#include <stack>
#include<cmath>
using namespace std;
int main()
{
    stack<int> st;
    string exp;
    cout << "Enter the Postfix Expression you want to evaluate.  ";
    cin >> exp;
    for (int i = 0; i < exp.size(); ++i)
    {
        if (isdigit(exp[i]))
        {
            st.push(exp[i] - '0');
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (exp[i])
            {
                {
                case '+':
                    st.push(b + a);
                    break;
                case '-':
                    st.push(b - a);
                    break;
                case '*':
                    st.push(b * a);
                    break;
                case '/':
                    st.push(b / a);
                    break;
                case '^':
                    st.push(pow(b,a));
                }
            }
        }
    }
    cout << st.top()<<endl;
}