#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& R) {
        map<int,vector<int>> M;
        for(int i=0;i<R.size();i++)
        {
           M[R[i][0]].push_back(R[i][1]);
        }
        int x=n-M.size();
        int ans=0;
        ans=x*2;
        for(auto it=M.begin();it!=M.end();it++)
        {
            vector<char> V(10,'E');
            for(int j=0;j<(it->second).size();j++)
            {
                V[((it->second)[j])-1]='B';
            }
            
            if(V[1]=='E' && V[2]=='E' && V[3]=='E' && V[4]=='E' &&V[5]=='E' && V[6]=='E' && V[7]=='E' && V[8]=='E')
            {
                ans=ans+2;
            }
            else
            {
                if(V[1]=='E' && V[2]=='E' && V[3]=='E' && V[4]=='E')
                    ans++;
                else if(V[3]=='E' && V[4]=='E' &&V[5]=='E' && V[6]=='E' )
                    ans++;
                else if(V[5]=='E' && V[6]=='E' && V[7]=='E' && V[8]=='E')
                    ans++;
            }
            
        }
    return ans;  
    }
};