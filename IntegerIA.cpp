#include "InfiniteArithmetic.hh"
#include <bits/stdc++.h>
using namespace std;
using namespace InfiniteArithmetic;

    // Finction to add 2 numbers manually...
    string Integer::add( string a,  string b)
    {
        string answer;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i--] - '0';
            }
            if (j >= 0)
            {
                sum += b[j--] - '0';
            }
            answer.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
    
    // Function to subtract 2 numbers manually...
    string Integer::subtract( string a, string b)
    {
        int k1=a.size();
        int k2=b.size();
        string a1=a.substr();
        string b1=b.substr();
        if(k1>k2){
            reverse(b1.begin(),b1.end());
            for(int i=0;i<k1-k2;i++){
                b1.push_back('0');
            }
            reverse(b1.begin(),b1.end());
        }else if(k2>k1){
            reverse(a1.begin(),a1.end());
            for(int i=0;i<k2-k1;i++){
                a1.push_back('0');
            }
            reverse(a1.begin(),a1.end());
        }

        if(a1.size()<b1.size() || a1<b1)
        {
            string answer;
            int borrow = 0;
            int i = b1.length() - 1;
            int j = a1.length() - 1;
            while (i >= 0 || j >= 0)
            {
                int diff = (i >= 0 ? b1[i--] - '0' : 0) - (j >= 0 ? a1[j--] - '0' : 0) - borrow;
                if (diff < 0)
                {
                    diff += 10;
                    borrow = 1;
                }
            else
            {
                borrow = 0;
            }
            answer.push_back(diff + '0');
            }
            // now removing extra front zeroes...
            while (answer.length() > 1 && answer.back() == '0')
            {
               answer.pop_back();
            }
            reverse(answer.begin(), answer.end());
            return '-' + answer;
        
        } else {
            string answer;
            int borrow = 0;
            int i = a1.length() - 1;
            int j = b1.length() - 1;
            while (i >= 0 || j >= 0)
            {
               int diff = (i >= 0 ? a1[i--] - '0' : 0) - (j >= 0 ? b1[j--] - '0' : 0) - borrow;
                if (diff < 0)
                {
                    diff += 10;
                    borrow = 1;
               }
               else
                {
                    borrow = 0;
                }
                answer.push_back(diff + '0');
            }
            // now removing extra front zeroes...
            while (answer.length() > 1 && answer.back() == '0')
            {
               answer.pop_back();
            }
            reverse(answer.begin(), answer.end());
            return answer;
        }
        
    }

    // multiplying string by single digit.
    // string string_multi_digit(const string &a, int digit)
    // {
    //     string answer;
    //     int carry = 0;
    //     for (int i = a.length() - 1; i >= 0; i--)
    //     {
    //         int product = (a[i] - '0') * digit + carry;
    //         answer.push_back(product % 10 + '0');
    //         carry = product / 10;
    //     }
    //     if (carry)
    //     {
    //         answer.push_back(carry + '0');
    //     }
    //     reverse(answer.begin(), answer.end());
    //     return answer;
    // }

    // Function to shift a number by designated number of places;
    string shift( string a, int places)
    {
        return a + string(places, '0');
    }

    string km_addd( string a,  string b)
    {
        string answer;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i--] - '0';
            }
            if (j >= 0)
            {
                sum += b[j--] - '0';
            }
            answer.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }

    string km_subtractt( string a, string b)
    {
        int k1=a.size();
        int k2=b.size();
        string a1=a.substr();
        string b1=b.substr();
        if(k1>k2){
            reverse(b1.begin(),b1.end());
            for(int i=0;i<k1-k2;i++){
                b1.push_back('0');
            }
            reverse(b1.begin(),b1.end());
        }else if(k2>k1){
            reverse(a1.begin(),a1.end());
            for(int i=0;i<k2-k1;i++){
                a1.push_back('0');
            }
            reverse(a1.begin(),a1.end());
        }

        if(a1.size()<b1.size() || a1<b1)
        {
            string answer;
            int borrow = 0;
            int i = b1.length() - 1;
            int j = a1.length() - 1;
            while (i >= 0 || j >= 0)
            {
                int diff = (i >= 0 ? b1[i--] - '0' : 0) - (j >= 0 ? a1[j--] - '0' : 0) - borrow;
                if (diff < 0)
                {
                    diff += 10;
                    borrow = 1;
                }
            else
            {
                borrow = 0;
            }
            answer.push_back(diff + '0');
            }
            // now removing extra front zeroes...
            while (answer.length() > 1 && answer.back() == '0')
            {
               answer.pop_back();
            }
            reverse(answer.begin(), answer.end());
            return '-' + answer;
        
        } else {
            string answer;
            int borrow = 0;
            int i = a1.length() - 1;
            int j = b1.length() - 1;
            while (i >= 0 || j >= 0)
            {
               int diff = (i >= 0 ? a1[i--] - '0' : 0) - (j >= 0 ? b1[j--] - '0' : 0) - borrow;
                if (diff < 0)
                {
                    diff += 10;
                    borrow = 1;
               }
               else
                {
                    borrow = 0;
                }
                answer.push_back(diff + '0');
            }
            // now removing extra front zeroes...
            while (answer.length() > 1 && answer.back() == '0')
            {
               answer.pop_back();
            }
            reverse(answer.begin(), answer.end());
            return answer;
        }
        
    }

    // Karatsuba multiplication for arbitrarily long numbers represented as strings
    string Karatsuba_Multiply(const string &x, const string &y)
    {
        int n = max(x.length(), y.length());
        if (n == 1)
        {
            return to_string((x[0] - '0') * (y[0] - '0'));
        }
        n = (n / 2) + (n % 2);
        string a = x.length() > n ? x.substr(0, x.length() - n) : "0";
        string b = x.length() > n ? x.substr(x.length() - n) : x;
        string c = y.length() > n ? y.substr(0, y.length() - n) : "0";
        string d = y.length() > n ? y.substr(y.length() - n) : y;

        string ac = Karatsuba_Multiply(a, c);
        string bd = Karatsuba_Multiply(b, d);
        string abcd = Karatsuba_Multiply(km_addd(a, b), km_addd(c, d));
        string middle = km_subtractt(km_subtractt(abcd, ac), bd);

        return km_addd(km_addd(shift(ac, 2 * n), shift(middle, n)), bd);
    }
    string Integer::multiply( string a,  string b)
    {
        string answer = Karatsuba_Multiply(a, b);
        reverse(answer.begin(),answer.end());
        while(answer.back() == '0' && answer.size() > 1)
        {
            answer.pop_back();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }

    // Function to compare sizes of strings...
    int compare( string num1,  string num2)
    {
        if (num1.size() > num2.size())
        {
            return 1;
        }
        if (num1.size() < num2.size())
        {
            return -1;
        }
        return num1.compare(num2);
    }

    string Integer::divide( string a,  string b)
    {
        // actual division function...
            if (b == "0")
            {
                return "Kidding huh ?! Anyways, division by zero is not allowed";
            }
            string answer;
            string remainder;
            for (char digit : a)
            {
                remainder += digit;
                int answerDigit = 0;
                while (compare(remainder, b) >= 0)
                {
                    remainder = subtract(remainder, b);
                    ++answerDigit;
                }
                answer += to_string(answerDigit);
            }
            // Removing the zeroes in the front...
            int start = answer.find_first_not_of('0');
            if (start != string::npos)
            {
                return answer.substr(start);
            }
            return "0";
    }

ostream& InfiniteArithmetic::operator<<(ostream &os,Integer c){
            os << c.value << endl;
            return os;
}