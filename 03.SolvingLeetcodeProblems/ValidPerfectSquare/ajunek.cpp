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
/*-------------------------------------------------------------------------------*/

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