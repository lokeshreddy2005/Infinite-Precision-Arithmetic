#ifndef InfiniteArithmetic_h
#define InfiniteArithmetic_h
#include <bits/stdc++.h>
using namespace std;
//Let's Go...
namespace InfiniteArithmetic{
class Integer
{
    private:
        string value;

        bool ValidInput(const string &str) const
        {
            return !str.empty() && all_of(str.begin() + (str[0] == '-' ? 1 : 0), str.end(), ::isdigit);
        }

        string add(string a, string b);
        string subtract(string a, string b);
        string multiply(string a, string b);
        string divide(string a, string b);

    public:
        Integer() : value("0") {} // default constructor

        Integer(const string &str) : value(str)
        {
            if (!ValidInput(str))
            {
                cerr << "You entered wrong format for the input" << endl;
                value = "0";
            }
        } // Actual constructor

        Integer(const Integer &other) : value(other.value) {} // copy constructor

        ~Integer()
        {
            // No memory allocated explicitly, so no task to free
        }

        static Integer parse(const string &str)
        {
            return Integer(str);
        }
        // overloading all 4 arithmetic operators for Integer class
        Integer operator+(const Integer &other) 
        {
            return Integer(add(value, other.value));
        }
        
        Integer operator-(const Integer &other) 
        {
            return Integer(subtract(value, other.value));
        }

        Integer operator*(const Integer &other) 
        {
            return Integer(multiply(value, other.value));
        }

        Integer operator/(const Integer &other)
        {
            return Integer(divide(value, other.value));
        }

        friend ostream &operator<<(ostream &os,Integer c);
        //friend string Karatsuba_Multiply(const string &x, const string &y);
        
};

//string Karatsuba_Multiply(const string &x, const string &y);

class Float
{
    
    private:
        string value;

        string addition(string a, string b);
        string subtraction(string a, string b);
        string multiplication(string a, string b);
        string division(string a, string b);


        bool ValidInput(const string &str) const
        {
            if (str.empty())
            {
                return false;
            }
            int check = 0;
            if (str[0] == '-' || str[0] == '+')
            {
                if (str.length() == 1)
                {
                    return false;
                }
                check = 1;
            }

            bool decimal_point_found = false;

            for (size_t i = check; i < str.length(); ++i)
            {
                if (str[i] == '.')
                {
                    if (decimal_point_found)
                    {
                        return false;
                    } 
                    decimal_point_found = true;
                }
                else if (!isdigit(str[i]))
                {
                    return false;
                }
            }

            return true;
        }

    public:
        Float() : value("0.0") {} // Default constructor

        Float(const string &str) : value(str)
        {
            if (!ValidInput(str))
            {
                cerr << "Invalid format for the input" << endl;
                value = "0.0";
            }
        } // Actual constructor

        Float(const Float &other) : value(other.value) {} // Copy constructor

        ~Float()
        {
            // No memory allocated explicitly, so no task to free
        }

        static Float parse(const string &str)
        {
            return Float(str);
        }

        // Overloading arithmetic operators for Float class
        Float operator+( Float &other)
        {
            return Float(addition(value, other.value));
        }

        Float operator-( Float &other) 
        {
            return Float(subtraction(value, other.value));
        }

        Float operator*( Float &other) 
        {
            return Float(multiplication(value, other.value));
        }

        Float operator/( Float &other) 
        {
            if (other.value == "0.0")
            {
                cerr << "Error: Division by zero" << endl;
                return Float("0.0");
            }
            return Float(division(value, other.value));
        }

        friend ostream &operator<<(ostream &os,Float c);

};

ostream &operator<<(ostream &os,Integer c);
        

ostream &operator<<(ostream &os,Float c);
        

}
#endif