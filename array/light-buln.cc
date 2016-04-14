#include <iostream>
#include <bitset>
#include <boost/dynamic_bitset.hpp>

using namespace std;

int bulbSwitch(int num){
    if(num<=0) return 0;
    boost::dynamic_bitset<> map(num);
    int i,j;
    for(j=1;j<=num;++j){
        for(i=j;i<=num;++i){
            if(i%j==0) map.flip(i-1);
        }
        //flag=!flag;
    }
    cout<<map.count()<<endl;
}

int main(int argc,char *argv[])
{
    //const int num = 3;
    //bitset<num> map;
    //vector<bool> map(false,num);
    int num;
    cin>>num;
    boost::dynamic_bitset<> map(num);

    int i,j;
    for(j=1;j<=num;++j){
        for(i=j;i<=num;++i){
            if(i%j==0) map.flip(i-1);
        }
        //flag=!flag;
        //cout<<map<<endl;
    }
    cout<<map.count()<<endl;
    return 0;
}
