class SudoDiv{
  private:
    int num;
    int den;
  public:
    //setter
    SudoDiv()
    {
      Set_Member(0,1);
    }
    SudoDiv(int numerator, int denominator)
    {
      Set_Member(numerator, denominator);
    }
    virtual ~SudoDiv(){}
    void Set_Member(int numerator, int denominator)
    {
      num = numerator;
      den = denominator;
    }

  public:
    void operator()(int numerator, int denominator)
    {
      Set_Member(numerator,denominator);
    }
    SudoDiv operator+(const SudoDiv& sd)
    {
      SudoDiv t;
      t.num = num*sd.den + sd.num*den;
      t.den = den*sd.den;
      return t;
    };
    SudoDiv operator-(const SudoDiv& sd)
    {
      SudoDiv t;
      t.num = num*sd.den - sd.num*den;
      t.den = den*sd.den;
      return t;
    };
    SudoDiv operator*(const SudoDiv& sd)
    {
      SudoDiv t;
      t.num = num*sd.num;
      t.den = den*sd.den;
      return t;
    };
    SudoDiv operator/(const SudoDiv& sd)
    {
      SudoDiv t;
      t.num = num*sd.den;
      t.den = den*sd.num;
      return t;
    };

    double getValue()
    {
      return num/(double)den;
    }
};

#include <stack>
#include <iostream>
#include <string>
#include <cctype>

double RPN(std::string rpnStr)
{

  std::stack<SudoDiv> byteStack;
  SudoDiv t;
  char b;

  for(int i = 0,s = rpnStr.size();i < s;++i)
  {
    b = rpnStr[i];

    if(b == ' ')continue;

    if(isdigit(b))
    {
      unsigned int n = b - '0';
      t(n,1);
      byteStack.push(t);
      continue;
    }

    if(byteStack.size() < 2)throw "Stack underflow : error";

    SudoDiv t1,t2;
    t1 = byteStack.top();
    byteStack.pop();
    t2 = byteStack.top();
    byteStack.pop();

    switch(b)
    {
      case '+':
      {
        byteStack.push(t2 + t1);
        break;
      }
      case '-':
      {
        byteStack.push(t2 - t1);
        break;
      }
      case '*':
      {
        byteStack.push(t2*t1);
        break;
      }
      case '/':
      {
        byteStack.push(t2/t1);
        break;
      }
      default:throw "Invalid operator : error";
    }
  }

  if(byteStack.size() != 1)throw "Invalid syntax : error";

  t = byteStack.top();
  byteStack.pop();

  return t.getValue();
}

int main()
{
  std::string target;
  std::getline(std::cin,target);
  double answer = RPN(target);
  std::cout << answer << '\n';
}
