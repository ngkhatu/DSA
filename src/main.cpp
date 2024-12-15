
#include <algorithm> // std::sort
#include <iostream>
#include <queue>
#include <unordered_map> // unordered_map (hash map)
#include <vector>        // vector

// TwoSum
using namespace std;

// Valid Sodoku
class Solution {
public:
  // Hash Set (One Pass)
  // Time Complexity- O(n^2)
  // Space Complexity- O(n^2)
  bool isValidSudoku(vector<vector<char>> &board) {

    // hash map: key- row or col #, value- set of values(1-9, .)
    unordered_map<int, unordered_set<char>> rows, cols;

    // ordered hash map: key- pair of ints, value- set of values(1-9, .)
    map<pair<int, int>, unordered_set<char>> squares;

    // iterate through row 0 through 9
    for (int r = 0; r < 9; r++) {
      // iterate through col 0 through 9
      for (int c = 0; c < 9; c++) {

        // if blank continue
        if (board[r][c] == '.')
          continue;

        // squareKey derived from row and column
        pair<int, int> squareKey = {r / 3, c / 3};

        // Check if the value already exists in the set. If so, return false
        if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) ||
            squares[squareKey].count(board[r][c])) {
          return false;
        }

        // if values do not exist, insert them into the sets
        rows[r].insert(board[r][c]);
        cols[c].insert(board[r][c]);
        squares[squareKey].insert(board[r][c]);
      }
    }

    // return true if there are no repeating values anywhere and valid
    return true;
  }

  /*
  // Bitmask solution
    // Time Complexity- O(n^2)
    // Space Complexity- O(n)
    bool isValidSudoku(vector<vector<char>>& board) {
        // initialize arrays
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        // iterate by rows
        for (int r = 0; r < 9; ++r) {
            // iterate by columns
            for (int c = 0; c < 9; ++c) {

                // if value is . continue
                if (board[r][c] == '.') continue;

                // subtract '1' ascii value from char value
                int val = board[r][c] - '1';

                // bit shift 1 by the value, then and with current [r/c/squares]
  array if ((rows[r] & (1 << val)) || (cols[c] & (1 << val)) || (squares[(r / 3)
  * 3 + (c / 3)] & (1 << val))) { return false;
                }

                // if there is no match, continue to update the array values
                rows[r] |= (1 << val);
                cols[c] |= (1 << val);
                squares[(r / 3) * 3 + (c / 3)] |= (1 << val);
            }
        }
        return true;
    }
  */
};

int main() { return 0; }
