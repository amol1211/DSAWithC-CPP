class Solution {
public:
    int addDigits(int num) {
        
        // Initialize a variable to store the digital root of the number.
        int digitalRoot = 0;
        
        // Loop until the number becomes zero.
        while (num > 0) {
            
            // Extract the last digit of the number and add it to the digitalRoot.
            digitalRoot += num % 10;
            
            // Remove the last digit from the number.
            num = num / 10;

            // If the number becomes zero and the digitalRoot is greater than 9 (two or more digits),
            // set the number to digitalRoot and reset digitalRoot to 0 to continue the process.
            if (num == 0 && digitalRoot > 9) {
                num = digitalRoot;
                digitalRoot = 0;
            }
        }
        
        // Once the loop ends, the value of digitalRoot will be the final digital root of the input number.
        return digitalRoot;
    }
};
