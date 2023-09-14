class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) {
            return true;
        }
        long long int start = 2,  end = num/2;
        while (start <= end) {
            long long int mid = start + (end - start)/2;
            long long int ans = mid * mid;
            if (ans == num) {
                return true;
            }
            else if(ans <= num) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return false;
    }
};
/***************************************************/
/*This solution makes use of the fact that all square numbers are sum of odd numbers starting from 1.
For ex :
1 = 1
1+3 = 4
1 + 3 + 5 = 9
1 + 3 + 5 + 7 = 16
.... and so on
So i keep subtracting odd numbers from the given number, starting from 1. If the number eventually reaches 0, it is a 
perfect square. If it reaches a negative number without reaching 0 it is not a perfect square.
So the code goes like :*/

/*The given code implements an alternative approach to check whether a given number is a perfect square or not. 
The algorithm used in this implementation is based on the observation that the sum of the first n odd numbers is 
equal to n^2. Therefore, we can check if a number is a perfect square by subtracting the sum of the first n odd 
numbers from it until the result is zero or negative.
The implementation starts with i=1 and repeatedly subtracts the ith odd number from the given number until the number 
becomes zero or negative. The value of i is incremented by 2 after each subtraction to get the next odd number. If the 
number becomes zero, we return true indicating that it is a perfect square. Otherwise, we return false.
This implementation is correct and efficient since it uses a simple iterative algorithm without any complex mathematical 
operations. However, it may not be as fast as the binary search algorithm in the previous implementation for large inputs 
since it has a linear time complexity O(sqrt(num)).*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while(num>0){
            num -= i;      //Subtracting odd number from num and updating num
            i +=2;         // Updating i to the next odd number
            if(!num) return true;
        }
        return false;
    }
};