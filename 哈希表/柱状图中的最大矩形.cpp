给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

//解1：
//暴力
int largestRectangleArea(vector<int>& heights) {
    int res=0;
    for(int i=0; i<heights.size();i++){
        int minHeight=INT_MAX;
        for(int j=i;j<heights.size();j++){
            minHeight=min(minHeight, heights[j]);
            res=max(res, minHeight*(j-i+1));
        }
    }
    return res;
}

/*思路简单，但很容易超时，也不够精巧*/

//解2：
//分治，对一个数组来说，首先选定一个对应值最小的下标。那么勾勒得矩形要么在这个下标左边，要么穿过这个下标，要么在这个下标右边。
//递归的搜索数组，即可得到结果
int helper(vector<int>& heights, int begin, int end){
    if(begin==end) return heights[begin];
    if(begin>end) return 0;
    int currMinPtr=begin;
    for(int i=begin+1; i<=end;i++){
        if(heights[i]<heights[currMinPtr])
            currMinPtr=i;
    }
    int crossMin=heights[currMinPtr]*(end-begin+1);
    int leftMin=helper(heights, begin, currMinPtr-1);
    int rightMin=helper(heights, currMinPtr+1, end);
    return max(crossMin, max(leftMin, rightMin));
}
int largestRectangleArea(vector<int>& heights) {
    return helper(heights, 0, heights.size()-1);
}
/*问题在于分治需要用到递归，层层嵌套的栈也非常容易TLE*/

//解3：
//单调栈：假设从数组heights的每一个位开始寻找，该矩形的右边界对应的hrights[j]一定小于当前heights[i]，
//在遇到这样的“障碍”之前，应该持续向右递增下标，这样就形成了一个单调递增的栈（栈内单增，遇到新元素判断其于栈顶元素的大小关系以调整栈结构）。
//单调栈特别适合边界存在大小限制的问题
