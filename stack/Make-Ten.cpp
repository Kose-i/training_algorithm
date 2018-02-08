#include <stack>
#include <iostream>
#include <string>
#include <locale>

class SudoDiv{
  private:
    int num;
    int den;
  public:
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

double RPN(std::string rpnStr)
{

  std::stack<SudoDiv> byteStack;
  SudoDiv t;
  char b;

  for(int i = 0,s = rpnStr.size();i < s;++i)
  {
    b = rpnStr[i];

    if(isspace(b))continue;

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

#include <cstring>

int first = 1;
char madeStr[7];
bool SolveTen(const std::string& fourNum, int num, int exp)
{
  static bool flag[4] ={false,false,false,false};

  if(num == 0 && exp == 0)
  {
    std::memset(flag,false,sizeof(bool)*4);
    std::memset(madeStr,0,sizeof(char)*4);
  }

  const int L = 7;
  if(num + exp == L)
  {
    const double E = 0.000001;

    double res;
    try{
      res = RPN(madeStr);
    }catch(const char* e) {
      std::cout << e << '\n';
      return false;
    }
    return (std::abs(res - 10) < E);
  }

  if(num - exp >= 2)
  {
    bool f;
    madeStr[num + exp] = '+';
    f = SolveTen(fourNum, num, exp + 1);
    if(f)
    {
      if(first)std::cout << madeStr << '\n';
      first = 0;
      return f;
    }
    madeStr[num + exp] = '*';
    f = SolveTen(fourNum,num,exp + 1);
    madeStr[num + exp]='/';
    f = SolveTen(fourNum,num,exp + 1);
    if(f)
    {
      if(first)std::cout << madeStr << '\n';
      first = 0;
      return f;
    }
  }

  if(num < 4)
  {
    for(int i = 0;i < 4;++i)
    {
      if(!flag[i])
      {
        flag[i] = true;
        madeStr[num+ exp]= fourNum[i];
        bool f = SolveTen(fourNum,num + 1,exp);
        if(f)return f;
        flag[i] = false;
      }
    }
  }
  return false;
}

int main()
{
  char a[4];
  for(int i = 0;i < 4;++i)
  {
    std::cin >> a[i];
    if(!isdigit(a[i]))
    {
      --i;
      continue;
    }
  }
  if( SolveTen(a, 0 , 0) )std::cout << "True\n";
  else std::cout << "False\n";
}
