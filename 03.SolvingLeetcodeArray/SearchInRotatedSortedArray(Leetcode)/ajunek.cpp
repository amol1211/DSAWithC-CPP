#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public :
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int start = 0, end = n-1;
        while (start < end) {
            int mid = start + (end - start)/2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        int pivot =  start;
        start = 0, end = n - 1;
        if (target >= nums[pivot] && target <= nums[end]) {
            start = pivot;
        } else {
            end = pivot - 1;
        }
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }

        }

        return -1;
    }
};
/*------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public :
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return nums[0] ==  target ? 0: -1;
        }

        int start = 0, end = n-1;
        while (start < end) {
            int mid = start + (end - start)/2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        int pivot = start;
        start = 0, end = n-1;
        if (target >= nums[pivot] && target <= nums[end]) {
            start = pivot;
        } else {
            end = pivot - 1;
        }
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end =  mid - 1;
            }
        }

        return -1;
    }
};

/*--------------------------------------------------------------------------*/
class Solution {
    public: 
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[start]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target <= nums[end] && target < nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
     }
};
/*--------------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[start]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target <= nums[end] && target > nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
/*---------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[start]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target <= nums[end] && target > nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
/*------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public: 
    int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] >= nums[start]) {
            if (target >= nums[start] && target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if (target <= nums[end] && target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}
};
/*------------------------------------------------------------------------------*/
