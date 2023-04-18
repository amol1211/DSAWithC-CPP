//1.1
class solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int> ans;

        for(int i=0; i < nums.size(); i++) {
            if(nums[abs(num[i])-1]<0)
            ans.push_back(abs(num[i]));
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }

        return ans;
    }
};
//1.2
class solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return{};
        vector<int> ans;

        for(int i = 0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1]<0)
            ans.push_back(abs(nums[i]));
            nums.[abs(nums[i])-1]= -nums[abs(num[i])-1];
        }
    return ans;
    }
};
//1.3
class solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return {};

        vector<int> ans;

        for(int i=0; i<nums.size();i++) {
            if(nums[abs(nums[i])-1]<0)
            ans.push_back(abs(num[i]));
            nums[abs(nums[i])-1] =-nums[abs(nums[i])-1];
        }

        return ans;
    }

};

//1.4
class solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return {};

        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            if(nums[abs(num[i])-1]<0)
            ans.push_back(abs(num[i]));
            nums[abs(num[i])-1]= -nums[abs(num[i])-1];
        }

        return ans;
    }
};

//2.1

class solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return {};

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            for(int j= i+1; j < nums.size(); j++) {
                if(nums[i] != nums[j]) continue;
                else{
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        return ans;
    }
}

//2.2

class solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return {};

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] != nums[j]) continue;
                else {
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        return ans;
    }
};


//3.1
vector<int> findDuplicates(vector<int>& nums) {
    // If input vector is empty, return an empty vector
    if (nums.empty()) {
        return {};
    }
    
    // Create an empty vector to store the duplicates
    vector<int> ans;
    
    // Sort the input vector in non-descending order
    sort(begin(nums), end(nums));
    
    // Initialize s to the first element in the vector
    int s = nums[0];
    
    // Traverse the input vector
    for (int i = 1; i < nums.size(); i++) {
        // If the current element is equal to the previous element, it is a duplicate
        if (s == nums[i]) {
            // Add the duplicate element to the answer vector
            ans.push_back(nums[i]);
            
            // Skip the next element since we know it is a duplicate
            i += 1;
            
            // If there are more elements in the vector, update the value of s to the next element
            if (i < nums.size()) {
                s = nums[i];
            } else {
                break;
            }
        }
        // Otherwise, update the value of s to the current element
        else {
            s = nums[i];
        }
    }
    
    // Return the answer vector
    return ans;
};

//3.2
class solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return {};

        vector<int> ans;

        sort(begin(nums), end(nums));

        int s = nums[0];

        for(int i =1; i < nums.size(); i++) {
            if(s == nums[i]) {
                ans.push_back(nums[i]);

                i+=1;

                if(i < nums.size()) {
                    s = nums[i];
                }
                else{
                    break;
                }
            }
            else{
                s = nums[i];
            }
        }
        return ans;
    }
};

//3.3
class solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return {};

        vector<int> ans;

        sort(begin(nums),end(nums));

        int s = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if( s == nums[i]) {
                ans.push_back(nums[i]);

                i+= 1;

                if(i < nums.size()) {
                    s = nums[i];
                }
                else{
                    break;
                }
            }
            else{
                s = nums[i];
            }
        }
        return ans;
        
    }
};

//3.4
class solution {
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return{};

        vector<int> ans;
        sort(begin(nums), end(nums));
        s = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            if(s == nums[i]) {
                ans.push_back(nums[i]);

                i+=1;
                if(s < nums.size()) {
                    s = nums[i]; continue;
                }else{
                    break;
                }
            }else{
            s = nums[i];
            }
        }
        return ans;
    }
    
};
