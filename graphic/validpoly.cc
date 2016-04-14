/*
 * validpoly.cc
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

/*
 * if it is project,may write by this way.
 * but,now I just want to write simple small file.:)
 * #include "validpoly.h"
 */

/*
 *
 * 判断是否是四边形 set8个点重合四个点
 * 然后判断边是否与另外三边垂直/平行，斜率tan
 */
#include <iostream>
#include <unordered_set>
#include <vector>

enum Status{
    Common,//一般情形
    Parallel,//平行
    Horizon,//水平
    Vertical//垂直
};

struct Point{
    int x,y;
    Point():x(0),y(0){}
    Point(int x_,int y_):x(x_),y(y_){}
    //斜率
    double slope(const Point& p,Status &s){
        int a = p.x-x;
        int b = p.y-y;
        if(a==0&&b!=0){
            s=Vertical;
            return 0;
        }
        return ::tan(b/a);
    }
};
namespace std{
    template<>::hash(cosnt)
}
bool isQuad(vector<Point> &vec)
{
    unordered_set<Point> s;
}
int main(int argc,char const *argv[])
{

}
