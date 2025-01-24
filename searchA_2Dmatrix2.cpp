class Solution {
public:
    bool binarySearch(vector<int>& searchSpace, int left, int right, int target) {
        int low = left;
        int high = right;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (searchSpace[mid] == target) {
                return true;
            }
            if (searchSpace[mid] < target) {
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
        int i = 0;

        while (i < n) {
            if (binarySearch(matrix[i], 0, m - 1, target)) {
                return true;
            }
            i++;
        }

        return false;
    }
};


int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    
    Solution solution;

    int target = 5;
    if (solution.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    target = 20;
    if (solution.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}
