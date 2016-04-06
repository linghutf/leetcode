#include <iostream>
#include <algorithm>
#include <string>
//#include <cctype>

using namespace std;

class Solution{
    public:
        int lengthOfLastWord(const string &s){
            //const string str(s);
            auto first = std::find_if(s.rbegin(),s.rend(),::isalpha);//找到第一个字母
            auto last = std::find_if_not(first,s.rend(),::isalpha);//[begin,first]找到第一个不是字母
            return std::distance(first,last);
        }
};

int main(int argc, char *argv[])
{
    Solution *p;
    string s;
    getline(cin,s,'\n');
    cout<<p->lengthOfLastWord(s)<<endl;
    return 0;
}


