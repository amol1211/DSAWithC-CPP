#include <bits/stdc++.h>
void sort012(int *arr, int n) {
    int low = 0;
    int mid = 0;
    int high = 0;

    for(int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            low++;
        } else if (arr[i] == 1) {
            mid++;
        } else {
            high++;
        }
    }

    for(j = 0; j < n; j++) {
        if (j < low) {
            arr[j] = 0;
        } else if (j < low + mid) {
            arr[j] = 1;
        } else {
            arr[j] = 2;
        }
    }
}

/*----------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
void sort012(int *arr, int n) {
    int low = 0;
    int mid = 0;
    int high = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
                low++;
            } else if (arr[i] == 1) {
                mid++;
            } else {
                high++;
            }
        }

        for(int j = 0; j < n; j++) {
            if(j < low) {
                arr[j] = 0;
            } else if (j < low + mid) {
                arr[j] = 1;
            } else {
                arr[j] = 2;
            }
        }
    }
/*---------------------------------------------------------*/
#include <bits/stdc++.h>
void sort012(int *arr, int n) {
    int low = 0;
    int mid = 0;
    int high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            low++;
        } else if (arr[i] == 1) {
            mid++;
        } else {
            high++;
        }
    }

    for(int j = 0; j < n; j++) {
        if (arr[j] < low) {
            arr[j] = 0;
        } else if (j < low + mid) {
            arr[j] = 1;
        } else {
            arr[j] = 2;
        }
    }
}
/*---------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

/*------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n) {

int low = 0;
int mid = 0;
int high = n - 1;

while (mid <= high) {
    if(arr[mid] == 0) {
        swap(arr[low], arr[mid]);
        low++;
        mid++;
    } else if (arr[mid] == 1) {
        mid++;
    } else {
        swap(arr[mid], arr[high]);
        high--;
    }
}
}
/*-------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while(mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
