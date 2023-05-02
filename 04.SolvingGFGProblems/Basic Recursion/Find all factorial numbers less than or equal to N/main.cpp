#include <iostream>
using namespace std;

class Solution
{
public:

    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
       vector< long long > ans = {1};
       for( int i = 1; i<= N ; i++ ){
           
           long long t = i * ans[i-1] ; 
           if( t > N)
             break;
           
           ans.push_back( t );
       }
       
           auto it = ans.begin();
       ans.erase(it);
       
       return ans;
      
    }
};

/*----------------OR-----------------------------------------*/

//User function Template for C++
//User function Template for C++
class Solution
{
public:
    vector<long long> factorialNumbers(long long N)
    {
        
        vector<long long> v;
        
        long long mul=1;
        
        for(int i=1;mul*i<=N;i++)
        {
            mul*=i;
            v.push_back(mul);
        }
        
        return v;
    }
};