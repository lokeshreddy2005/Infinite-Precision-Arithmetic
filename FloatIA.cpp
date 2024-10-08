#include "InfiniteArithmetic.hh"
#include <bits/stdc++.h>
using namespace std;
using namespace InfiniteArithmetic;

    string Float::addition( string a, string b)
    {
        string before;
        string after;
        int k1 = 0,k2 = 0,c1 = 0,c2 = 0;
        for( int i = 0; i<a.size() ; i++ )
        {
            if( a[i] == '.' )
            {
                k1 = i;
                break;
            }else{
                c1++;
            }
        }
        for(int i = 0; i<b.size() ; i++ )
        {
            if( b[i] == '.' )
            {
                k2 = i;
                break;
            }else{
                c2++;
            }
        }
        
        if(c1 == a.length())
        {
            k1 = c1;
        }
        if(c2 == b.length())
        {
            k2 = c2;
        }

        string before1 = a.substr(0,k1);
        string before2 = b.substr(0,k2);
        string after1;
        string after2;
 
        if(k1 == a.length()){
            after1 = "";
        }else{
            after1 = a.substr(k1+1,a.size()-k1-1);
        }

        if(k2 == b.length()){
            after2 = "";
        }else{
            after2 = b.substr(k2+1,b.size()-k2-1);
        }

        int b1 = before1.length();
        int b2 = before2.length();
        int a1 = after1.length();
        int a2 = after2.length();

        if( a1 > a2 ){
             for(int i=0; i < a1-a2 ; i++ ){
                after2.push_back('0');
             }
        }else if( a1 < a2 ){
            for(int i=0; i<a2-a1 ; i++ ){
                after1.push_back('0');
            }
        }

        if( b1 > b2 ){
            reverse(before2.begin(),before2.end());
            for(int i=0; i<b1-b2 ; i++ ){
                before2.push_back('0');
            }
            reverse(before2.begin(),before2.end());
        }
        else if( b2 > b1 ){
            reverse(before1.begin(),before1.end());
            for(int i=0; i<b2-b1 ; i++ ){
                before1.push_back('0');
            }
            reverse(before1.begin(),before1.end());
        }

        int carry = 0;
        int i = after1.length()-1;
        int j = after2.length()-1;
        int x = before1.length()-1;
        int y = before2.length()-1;

        while (i >= 0 || j >= 0)
        {
            int sum = (i >= 0 ? after1[i--] - '0' : 0) + (j >= 0 ? after2[j--] - '0' : 0) + carry;
            if (sum>=10)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            after.push_back(sum + '0');
        }
        
        reverse(after.begin(),after.end());

        while (x >= 0 || y >= 0)
            {
               int sum = (x >= 0 ? before1[x--] - '0' : 0) + (y >= 0 ? before2[y--] - '0' : 0) + carry;
                if (sum >=10)
                {
                    sum -= 10;
                    carry = 1;
               }
               else
                {
                    carry = 0;
                }
                before.push_back(sum + '0');
            }
            if(carry == 1){
                before.push_back(carry + '0');
            }
            // now removing extra front zeroes...
            while (before.length() > 1 && before.back() == '0')
            {
               before.pop_back();
            }
            reverse(before.begin(), before.end());
            return before + '.' + after;
    }
string Float::subtraction( string a, string b)
    {
        string before;
        string after;
        int k1=0,k2=0,c1=0,c2=0;
        for(int i=0; i < a.size() ; i++ )
        {
            if(a[i] == '.')
            {
                k1 = i;
                break;
            }else{
                c1++;
            }
        }
        for(int i=0 ; i < b.size() ; i++ )
        {
            if(b[i] == '.')
            {
                k2 = i;
                break;
            }else{
                c2++;
            }
        }
        
        if(c1 == a.length())
        {
            k1 = c1;
        }
        if(c2 == b.length())
        {
            k2 = c2;
        }

        string before1 = a.substr(0,k1);
        string before2 = b.substr(0,k2);
        string after1;
        string after2;
 
        if(k1 == a.length()){
            after1 = "";
        }else{
            after1 = a.substr(k1+1,a.size()-k1-1);
        }

        if(k2 == b.length()){
            after2 = "";
        }else{
            after2 = b.substr(k2+1,b.size()-k2-1);
        }

        int b1 = before1.length();
        int b2 = before2.length();
        int a1 = after1.length();
        int a2 = after2.length();

        if(a1 > a2){
             for(int i=0 ; i < a1-a2 ; i++ ){
                after2.push_back('0');
             }
        }else if(a1 < a2){
            for(int i=0 ; i < a2-a1 ; i++ ){
                after1.push_back('0');
            }
        }

        if(b1 > b2){
            reverse(before2.begin(),before2.end());
            for(int i=0 ; i < b1-b2 ; i++ ){
                before2.push_back('0');
            }
            reverse(before2.begin(),before2.end());
        }
        else if (b2 > b1){
            reverse(before1.begin(),before1.end());
            for(int i=0 ; i < b2-b1 ; i++ ){
                before1.push_back('0');
            }
            reverse(before1.begin(),before1.end());
        }
        
        int borrow = 0;
        int i = after1.length()-1;
        int j = after2.length()-1;
        int x = before1.length()-1;
        int y = before2.length()-1;

        if(before1.size() < before2.size() || before1 < before2)
        {
            while (i >= 0 || j >= 0)
            {
                int diff = (j >= 0 ? after2[j--] - '0' : 0) - (i >= 0 ? after1[i--] - '0' : 0) - borrow;
                if (diff < 0)
                {
                    diff += 10;
                    borrow = 1;
                }
                else
                {
                    borrow = 0;
                }
                 after.push_back(diff + '0');
            }
            
            reverse(after.begin(),after.end());


            while (x >= 0 || y >= 0)
            {
                int diff = (y >= 0 ? before2[y--] - '0' : 0) - (x >= 0 ? before1[x--] - '0' : 0) - borrow;
                if (diff < 0)
                {
                    diff += 10;
                    borrow = 1;
                }else
                {
                   borrow = 0;
                }
                before.push_back(diff + '0');
            }
            // now removing extra front zeroes...
            while (before.length() > 1 && before.back() == '0')
            {
               before.pop_back();
            }
            reverse(before.begin(), before.end());
            return '-' + before +'.'+after;
        
        } else {
            while (i >= 0 || j >= 0)
            {
                int diff = (i >= 0 ? after1[i--] - '0' : 0) - (j >= 0 ? after2[j--] - '0' : 0) - borrow;
                if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            after.push_back(diff + '0');
        }
        
        reverse(after.begin(),after.end());
            while (x >= 0 || y >= 0)
            {
               int diff = (x >= 0 ? before1[x--] - '0' : 0) - (y >= 0 ? before2[y--] - '0' : 0) - borrow;
                if (diff < 0)
                {
                    diff += 10;
                    borrow = 1;
               }
               else
                {
                    borrow = 0;
                }
                before.push_back(diff + '0');
            }
            // now removing extra front zeroes...
            while (before.length() > 1 && before.back() == '0')
            {
               before.pop_back();
            }
            reverse(before.begin(), before.end());
            return before+'.'+after;
        }
          
    }

    // Finction to add 2 numbers manually...
    string km_add( string a,  string b)
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
    string km_subtract( string a,const string b)
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
    
// Function to shift a number by designated number of places;
string shifting( string a, int places)
    {
        return a + string(places, '0');
    }



// Karatsuba multiplication for arbitrarily long numbers represented as strings
string Karatsuba_Multiplication(const string &x, const string &y)
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

        string ac = Karatsuba_Multiplication(a, c);
        string bd = Karatsuba_Multiplication(b, d);
        string abcd = Karatsuba_Multiplication(km_add(a, b), km_add(c, d));
        string middle = km_subtract(km_subtract(abcd, ac), bd);

        return km_add(km_add(shifting(ac, 2 * n), shifting(middle, n)), bd);
    }

    
string Float::multiplication( string a,  string b)
    {
        int k1=0,k2=0,c1=0,c2=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='.')
            {
                k1=i;
                break;
            }else{
                c1++;
            }
        }
        for(int i=0;i<b.size();i++)
        {
            if(b[i]=='.')
            {
                k2=i;
                break;
            }else{
                c2++;
            }
        }

        if(c1==a.length())
        {
            k1=c1;
        }
        if(c2==b.length())
        {
            k2=c2;
        }

        int l1 = a.size()-k1-1;
        int l2 = b.size()-k2-1;
        string a1,b1;
        if(l1==-1){
            l1=0;
        }
        if(l2==-1){
            l2=0;
        }


        for(int i=0;i<a.size();i++){
            if(a[i]!='.'){
                a1.push_back(a[i]);
            }
        }
        for(int i=0;i<b.size();i++){
            if(b[i]!='.'){
                b1.push_back(b[i]);
            }
        }

        string answer = Karatsuba_Multiplication(a1, b1);
        reverse(answer.begin(),answer.end());
        string final_ans;
        for(int i=0;i<l1+l2;i++){
            final_ans.push_back(answer[i]);
        }
        final_ans.push_back('.');
        for(int i=l1+l2;i<answer.size();i++){
            final_ans.push_back(answer[i]);
        }
        // now removing extra front zeroes...
            while (final_ans.length() > 2 && final_ans.back() == '0')
            {
               final_ans.pop_back();
            }
        reverse(final_ans.begin(),final_ans.end());


        return final_ans;
    }

// Function to compare sizes of strings...
    int comparison( string num1,  string num2)
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

string Float::division(string a, string b)
    {
        if (b == "0")
            {
                return "Kidding huh ?! Anyways, division by zero is not allowed";
            }

        int k1=0,k2=0,c1=0,c2=0;
        string a1,b1,final_ans;
        for(int i=0;i<a.size();i++){
            if(a[i]=='.'){
                k1=i;
            }else{
                a1.push_back(a[i]);
                c1++;
            }
        }
        for(int i=0;i<b.size();i++){
            if(b[i]=='.'){
                k2=i;
            }else{
                b1.push_back(b[i]);
                c2++;
            }
        }

        if(c1==a.size()){
            k1=a.size();
        }
        if(c2==b.size()){
            k2=b.size();
        }

        int l1 = a.size()-k1-1;
        int l2 = b.size()-k2-1;

        if(l1==-1){
            l1=0;
        }
        if(l2==-1){
            l2=0;
        }

        for(int i=0;i<1000+l2-l1;i++){
            a1.push_back('0');
        }

        reverse(a1.begin(),a1.end());
        reverse(b1.begin(),b1.end());
        while(a1.back()=='0'){
            a1.pop_back();
        }
        while(b1.back()=='0'){
            b1.pop_back();
        }
        reverse(a1.begin(),a1.end());
        reverse(b1.begin(),b1.end());
        // actual division function...

            
            string answer; 
            string remainder="";
            int k=0,c=0;
            for (char digit : a1)
            {
                remainder += digit;
                int answerDigit = 0;

                while (comparison(remainder, b1) >= 0)
                {
                    remainder = km_subtract(remainder, b1);
                    
                    ++answerDigit;
                    if(comparison(remainder,b1)==0){
                        c=1;
                    }
                }
                answer += to_string(answerDigit);
                k++;
                if(c==1){
                    
                    for(int i=0;i<a1.size()-k;i++){
                        answer.push_back('0');
                    }
                    
                    break;
                }
                
            }
            

            reverse(answer.begin(),answer.end());
            for(int i=0;i<1000;i++){
                final_ans.push_back(answer[i]);
            }
            final_ans.push_back('.');
            for(int i=1000;i<answer.size();i++){
                final_ans.push_back(answer[i]);
            }
            while(final_ans.back()=='0'&&final_ans.size()>1&&final_ans[final_ans.size()-2]!='.'){
                final_ans.pop_back();
            }
            reverse(final_ans.begin(),final_ans.end());
            while(final_ans.back()=='0'&&final_ans[final_ans.size()-2]!='.'){
                final_ans.pop_back();
            }
            
            return final_ans;
    }

ostream& InfiniteArithmetic::operator<<(ostream &os,Float c){
            os << c.value << endl;
            return os;
}

// int main(){
//     Float f1("5.69");
//     Float f2("0.00");
//     cout<<f1+f2<<endl;
// }