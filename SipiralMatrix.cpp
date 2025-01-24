#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        vector<int> output;
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right across the top row
            for (int i = left; i <= right; i++) {
                output.push_back(matrix[top][i]);
            }
            top++;
            
            // Traverse from top to bottom down the right column
            for (int i = top; i <= bottom; i++) {
                output.push_back(matrix[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                // Traverse from right to left across the bottom row
                for (int i = right; i >= left; i--) {
                    output.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if (left <= right) {
                // Traverse from bottom to top up the left column
                for (int i = bottom; i >= top; i--) {
                    output.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return output;
    }
};

int main() {
    // Define a test matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution solution;

    // Get the spiral order of the matrix
    vector<int> result = solution.spiralOrder(matrix);

    // Print the result
    cout << "Spiral order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Another test case
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    result = solution.spiralOrder(matrix2);

    // Print the result for the second matrix
    cout << "Spiral order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
