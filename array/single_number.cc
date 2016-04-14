#include <iostream>

using namespace std;

/**
 * a array
 * n array length
 * k other number appear times
 * return only appear once
 */
int singleNumber(int a[],int n,int k){
    int bitnum[32]={0};
    int res=0;
    for(int i=0;i<32;++i){
        for(int j=0;j<n;++j){
            bitnum[i]+=(a[j]>>i)&0x1;//记录每一位1的数量
        }
        cout<<i<<":"<<bitnum[i]<<endl;
        res |= ((bitnum[i]%k)<<i);//求余有剩余的,即是唯一的那个数
    }
    return res;
}

int main()
{
    int a[]={3,2,3,2,4,3,2};
    int len = sizeof(a)/sizeof(a[0]);
    cout<<singleNumber(a,len,3)<<endl;
    return 0;
}
