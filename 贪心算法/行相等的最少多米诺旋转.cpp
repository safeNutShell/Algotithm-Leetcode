/*
在一排多米诺骨牌中，A[i] 和 B[i] 分别代表第 i 个多米诺骨牌的上半部分和下半部分。（一个多米诺是两个从 1 到 6 的数字同列平铺形成的 —— 该平铺的每一半上都有一个数字。）
我们可以旋转第 i 张多米诺，使得 A[i] 和 B[i] 的值交换。
返回能使 A 中所有值或者 B 中所有值都相同的最小旋转次数。
如果无法做到，返回 -1.
*/

int check(int target, vector<int>&A, vector<int>&B, int n){
    int counta=0,countb=0;
    for(int i=0;i<n;i++){
        if(A[i]!=target&&B[i]!=target)
            return -1;
        else if(A[i]!=target)
            counta++;
        else if(B[i]!=target)
            countb++;
    }
    return min(counta,countb);
}
int minDominoRotations(vector<int>& A, vector<int>& B) {
    int n=A.size();
    int res=check(A[0],A,B,n);
    if(res!=-1||A[0]==B[0]) return res;
    else return check(B[0],A,B,n);
}
