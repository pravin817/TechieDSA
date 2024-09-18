/*
    Company Tags : Amazon
    Leetcode Link : https : // leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

class Solution
{
public:
    // Brute Force solution : Check for the each pair in the vector
    // GIVES TLE
    vector<int> solution1(vector<int> &nums, int target)
    {
        int length = nums.size();

        for (int i = 0; i < length; ++i)
        {
            for (int j = i + 1; j < length; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i + 1, j + 1};
                }
            }
        }
        return {};
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(1)
    */

    // Solution 2 - By using the map for the storing the element along with the index and search for the (target- nums[i]), if the remaining found in the map then returns the indices.
    vector<int> solution2(vector<int> &nums, int target)
    {
        int length = nums.size();

        unordered_map<int, int> mp;

        // Traverse the complete array and simulatenously check if the remaining is present (find) in the map then return the indices of the two elements
        for (int i = 0; i < length; ++i)
        {
            int remaining = target - nums[i];

            if (mp.find(remaining) != mp.end())
            {
                // Found
                return {mp[remaining] + 1, i + 1}; // Indices starts from 1
            }
            else
            {
                // Insert the elements into the map
                mp[nums[i]] = i;
            }
        }
        return {}; // If the pair not found
    }
    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(N)
    */

    // Expected Solution : As the array is sorted in increasing order we can think of two pointer approach.
    vector<int> solution3(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high)
        {
            int sum = nums[low] + nums[high];

            if (sum == target)
                return {low + 1, high + 1};
            else if (sum < target)
                ++low;
            else
                --high;
        }

        return {};
    }
    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

    vector<int> twoSum(vector<int> &numbers, int target)
    {
        return solution3(numbers, target);
    }
};