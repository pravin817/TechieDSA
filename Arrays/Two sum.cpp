
/*
    Company Tags                : Zoho, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, FactSet, Hike, Adobe, Google, Wipro, SAP Labs, CarWale
    Leetcode Link               : https://leetcode.com/problems/two-sum/
*/

class Solution
{
public:
    // Brute Force solution : Check each pair of elements in the array
    // to see if their sum equals the target value.
    std::vector<int> solution1(std::vector<int> &nums, int target)
    {
        std::vector<int> result;
        int length = nums.size();

        for (int i = 0; i < length; ++i)
        {
            for (int j = i + 1; j < length; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(1)
    */

    // Optimized solution using a hash map:
    // Store elements in a map along with their indices, and for each new element, check if its remaining (target - element) exists in the map.
    std::vector<int> solution2(std::vector<int> &nums, int target)
    {
        int length = nums.size();
        // value -> idx
        std::unordered_map<int, int> mp;
        std::vector<int> result;

        // now traverse the all elements from the vector
        for (int i = 0; i < length; ++i)
        {
            int remaining = target - nums[i];
            if (mp.find(remaining) != mp.end())
            {
                // If the pair is found then
                result.push_back(mp[remaining]);
                result.push_back(i);
                break;
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return result;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(N)
    */

    vector<int> twoSum(vector<int> &nums, int target)
    {
        return solution2(nums, target);
    }
};