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
        }//先定位到环中的某一个元素
        
        int ptr=0;
        while(nums[slow]!=nums[ptr]){
            slow=nums[slow];
            ptr=nums[ptr];
        }//环内元素/链表首位元素同时开始遍历，定位入口点
        return nums[ptr];
    }

/*
最简单的利用set存储已经出现的数字，对接下来的数字进行匹配
更高效地，当数组中有两个以上重复的数字时，意味着顺着数组的下标-value遍历，会出现环
那么此题就变成了如何检索链表中的环以及找出环的入口
典型做法是利用快慢指针
合理性？为什么一定能相遇
*/
