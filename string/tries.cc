/**
 * 字典树
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;

enum Color{
    White,
    Red,
    Black
};

struct Node{
    char c;
    Color color;
    std::list<Node *> nexts;
};

typedef std::list<Node *> Dictionary;

void BuildTries(Dictionary &dic,string &s)
{
    Node *p = dic.front();
}
