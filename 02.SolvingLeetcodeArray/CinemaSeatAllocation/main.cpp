/* A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as 
shown in the figure above.
Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] 
means the seat located in row 3 and labelled with 8 is already reserved.
Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four 
adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but 
there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group 
in the middle, which means to have two people on each side.

Example 1:
Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved 
and contiguous seats mark with orange are for one group.
Example 2:

Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2
Example 3:

Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4
 

Constraints:

1 <= n <= 10^9
1 <= reservedSeats.length <= min(10*n, 10^4)
reservedSeats[i].length == 2
1 <= reservedSeats[i][0] <= n
1 <= reservedSeats[i][1] <= 10
All reservedSeats[i] are distinct. */

//Solution:
/*If no Seat is Blocked in a row. We can allocate at most 2*n family in seat {2,3,4,5} and {6,7,8,9}
Now If in a row any of the seat {2,3,4,5} are taken no family can seat there , Similary for {6,7,8,9}
If {2 or 3} and {8 or 9} are taken but {4,5,6,7} are free we can arrange one extra family
As N is large we only look at the blocked seats . In code a vector pair is taken and sorted so that all seat in a row come 
together while iteration

Let ans=0
Total number of rows=t.
Total number of occupied rows=r;

Steps to find solution

Find number of occupied rows(r)

ans=ans+ (2*(t-r))
now iterate all occupied rows

if seats 2-9 are available add 2 to ans,
else if seats 2-5 or 4-7 or 6-9 are available add 1 to ans.*/

/*--------------------------------------------------------------------*/
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