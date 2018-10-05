#include<iostream>
using namespace std;

class stack
{
  public:
  stack()
  {
    this->value = 0;
    this->next = NULL;
  }
  stack(char value)
  {
    this->value = value;
    this->next = NULL;
  }

  void push(stack **top , char value)
  {
    stack *ptr;
    ptr = new stack(value);

    if(*top == NULL)
    {
        *top = ptr;
    }
    else
    {
        ptr->next = *top;
        *top = ptr;
    }
  }

  int pop(stack **top)
  {
    stack *temp = *top;
    *top = (*top)->next;
    free(top);
    return temp->value;
  }

  char peak(stack *top)
  {
    if(top == NULL)
    {
      return 0;
    }
    else
    {
      return top->value;
    }
  }

  int precedence(char value)
  {
    if(value == '|')
    {
      return 1;
    }
    else if(value == '&')
    {
      return 2;
    }
    else if(value == '=' || value == '!' || value == '<' || value == '>')
    {
      return 3;
    }
    else if(value == '+' || value == '-')
    {
      return 4;
    }
    else if(value == '/' || value == '*')
    {
      return 5;
    }
    else if(value == '(')
    {
      return 0;
    }
    else
    {
      return 0;
    }
  }

  char value;
  
  private:
  stack *next;
};