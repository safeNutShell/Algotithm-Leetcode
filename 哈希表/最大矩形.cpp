//给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

//解：
int largestRectangleArea(vector<int>& heights) {
    vector<int> stack;
    stack.push_back(-1);
    int res = 0;
    for (int i = 0; i < heights.size(); i++) {
        while (stack.back() != -1 && heights[stack.back()] >= heights[i]) {
            res = max(res, heights[stack.back()] * (i - stack[stack.size() - 2] - 1));
            stack.pop_back();
        }
        stack.push_back(i);
    }
    int rightLimit = heights.size();
    while (stack.back() != -1) {
        res = max(res, heights[stack.back()] * (rightLimit - stack[stack.size() - 2] - 1));
        stack.pop_back();
    }
    return res;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size()==0) return 0;
    int dp_size=matrix[0].size();
    int res=0;
    vector<int> dp(dp_size, 0);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<dp_size;j++){
            if(matrix[i][j]=='1'){
                dp[j]=dp[j]+1;
            }
            else{
                dp[j]=0;
            }
        }
        res=max(res, largestRectangleArea(dp));
    }
    return res;
}
/*
和“柱状图中最大矩形”梦幻联动；巧妙地把垒起来的1看做成长方型，纵向遍历matrix，遇到'0'就清空当前积累的长方形，遇到'1'就继续积累。
这样在每层都形成了一组长方形，且各自有高，接下来只要在当前组中框出一个最大长方形面积即可，这也正是“柱状图中最大矩形”解决的问题。
*/
