/*
给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
*/

int thirdMax(vector<int>& nums) {
    if(nums.size()==0) return 0;
    long int FirstMax=nums[0], SecondMax=LONG_MIN, ThirdMax=LONG_MIN;
    for(int i=1; i<nums.size(); i++){
        if(nums[i]>FirstMax){
            ThirdMax=SecondMax;
            SecondMax=FirstMax;
            FirstMax=nums[i];
        }
        else if(nums[i]<FirstMax && nums[i]>SecondMax){
            ThirdMax=SecondMax;
            SecondMax=nums[i];
        }
        else if(nums[i]<SecondMax && nums[i]>ThirdMax){
            ThirdMax=nums[i];
        }
    }
    if(ThirdMax != LONG_MIN){
        return ThirdMax;
    }
    else if (FirstMax != LONG_MIN){
        return FirstMax;
    }
    return 0;
}

/*
简单的一次遍历和区间比较；注意特殊测试用例可能专坑INT_MIN之类的值，解决办法可以是使用更大范围的值或者用辅助变量进行判断。
*/
