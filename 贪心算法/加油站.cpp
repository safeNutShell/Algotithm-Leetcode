在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

//解1：
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int round=gas.size();
    for(int i=0;i<round;i++){
        int tank=0;
        int count=0;
        int j=i;
        while(true){
            if(tank+gas[j]>=cost[j]){
                tank=tank+gas[j]-cost[j];
                j=(j+1)%round;
                count++;
            }
            else{
                break;
            }
            if(count==round)
                return i;
        }
    }
    return -1;

}
/*简单的遍历思想，把每个下标都走一遍，时间复杂度为O(n^2)*/

//解2：
