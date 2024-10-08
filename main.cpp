#include <iostream>
#include<algorithm>
#include<string>
#include "InfiniteArithmetic.hh"
//#include"FloatIA.cpp"
//#include"IntegerIA.cpp"
using namespace std;
using namespace InfiniteArithmetic;

int main(int argc,char *argv[])
{
    string num1 = argv[3];
    string num2 = argv[4];
    string type = argv[1];
    string operation = argv[2];
    int k1 = 0,k2 = 0;

    if(type == "int")
    {
        if(num1[0] == '-')
        {
            k1 = 0;
            reverse(num1.begin(),num1.end());
            num1.pop_back();
            reverse(num1.begin(),num1.end());
        }else if(num1[0]=='+')
        {
            k1 = 1;
            reverse(num1.begin(),num1.end());
            num1.pop_back();
            reverse(num1.begin(),num1.end());
        }else
        {
            k1 = 1;
        }

        if(num2[0] == '-')
        {
            k2 = 0;
            reverse(num2.begin(),num2.end());
            num2.pop_back();
            reverse(num2.begin(),num2.end());
        }else if(num2[0] == '+')
        {
            k2 = 1;
            reverse(num2.begin(),num2.end());
            num2.pop_back();
            reverse(num2.begin(),num2.end());
        }else
        {
            k2 = 1;
        }

        Integer a(num1);
        Integer b(num2);


        if(operation == "add")
        {
            if(k1 == 0&&k2 == 0)
            {
                Integer c = a+b;
                cout << "-" ;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 0)
            {
                Integer c = a-b;
                cout << c << endl;
            }else if(k1 == 0 && k2 == 1)
            {
                Integer c = b-a;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 1)
            {
                Integer c = a+b;
                cout << c << endl;
            }
        }
        else if(operation == "sub")
        {
            if(k1 == 0 && k2 == 0)
            {
                Integer c = b-a;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 0)
            {
                Integer c = a+b;
                cout << c << endl;
            }else if(k1 == 0 && k2 == 1)
            {
                Integer c = a+b;
                cout << "-" ;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 1)
            {
                Integer c = a-b;
                cout << c << endl;
            }
        }
        else if(operation == "mul")
        {
            if(k1 == 0 && k2 == 0)
            {
                Integer c = a*b;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 0)
            {
                Integer c = a*b;
                cout << "-" ;
                cout << c << endl;
            }else if(k1 == 0 && k2 == 1)
            {
                Integer c = a*b;
                cout << "-";
                cout << c << endl;
            }else if(k1 == 1 && k2 == 1)
            {
                Integer c = a*b;
                cout << c << endl;
            }
        }
        else if(operation == "div")
        {
            if(k1 == 0 && k2 == 0)
            {
                Integer c = a/b;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 0)
            {
                Integer c = a/b;
                cout << "-";
                cout << c << endl;
            }else if(k1 == 0 && k2 == 1)
            {
                Integer c = a/b;
                cout << "-" ;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 1)
            {
                Integer c = a/b;
                cout << c << endl;
            }
        }
        else
        {
            cout << "Ohh! You should enter only any one of these as arguments \n (I)add \n (II)sub \n (III)mul \n (IV)div " << endl;
        }

    }
    else if(type == "float")
    {
        if(num1[0] == '-')
        {
            k1 = 0;
            reverse(num1.begin(),num1.end());
            num1.pop_back();
            reverse(num1.begin(),num1.end());
        }else if(num1[0] == '+')
        {
            k1 = 1;
            reverse(num1.begin(),num1.end());
            num1.pop_back();
            reverse(num1.begin(),num1.end());
        }else
        {
            k1 = 1;
        }

        if(num2[0] == '-')
        {
            k2 = 0;
            reverse(num2.begin(),num2.end());
            num2.pop_back();
            reverse(num2.begin(),num2.end());
        }else if(num2[0] == '+')
        {
            k2 = 1;
            reverse(num2.begin(),num2.end());
            num2.pop_back();
            reverse(num2.begin(),num2.end());
        }else
        {
            k2 = 1;
        }

        Float a(num1);
        Float b(num2);


        if(operation == "add")
        {
            if(k1 == 0 && k2 == 0)
            {
                Float c = a+b;
                cout << "-";
                cout << c << endl;
            }else if(k1 == 1 && k2 == 0)
            {
                Float c = a-b;
                cout << c << endl;
            }else if(k1 == 0 && k2 == 1)
            {
                Float c = b-a;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 1)
            {
                Float c = a+b;
                cout << c << endl;
            }
        }
        else if(operation == "sub")
        {
            if(k1 == 0 && k2 == 0)
            {
                Float c = b-a;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 0)
            {
                Float c = a+b;
                cout << c << endl;
            }else if(k1 == 0 && k2 == 1)
            {
                Float c = a+b;
                cout << "-";
                cout << c << endl;
            }else if(k1 == 1 && k2 == 1)
            {
                Float c = a-b;
                cout << c << endl;
            }
        }
        else if(operation == "mul")
        {
            if(k1 == 0 && k2 == 0)
            {
                Float c = a*b;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 0)
            {
                Float c = a*b;
                cout << "-";
                cout << c << endl;
            }else if(k1 == 0 && k2 == 1)
            {
                Float c = a*b;
                cout << "-";
                cout << c << endl;
            }else if(k1 == 1 && k2 == 1)
            {
                Float c = a*b;
                cout << c << endl;
            }
        }
        else if(operation == "div")
        {
            if(k1 == 0 && k2 == 0)
            {
                Float c = a/b;
                cout << c << endl;
            }else if(k1 == 1 && k2 == 0)
            {
                Float c = a/b;
                cout << "-";
                cout << c << endl;
            }else if(k1 == 0 && k2 == 1)
            {
                Float c = a/b;
                cout << "-";
                cout << c << endl;
            }else if(k1 == 1 && k2 == 1)
            {
                Float c = a/b;
                cout << c << endl;
            }
        }
        else
        {
            cout << "Ohh! You should enter only any one of these as arguments \n (I)add \n (II)sub \n (III)mul \n (IV)div " << endl;
        }

    }
    else
    {
        cout << "Ohh! You should enter only integer(int) or float(float) types" << endl;
    }

    return 0;
}