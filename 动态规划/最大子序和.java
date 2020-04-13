/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/

public int crossSum(int[] nums, int left, int right, int p){
    if(left==right) return nums[left];

    int subLeftSum=Integer.MIN_VALUE;
    int leftTmp=0;
    for(int i=p;i>left-1;i--){
        leftTmp+=nums[i];
        subLeftSum=Math.max(subLeftSum,leftTmp);
    }

    int subRightSum=Integer.MIN_VALUE;
    int rightTmp=0;
    for(int i=p+1;i<right+1;i++){
        rightTmp+=nums[i];
        subRightSum=Math.max(subRightSum,rightTmp);
    }

    return subLeftSum+subRightSum;
}

public int helper(int[] nums, int left, int right){
    if(left==right) return nums[left];

    int p=(left+right)/2;

    int leftSum=helper(nums, left, p);
    int rightSum=helper(nums,p+1, right);
    int crossSum=crossSum(nums, left, right, p);

    return Math.max(Math.max(leftSum, rightSum),crossSum);
}
public int maxSubArray(int[] nums) {
    return helper(nums, 0, nums.length-1);
}

/*
不仅是动态规划，更体现了分治的思路
首先一个序列可从中分开，而子序列可能在左半、可能跨过中心也可能在右半，因此分为三种情况进行比较
*/
