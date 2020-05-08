/*
给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。
说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
*/

void rotate(vector<vector<int>>& matrix) {
    int size=matrix.size();
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            int tmp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=tmp;
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size/2;j++){
            int tmp=matrix[i][j];
            matrix[i][j]=matrix[i][size-1-j];
            matrix[i][size-1-j]=tmp;
        }
    }
}

/*
数组题有时是数学题，要么代数要么几何。
这题就是把顺时针一次旋转分解成对角旋转加翻转。
*/
