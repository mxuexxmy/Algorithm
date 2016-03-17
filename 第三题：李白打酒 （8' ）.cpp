// 第三题：李白打酒 （8' ）


//     话说大诗人李白，一生好饮。幸好他从不开车。
//     一天，他提着酒壶，从家里出来，酒壶中有酒2斗。他边走边唱：

//     无事街上走，提壶去打酒。
//     逢店加一倍，遇花喝一斗。

//     这一路上，他一共遇到店5次，遇到花10次，已知最后一次遇到的是花，他正好把酒喝光了。 

//     请你计算李白遇到店和花的次序，可以把遇店记为a，遇花记为b。则：babaabbabbabbbb 就是合理的次序。像这样的答案一共有多少呢？请你计算出所有可能方案的个数（包含题目给出的）。

//     注意：通过浏览器提交答案。答案是个整数。不要书写任何多余的内容。

pre 为-1，表示是第一次；为0表示上一次是遇花，为1表示遇店


#include <iostream>
#include <cstdio>
using namespace std;

int ans;

void dfs(int alco,int store,int flower, int pre){
    if(store == 0 && flower == 0 ){
        if(pre == 0 && alco == 0)ans++;
        return ;
    }
    if(store > 0){
        dfs(alco*2,store-1,flower,1);
    }

    if(alco > 0 && flower > 0){
        dfs(alco-1,store,flower-1,0);
    }
    return ;
}

int main(){
    ans = 0;
    dfs(2,5,10,-1);
    printf("%d\n",ans);
    return 0;
}