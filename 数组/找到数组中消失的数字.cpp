/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
找到所有在 [1, n] 范围之间没有出现在数组中的数字。
您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
*/

vector<int> findDisappearedNumbers(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
        if(nums[abs(nums[i])-1]>0)
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
    }
    vector<int> res;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0)
            res.push_back(i+1);
    }
    return res;
}

/*
主要是不能使用额外的存储空间，因此需要一边遍历一边对原数组进行修改
或许可以通过重复使用原数组达到不开辟额外存储空间的目的
*/
