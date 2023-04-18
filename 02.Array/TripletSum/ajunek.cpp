#include <bits/stdc++.h>
#include <set>
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    set<vector<int>>visited;
    vector<vector<int>> ans;

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == K) {
                    vector<int> triplet;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[j]);
                    triplet.push_back(arr[k]);

                    sort(triplet.begin(), triplet.end());
                    if (visited.find(triplet) == visited.end()) {
                        ans.push_back(triplet);
                        visited.insert(triplet);
                    }
                }
            }
        }
    }
    
    return ans;
}
/*-----------------------------------------------------------------------------*/
#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while(left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if(sum == K) {
                vector<int> temp = {arr[i], arr[left], arr[right]};
                ans.push_back(temp);
                left++;
                right--;
            } else if (sum < K) {
                left++;
            } else {
                right--;
            }
        }
    }
    if (ans.empty()) {
        return {{-1}};
    } else {
        return ans;
    }
}

/*------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
#include<set>
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
set<vector<int>>visited;
vector<vector<int>>ans;
for(int i = 0; i < n-2; i++) {
    for(int j = i+1; j < n-1; j++) {
        for(int k = j+1; k < n; k++) {

            if(arr[i] + arr[j] + arr[k] == K) {
                vector<int< triplet;
                triplet.push_back(arr[i]);
                triplet.push_back(arr[j]);
                triplet.push_back(arr[k]);

                sort(triplet.begin(), triplet.end());
                if(visited.find(triplet) == visited.end()) {
                    ans.push_back(triplet);
                    visited.insert(triplet);
                }
            }
        }
    }
}
return ans;
}
/*-----------------------------------------------------------------------------------*/

#include <bits/stdc++.h>
#include <set>

vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {

    set<vector<int>>visited;
    vector<vector<int>> ans;
    for(i = 0; i < n-2; i++) {
        for(j = i+1; j < n-1; j++) {
            for(k = j+1; k < n; k++) {
                
                if(arr[i] + arr[j] +  arr[k] == K) {
                    vector<int> triplet;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[j]);
                    triplet.push_back(arr[k]);

                    sort(triplet.begin(), triplet.end());
                    if(visited.find(triplet) == visited.end()) {
                        ans.push_back(triplet);
                        visited.insert(triplet);
                    }
                }
            }
        }
    }
    return ans;
}
/*---------------------------------------------------------------------*/
#include <bits/stdc++.h>
#include <set>

vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    set<vector<int>>visited;
    vector<vector<int>>ans;
    for(int i = 0; i < n - 2; i++) {
        for(int j = i+1; j < n -1; j++) {
            for(int k = j+1; k < n; k++) {

                if(arr[i] + arr[j] + arr[k] == K) {
                    vector<int>triplet;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[j]);
                    triplet.push_back(arr[k]);

                    sort(triplet.begin(), triplet.end());
                    if(visited.find(triplet) == visited.end()) {
                        ans.push_back(triplet);
                        visited.insert(triplet);
                    }
                }
            }
        }
    }
    return ans;
}

/*--------------------------------------------------------------------------*/

#include <bits/stdc++.h>

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n-2; i++) {
        int left = i + 1;
        int right = n - 1;

        while( left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == K) {
                vector<int> temp = {arr[i], arr[left], arr[right]};
                ans.push_back(temp);
                left++;
                right--;

                while(left < right && arr[left] == arr[left-1]) {
                    left++;
                }
                while(left < right && arr[right] == arr[right+1]) {
                    right--;
                }
            } else if(sum < K) {
                left++;
            } else {
                right--;
            }

        }
        while( i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return ans;
}

/*-------------------------------------------------------------------*/
#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int ans;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while(left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if(sum == K) {
                vector<int> temp = {arr[i], arr[left], arr[right]};
                ans.push_back(temp);
                left++;
                right--;

                while(left < right && arr[left] == arr[left - 1]) {
                    left++;
                }
                while(left < right && arr[right] == arr[right + 1]) {
                    right--;
                } 
            } else if(sum < K) {
                left++;
            } else {
                right--;
            }
        }
        while(i + 1 < n && arr[i] == arr[i +1]) {
            i++;
        }
    }
    return ans;
}
