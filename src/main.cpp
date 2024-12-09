
#include <algorithm> // std::sort
#include <iostream>
#include <queue>
#include <unordered_map> // unordered_map (hash map)
#include <vector>        // vector

// TwoSum
using namespace std;
class Solution {

public:
  // Bucket Sort Solution
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  vector<int> topKFrequent(vector<int> &nums, int k) {

    // Create a new count has map
    unordered_map<int, int> count;
    // Create an array of arrays of same size as nums
    vector<vector<int>> freq(nums.size() + 1);

    // count occurence of nums
    for (int n : nums) {
      count[n] = 1 + count[n];
    }

    // Push each entry into the freq vector of vectors- Group together values by
    // count(into the same vector)) Add the number value to the "bucket"(which
    // is the count of the number)
    for (const auto &entry : count) {
      freq[entry.second].push_back(entry.first);
    }

    // create a new array for return value
    vector<int> res;

    // iterate through the freq "bucket" (vector of int vectors), starting with
    // the largest count/ highest array location
    for (int i = freq.size() - 1; i > 0; --i) {
      for (int n : freq[i]) {

        // Push bucket values into res array
        res.push_back(n);

        // If res array size == k return res
        if (res.size() == k) {
          return res;
        }
      }
    }

    // return res
    return res;
  }

  /*
    // Heap Solution
    // Time Complexity: O(nlogk)
    // Space Complexity: O(n+k)
    //  n is the length of the array and k is the number of top frequent
    elements

    vector<int> topKFrequent(vector<int> &nums, int k) {

      // Create a hash map named count
      unordered_map<int, int> count;

      // iterate through the numbers
      for (int num : nums) {

        // count the occurence of each number and add to the hash map
        count[num]++;
      }

      // Create a new heap(stores pair<int, int> values, underlying storage is a
      // vector, greater is comparison operator(min-heap))
      priority_queue<pair<int, int>, vector<pair<int, int>>,
                     greater<pair<int, int>>>
          heap;

      // Iterate through the count hash map
      for (auto &entry : count) {

        // for each numberentry in hash map, push a pair to the heap (count, num
        // value)

        heap.push({entry.second, entry.first});

        // If the heap size is greater than k, pop out the value
        if (heap.size() > k) {
          heap.pop();
        }
      }

      // Create a new array for the result
      vector<int> res;

      // pop the top k results(num value) from the heap and push to the result
      // array

      for (int i = 0; i < k; i++) {
        res.push_back(heap.top().second);
        heap.pop();
      }

      // return the result
      return res;
    }
  */
  /*
    // Sorting Solution
    // Time Complexity: O(nlogn)- due to sorting
    // Space Complexity: O(n)
    vector<int> topKFrequent(vector<int> &nums, int k) {

      // Create a new hash map: key int, value int
      unordered_map<int, int> count;

      // iterate through the nums array
      for (int num : nums) {

        // count the occurence of each number in the array
        count[num]++;
      }

      // create a array of pairs named arr
      vector<pair<int, int>> arr;

      // iterate through the count hash map
      for (const auto &p : count) {

        // Push pairs to arr (count value, number)
        arr.push_back({p.second, p.first});
      }

      // Sort the array by count value
      sort(arr.rbegin(), arr.rend());

      // Create a new array named res
      vector<int> res;

      // push k values to the res array from the pairs in the sorted array
      for (int i = 0; i < k; ++i) {
        // push the first k numbers to the result
        res.push_back(arr[i].second);
      }

      // Return the result
      return res;
    }
    */
};

int main() {

  Solution sol;

  vector<int> t_nums{1, 2, 2, 3, 3, 3};
  int t_k{2};

  vector<int> result = sol.topKFrequent(t_nums, t_k);

  for (auto x : result) {
    cout << x << "," << endl;
  }
  return 0;
}
