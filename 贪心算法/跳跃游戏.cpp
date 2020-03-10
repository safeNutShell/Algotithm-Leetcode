给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。

//解：
bool canJump(vector<int>& nums) {
    if (nums.size() == 1) return true;
    int curr = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            if (i == nums.size() - 1) {
                curr = i;
                int tmp = curr - 1;
                while (1) {
                    if (tmp < 0) {
                        return false;
                    }
                    if (nums[tmp] < curr - tmp) {
                        tmp--;
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                curr = i;
                int tmp = curr - 1;
                while (1) {
                    if (tmp < 0) {
                        return false;
                    }
                    if (nums[tmp] <= curr - tmp) {
                        tmp--;
                    }
                    else {
                        break;
                    }
                }
            }

        }
    }
    return true;
}

/*
目前算法的问题在于对最后一位的特殊性没有照顾好，使用了额外的if判断
应当是可以用更简单的方法实现的
解题思路是：导致跳跃失败的是nums[i]==0，那么遍历过程中一旦遇到零就要向前回溯，看是否有某一位的跳跃可以跃过这个0，否则跳跃在i位断开
*/
