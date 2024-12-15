
#include <algorithm> // std::sort
#include <iostream>
#include <queue>
#include <unordered_map> // unordered_map (hash map)
#include <vector>        // vector

// TwoSum
using namespace std;
class Solution {
public:
  // Prefix and Suffix (Optimal)
  // Time Complexity- O(n)
  // Space Complexity- O(1) since the output array is excluded from space
  // analysis
  vector<int> productExceptSelf(vector<int> &nums) {

    // n is size of array
    int n = nums.size();

    // Create result vector and set to all 1s
    vector<int> res(n, 1);

    // iterate starting at 1
    // Set result = previous res * previous nums
    for (int i = 1; i < n; i++) {
      res[i] = res[i - 1] * nums[i - 1];
    }

    // postfix = 1
    int postfix = 1;

    // iterate through res and nums backwards
    for (int i = n - 1; i >= 0; i--) {
      res[i] *= postfix;
      postfix *= nums[i];
    }
    return res;
  }
};

/*
// Prefix and Suffix
// Time Complexity- O(n)
// Space Complexity- O(n)
    vector<int> productExceptSelf(vector<int>& nums) {

        // size of array
        int n = nums.size();
        // Create result array
        vector<int> res(n);
        // Create prefix array
        vector<int> pref(n);
        // Create suffix array
        vector<int> suff(n);

        // Set prefix[0] = 1
        pref[0] = 1;

        // Set last value in suffix array = 1
        suff[n - 1] = 1;

        // iterate nums
        // set prefix array = previous nums * previous prefix
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }

        // Set i to second to last, traverse suffix in reverse order
        // set suffix array = previous next nums * next suffix
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i + 1] * suff[i + 1];
        }
        // set result = pref * suff
        for (int i = 0; i < n; i++) {
            res[i] = pref[i] * suff[i];
        }
        return res;
    }
};
*/

/*
// Division
// Time Complexity- O(n)
// Space Complexity- O(1) since the output array is excluded from space
analysis. vector<int> productExceptSelf(vector<int>& nums) {

        // initialize prod and zeroCount
        int prod = 1, zeroCount = 0;


        // iterate through nums. Find product of all nonzero numbers
        for (int num : nums) {

            // if value is nonzero, multiply
            if (num != 0) {
                prod *= num;
            }
            // if value is zero, increment zeroCount
            else {
                zeroCount++;
            }
        }

        // Corner Case- If there are 2 or more zeros, return all zeros
        if (zeroCount > 1) {
            return vector<int>(nums.size(), 0);
        }

        // Create new vector for result
        vector<int> res(nums.size());

        // iterate through result array
        for (size_t i = 0; i < nums.size(); i++) {

            // if the zeroCount is 1:
            // implies there is at least one zero somewhere
            if (zeroCount > 0) {
                // for result where num is zero, use product value
                // for result where num is non-zero, use zero
                res[i] = (nums[i] == 0) ? prod : 0;
            } else {
                // If there are no zeros anywhere, divide prod by nums[i] to get
res res[i] = prod / nums[i];
            }
        }
        return res;
    }
*/

/*
    // Brute Force
    // Time Complexity- O(n^2)
    // Space Complexity- O(1) since output array is excluded from space analysis
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        // Nested For Loop
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    prod *= nums[j];
                }
            }
            res[i] = prod;
        }
        return res;
    }

*/

int main() { return 0; }
