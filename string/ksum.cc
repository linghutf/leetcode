#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

typedef std::vector<int> Array;
typedef std::vector<Array> ArrayArray;

void KSum(ArrayArray &arr,Array &nums,int K,int target,int p)
{
    if(K==2){//base case
        Array tuple(2,0);
        int i=p,j=nums.size()-1;
        int sum;
        while(i<j){
            if(i>p && nums[i]==nums[i-1]){
                ++i;
                continue;
            }
            sum = nums[i]+nums[j];
            if(sum==target){
                tuple[0] = nums[i++];
                tuple[1] = nums[j--];
                arr.push_back(tuple);
            }else if(sum>target){
                --j;
            }else{
                ++i;
            }
        }
    }else if(K>2){
        for(int i=p;i<nums.size();++i){
            if(i>p && nums[i]==nums[i-1]) continue;
            ArrayArray K1Sum;
            KSum(K1Sum,nums,K-1,target-nums[i],i+1);
            for(auto it=K1Sum.begin();it!=K1Sum.end();++it){
                Array tuple;
                tuple.push_back(nums[i]);
                tuple.insert(tuple.end(),it->begin(),it->end());
                arr.push_back(tuple);
            }
        }
    }
}

void Print(ArrayArray &arr)
{
    /*for(auto it=arr.begin();it!=arr.end();++it){
        for(auto )
    }*/
    for(auto& v:arr){
        for(auto& num:v){
            cout<<setw(4)<<num;
        }
        cout<<endl;
    }
}

void testcase()
{
    int k,target;
    Array nums ={-3,2,1,-1,4,3,5};
    ArrayArray arr;
    cin>>k>>target;

    KSum(arr,nums,k,target,0);
    Print(arr);
}

int main(int argc, char *argv[])
{
    testcase();

    return 0;
}
