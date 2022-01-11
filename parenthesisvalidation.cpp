
#include <bits/stdc++.h>
using namespace std;

bool validateParenthesis(char s[])
{
    stack<char> stk;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
            stk.push(s[i]);
        else if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']'))
        {
            if (stk.empty())
                return false;

            else if ((s[i] == ')' && stk.top() != '(') || (s[i] == ']' && stk.top() != '[') || (s[i] == '}' && stk.top() != '{'))
                return false;

            else
                stk.pop();
        }
    }
    if (stk.empty())
        return true;
    else
        return false;
}

int main()
{
    char s[] = "(if(a%2==0)&&isprime(2)else){how}";
    if (validateParenthesis(s))
        cout << "Valid";
    else
        cout << "invalid";
    return 0;
}