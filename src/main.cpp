
#include <algorithm> // std::sort
#include <iostream>
#include <queue>
#include <unordered_map> // unordered_map (hash map)
#include <vector>        // vector

// TwoSum
using namespace std;
class Solution {

public:
  /*
  string encode(vector<string>& strs) {
          // Create the result string
          string res;

          // iterate through the string vector
          for (const string& s : strs) {
              // store to string in format- size#word
              res += to_string(s.size()) + "#" + s;
          }
          cout << res<< endl;
          return res;
      }

      vector<string> decode(string s) {

          // Create a new string vector
          vector<string> res;

          // initialize i to 0
          int i = 0;

          // iterate through string
          while (i < s.size()) {

              // set j equal to i
              int j = i;

              // Increment j until #
              while (s[j] != '#') {
                  j++;
              }

              // Read the length from the substring, convert to int
              int length = stoi(s.substr(i, j - i));


              i = j + 1;
              j = i + length;
              res.push_back(s.substr(i, length));
              i = j;
          }
          return res;
      }
      */

  string encode(vector<string> &strs) {

    // Check if empty string
    if (strs.empty())
      return "";

    // initialize vector to store sizes of each string
    vector<int> sizes;

    // initialize result string
    string res = "";

    // Iterate through the string vector
    for (string &s : strs) {
      // push the size of each string to the vector
      sizes.push_back(s.size());
    }

    // iterate through the vector
    for (int sz : sizes) {

      // convert the sizes to a string, add comma, save to res
      res += to_string(sz) + ',';
    }

    // Add # to the end of res string
    res += '#';

    // Add strings to the end of res string
    for (string &s : strs) {
      res += s;
    }
    // cout << res << endl;
    return res;
  }

  vector<string> decode(string s) {

    // check if input string is empty
    if (s.empty())
      return {};

    // create a new int vector named sizes
    vector<int> sizes;

    // create a new string vector for the result
    vector<string> res;

    // initialize i to 0
    int i = 0;

    // iterate to # to get the sizes
    while (s[i] != '#') {

      // create a string named cur
      string cur = "";

      // iterate through the string. delimit by comma
      while (s[i] != ',') {
        // store numeric value(size) to cur
        cur += s[i];
        // increment char in string
        i++;
      }

      // convert cur string to int, then push to sizes vector
      sizes.push_back(stoi(cur));

      // increment i
      i++;
    }

    // incerement i to go one char past #
    i++;

    // iterate through the sizes vector
    for (int sz : sizes) {
      // for each size value in the vector: get the substring value(i to i+sz)
      // and add to res vector
      res.push_back(s.substr(i, sz));

      // increment i by the size
      i += sz;
    }

    // return result
    return res;
  }
};

int main() {

  Solution sol;

  vector<string> str_vect{"neet", "code", "love", "you"};
  for (auto x : str_vect) {
    cout << x << endl;
  }
  vector<string> result{};
  result = sol.decode(sol.encode(str_vect));

  for (auto x : result) {
    cout << x << endl;
  }
  return 0;
}
