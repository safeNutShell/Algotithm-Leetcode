/*
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。
*/

int findDuplicate(vector<int>& nums) {
    set<int> helper;
    for(int i=0;i<nums.size();i++){
        if(helper.count(nums[i]))
            return nums[i];
        else
            helper.insert(nums[i]);
    }
    return 0;
}

int findDuplicate(vector<int>& nums) {
    int slow=0;
    int fast=0;
    while(1){
        slow=nums[slow];
        fast=nums[nums[fast]];
        if(slow==fast)
            break;
    }

    int ptr1=slow;
    int ptr2=0;
    while(ptr1!=ptr2){
        ptr1=nums[ptr1];
        ptr2=nums[ptr2];
    }
    return nums[ptr1];
}
