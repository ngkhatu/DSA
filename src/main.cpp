
#include <algorithm> // std::sort
#include <iostream>
#include <unordered_map> // unordered_map (hash map)
#include <vector>        // vector

// TwoSum
using namespace std;
class Solution {

public:
  // Sorting Solution
  // Time complexity: O(m*nlogn)
  // Space complexity: O(m*n)
  // m is the number of strings and n is the length of the longest string
  vector<vector<string>> groupAnagrams(vector<string> &strs) {

    // Create a new hash map named res
    unordered_map<string, vector<string>> res;

    // for each given string- use the sorted string as the key and push the
    // string.
    for (const auto &s : strs) {
      // copy string to a new variable
      string sortedS = s;
      // sort the string by character
      sort(sortedS.begin(), sortedS.end());
      // Push the sorted string to the hash map
      res[sortedS].push_back(s);
    }

    // Build the resulting vector of string vectors
    vector<vector<string>> result;
    for (auto &pair : res) {
      result.push_back(pair.second);
    }

    // return the vector of string vectors
    return result;
  }

  // Hash Table solution
  // Time complexity: O(m*n)
  // Space complexity: O(m)
  // m is the number of strings and n is the length of the longest string

  /*
      vector<vector<string>> groupAnagrams(vector<string>& strs) {

          // create a new hash map named res
          // key- string, value- vector<string>
          unordered_map<string, vector<string>> res;

          // iterate through strings to put them into the res hash map
          for (const auto& s : strs) {

              // Create a vector to keep count of each char in the string
              vector<int> count(26, 0);
              for (char c : s) {
                  count[c - 'a']++;
              }

              // Create a unique string key for each anagram
              string key = to_string(count[0]);
              for (int i = 1; i < 26; ++i) {
                  key += ',' + to_string(count[i]);
              }

              // Push the string value to the hash map using the created key
              res[key].push_back(s);
          }


          // Create a new vector of string vectors named result(for return)
          vector<vector<string>> result;

          // for each key/ value pair. pop the anagram group values into the
     vector of vector strings for (const auto& pair : res) {
              result.push_back(pair.second);
          }

          // return value
          return result;
      }
  */
};

int main() {

  Solution sol;

  vector<string> test_str{"act", "pots", "tops", "cat", "stop", "hat"};

  vector<vector<string>> result = sol.groupAnagrams(test_str);

  for (auto x : result) {
    for (auto s : x) {
      cout << s << "," << endl;
    }
    cout << "-->" << endl;
  }
  return 0;
}
