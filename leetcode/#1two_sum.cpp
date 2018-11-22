/*
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* Example:
*   Given nums = [2, 7, 11, 15], target = 9,
*   Because nums[0] + nums[1] = 2 + 7 = 9,
*   return [0, 1].
*/


#include <iostream>
#include <string>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            int number = target - nums[i];
            
            //if number is found in map, return them
            if (hash.find(number) != hash.end()) {
                //+1 because indices are NOT zero based
                result.push_back(hash[number]);
                result.push_back(i);
                
                return result;
            }

            hash[nums[i]] = i;
        }
        
        cout << result << endl;
        return result;
    }
};

int main()
{
    /* code */
    Solution.twoSum(9);
}
