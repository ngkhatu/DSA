
#include <algorithm> // std::sort
#include <iostream>
#include <unordered_map> // unordered_map (hash map)
#include <vector>        // vector

using namespace std;
class Solution {

public:
  /*
  // Solution using Sorting
      vector<int> twoSum(const vector<int>& nums, const int target) {

          // Create a new array A of type pair<int, int>
          vector<pair<int, int>> A;

          // traverse nums
          for (int i = 0; i < nums.size(); i++) {

              // Push pair{value, index} into new array
              A.push_back({nums[i], i});
          }

          // sort the new Pair array (sort by nums[i])
          sort(A.begin(), A.end());


          // print out sorted array (sanity check)
          for(auto x: A){
              cout << x.first << ' ' << x.second << endl;
          }

          //initialize i and j (two pointers)
          int i = 0, j = nums.size() - 1;

          // iterate through  sorted A
          while (i < j) {

              // add both values
              int cur = A[i].first + A[j].first;

              // if added value equals target return the indices
              if (cur == target) {
                  return {min(A[i].second, A[j].second),
                          max(A[i].second, A[j].second)};
              }

              // if added value is less than the target increment i pointer
              else if (cur < target) {
                  i++;
              }

              // if added value is greater than the target decrement j pointer
              else {
                  j--;
              }
          }
          return {};
      }
      */

  vector<int> twoSum(vector<int> &nums, int target) {

    // size of nums
    int n = nums.size();

    // create unordered hash map
    unordered_map<int, int> prevMap;

    // iterate through nums
    for (int i = 0; i < n; i++) {
      // find difference between value and target
      int diff = target - nums[i];

      // Look for diff. If it exists in the hash map return indices
      if (prevMap.find(diff) != prevMap.end()) {
        return {prevMap[diff], i};
      }
      // if diff does not already exist, insert key/ value pair
      prevMap.insert({nums[i], i});

      // Sanity check... Print out values
      for (auto x : prevMap) {
        cout << x.first << ' ' << x.second << endl;
      }
      cout << "---" << "\n";
    }
    return {};
  }
};

int main() {

  Solution sol;

  vector<int> n{3, 5, 6, 2, 9};
  vector<int> targ = sol.twoSum(n, 7);

  for (auto x : targ) {
    cout << x << endl;
  }
  return 0;
}
