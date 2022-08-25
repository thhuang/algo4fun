class Solution {
   public:
    vector<int> transformArray(vector<int>& arr) {
        while (true) {
            vector<int> new_arr = arr;
            bool modified = false;
            for (int i = 1; i < arr.size() - 1; ++i) {
                if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
                    --new_arr[i], modified = true;
                if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
                    ++new_arr[i], modified = true;
            }
            arr = move(new_arr);
            if (!modified) break;
        }
        return arr;
    }
};
