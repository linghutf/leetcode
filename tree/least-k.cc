/*
 * least-k.cc
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

/*
 * if it is project,may write by this way.
 * but,now I just want to write simple small file.:)
 * #include "least-k.h"
 */

/*
 * 红黑树实现最小的K个数
 * 删除，查询,插入都是O(logk)
 * 在k个数中获取最值O(1)
 */
#include <iostream>
#include <iomanip>
#include <set>
#include <functional>
// #include <string>
// #include <cstdio>
#include <algorithm>
#include <vector>
// #include <memory>
// #include <thread>

using namespace std;

typedef std::multiset<int,std::greater<int> > Set;
typedef std::multiset<int,std::greater<int> >::iterator SetIterator;

void GetLeastKnum(const std::vector<int>& data,Set& result,int k){
    for(auto it = data.cbegin();it!=data.cend();++it){
        if(result.size()<=k){
            result.insert(*it);
        }else{
            SetIterator iter = result.begin();
            if(*it<*(result.begin())){
                result.erase(iter);
                result.insert(*it);
            }
        }
    }
}

void PrintKnum(Set& set){
    for(auto it=set.begin();it!=set.end();++it){
        cout<<setw(4)<<*it;
    }
    cout<<endl;
}

int main(int argc,char const *argv[])
{
    std::vector<int> v ={1,2,3,6,99,81,-1,0};
    int k = 3;
    Set set;
    GetLeastKnum(v,set,k);
    PrintKnum(set);

    return 0;
}
