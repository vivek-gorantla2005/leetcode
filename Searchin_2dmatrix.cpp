#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool binarySearch(vector<int>& row, int target, int left, int right) {
        int low = left;
        int high = right;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == target) {
                return true;
            }
            if (row[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;

        while (row < n) {
            // If the target is greater than the last element of the row, move to the next row
            if (target > matrix[row][m - 1]) {
                row++;
            }
            // If the target is less than or equal to the last element of the row, perform binary search
            else {
                return binarySearch(matrix[row], target, 0, m - 1);
            }
        }
        return false;
    }
};

int main() {
    // Create a test matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    Solution solution;

    // Test case 1: Target exists in the matrix
    int target1 = 5;
    if (solution.searchMatrix(matrix, target1)) {
        cout << "Target " << target1 << " found in the matrix." << endl;
    } else {
        cout << "Target " << target1 << " not found in the matrix." << endl;
    }

    // Test case 2: Target doesn't exist in the matrix
    int target2 = 20;
    if (solution.searchMatrix(matrix, target2)) {
        cout << "Target " << target2 << " found in the matrix." << endl;
    } else {
        cout << "Target " << target2 << " not found in the matrix." << endl;
    }

    return 0;
}
