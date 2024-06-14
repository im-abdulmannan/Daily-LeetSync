class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            result[i] = nums[i] * nums[i];
        }

        selectionSort(result);

        return result;
    }

private:
    void selectionSort(vector<int>& arr) {
        int n = arr.size();

        // Traverse through all array elements
        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in the remaining unsorted array
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            }

            // Swap the found minimum element with the first element
            cout << arr[min_idx] << " " << arr[i] << endl;
            swap(arr[min_idx], arr[i]);
        }
    }
};