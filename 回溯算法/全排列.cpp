/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。
*/

void helper(vector<vector<int>>& res, vector<int>& nums, int cur, int len){
    if(cur==len){
        res.push_back(nums);
        return;
    }
    for(int i=cur;i<len;i++){
        swap(nums[i], nums[cur]);
        helper(res, nums, cur+1, len);
        swap(nums[i], nums[cur]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    int size=nums.size();
    helper(res, nums, 0, size);
    return res;
}

/*
回溯算法的结构比较固定，但不同题目中设置的判断条件和操作的数据结构有所不同。
此题是从目标出发，考虑如何填满一个vector，由此对原数组进行遍历。
为了判断哪些元素是字数组中填过的，此解中用了swap，即把使用过的元素放在下标左边，未使用的自动在下标右边，下标不断向前推进表示填充数组的过程。
也可以用额外的标记数组表示哪些元素使用过，不过会带来额外的空间开销。
*/
