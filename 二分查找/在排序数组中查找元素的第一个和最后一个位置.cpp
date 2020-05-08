/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
*/

vector<int> helper(vector<int>& nums, int left, int right, int target) {
    if (left == right) {
        if (nums[left] != target) {
            vector<int> res;
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
    }
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
        int l = mid, r = mid;
        while (l!=0 && nums[l-1] == target) l--;
        while (r!=nums.size()-1 && nums[r+1] == target) r++;
        vector<int> res;
        res.push_back(l);
        res.push_back(r);
        return res;
    }
    else if (nums[mid] > target) {
        return helper(nums, left, mid, target);
    }
    else {
        return helper(nums, mid + 1, right, target);
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size()==0){
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    return helper(nums, 0, nums.size() - 1, target);
}

/*
简单方法可以用一次遍历，但是那样算法复杂度为N。使用二分查找之后复杂度可下降为logN。
注意在使用迭代时，在函数刚进入的地方做好结束情况的检查，之后再用其他代码进行迭代。
使用数组就要小心越界问题！
*/
