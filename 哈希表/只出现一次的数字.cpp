/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
*/

//解1：
//扣题，用哈希表
int singleNumber(vector<int>& nums) {
    set<int> s;
    int res;
    for (int i = 0; i < nums.size();i++) {
        if (!s.count(nums[i])) {//当前元素在表里没有
            s.insert(nums[i]);
        }
        else {
            s.erase(nums[i]);
        }
    }
    set<int>::iterator it = s.begin();
    res = *it;
    return res;
}
/*声明了额外的空间，一次遍历vector一次遍历set，效率一般*/

//解2：
//本题的特点是元素为int，可以把vector排序后遍历，有时候把无序变得有序会使问题简单很多。如果STL自带了排序函数，一般来说效率不错
int singleNumber(vector<int>& nums) {
    int res;
    int i = 0;
    sort(nums.begin(), nums.end());
    while (i != nums.size()) {
        if (i == nums.size() - 1) {
            res = nums[i];
            break;
        }
        if (nums[i] != nums[i + 1]) {
            res = nums[i];
            break;
        }
        else {
            i += 2;
        }
    }
    return res;
}
/*
排序后如果当前值和下一位值一样则跳过，否则直接得到只出现一次的值。
但是从运行消耗来看，效率并不高，或许sort(s.begin(),s.end())写得不好吧（😀
*/

//解3：
//异或
int singleNumber(vector<int>& nums) {
    int res=nums[0];
    for(int i=1;i<nums.size();i++){
        res=res^nums[i];
    }
    return res;
}
/*
利用底层计算机的位运算，因为重复的仅重复两次，因此异或之后相互抵消，最后只剩下出现一次的值
牛逼
*/
