
int removeDuplicates(vector<int> &nums) {
    int n = nums.size();

    if(n <= 1)
        return n;
    
    int i = 0; // pointer to track unique elements
    for(int j = 1; j < n; j++) {
        if(nums[j] != nums[i])
           nums[++i] = nums[j]; 
    } 
    return i + 1;
}