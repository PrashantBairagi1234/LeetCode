class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
          int n = nums.size();
          

          for(int i = 0;i<n;i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
          }

    unordered_map<int, int> prefixSumCount;
    int count = 0;
    int currentSum = 0;

    // Initialize with prefix sum 0 to handle cases where the subarray starts at index 0.
    prefixSumCount[0] = 1;

    for (int num : nums) {
        currentSum += num;

        // Check if there exists a prefix sum such that currentSum - prefixSum = k
        if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - k];
        }

        // Increment the count of the current prefix sum
        prefixSumCount[currentSum]++;
    }

    return count;
          
    }
};