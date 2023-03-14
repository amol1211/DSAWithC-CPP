#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            studentCount++;
            if(studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
    }
    return true;

}

int allocateBooks(vector<int> arr, int n, int m) {
    int start = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end - start)/2;

    while (start <= end) {
        if (isPossible(arr,n,m,mid)) {

            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

/*---------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else 
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid) {
            return false;
            }
            pageSum = arr[i];
        }
        if (studentCount > m) {
            return false;
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int start = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end - start)/2;

    while (start <= end) {
        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
/*--------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid) {
    
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            studentCount++;
            if(studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
        if (studentCount > m) {
            return false;
        }
    }
    return true;
}



int allocateBooks(vector<int> arr, int n, int m) {
    int start = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end - start)/2;

    while (start <= end) {
        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

/*-------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            studentCount++;
            if (studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
    }
    return true;
}

int allooacteBooks(vector<int> arr, int n, int m) {
    int start = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end - start)/2;

    while(start <= end) {
        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}