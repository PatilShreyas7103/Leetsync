class Solution {
public:
    int threeSumClosest(vector<int>& arr, int t) {
        int n = arr.size();
        int ans = 0;
        int mn = INT_MAX;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == t) {
                    return t;
                }
                else if (sum < t)
                {
                    if(abs(sum-t)<mn)
                    {
                        mn = abs(sum-t);
                        ans = sum;
                    }
                    left++;
                }

                    
                else
                {
                    if(abs(sum-t)<mn)
                    {
                        mn = abs(sum-t);
                        ans = sum;
                    }
                    right--;
                }
                    
            }
        }

        return ans;
    }
};
