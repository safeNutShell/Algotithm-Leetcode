//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> a;
    vector<int> b(2,-1);
    for(int i=0;i<nums.size();i++)
        a.insert(map<int,int>::value_type(nums[i],i));
        for(int i=0;i<nums.size();i++){
            if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i))
            {
                b[0]=i;
                b[1]=a[target-nums[i]];
                break;
            }
        }
    return b;
};
