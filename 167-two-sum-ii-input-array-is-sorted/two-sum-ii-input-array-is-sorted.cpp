class Solution {
public:
    int binary(vector<int>& nums, int s, int target) {
    int e = nums.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) s = mid + 1;
        else e = mid - 1;
    }
    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
        int diff = target - numbers[i];
        int j = binary(numbers, i + 1, diff);
        if (j != -1) return {i + 1, j + 1};
    }
    return {};
}
};