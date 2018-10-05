#include<iostream>
#include"stack.h"
using namespace std;

int main()
{
    stack *top = NULL;
    stack obj;
    cout << "Size of Equation: ";
    int size;
    cin >> size;
    cout << endl << "Infix: ";
    char postfix[size];
    char infix[size];
    int i , j = 0 , ascii;
    for(i = 0; i < size; i++)
    {
        infix[i] = getchar();
        ascii = infix[i];
        if(ascii >= 97 && ascii <= 122)
        {
            postfix[j] = infix[i];
            j++;
        }
        else
        {
            if(top == NULL)
            {
                obj.push(&top , infix[i]);
            }
            else
            {
                if(infix[i] == '(')
                {
                    obj.push(&top , infix[i]);
                }
                else if(infix[i] == ')')
                {
                    while(top->value != '(')
                    {
                        postfix[j] = obj.pop(&top);
                        j++;
                    }
                    obj.pop(&top);
                }
                else
                {
                    char temp_top = obj.peak(top);
                    int pre_top = obj.precedence(temp_top);
                    int pre_in = obj.precedence(infix[i]);

                    while(pre_in <= pre_top && top != NULL)
                    {
                        if(pre_in <= pre_top)
                        {
                            postfix[j] = obj.pop(&top);
                            j++;
                        }
                        temp_top = obj.peak(top);
                        pre_top = obj.precedence(temp_top);
                    }
                    obj.push(&top , infix[i]);
                }
            }
        }
    }
    cout << endl << "Postfix: ";
    while(top != NULL)
    {
        postfix[j] = obj.pop(&top);
        j++;
    }
    for(i = 0; i< size; i++)
    {
        cout << postfix[i];
    }
    cout << endl << endl;
    system("pause");
}