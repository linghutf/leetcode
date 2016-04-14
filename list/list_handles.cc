#include <iostream>
#include <iomanip>

#include "cpptest.hh"

using namespace std;

struct Node{
    Node *next;
    int v;

    Node(int v_=-1):v(v_),next(NULL){}
    Node(int v_,Node *next_):v(v_),next(next_){}
};

/*
 *
 * 反转单链表
 *
 *
 */
Node* ReverseList(Node *phead){
    if(phead==NULL||phead->next==NULL) return phead;
    Node *p,*q,*t;
    p = phead->next;
    q = p->next;
    p->next = NULL;//tail
    //include only have two node--care out!

    while(q!=NULL){
        t = q->next;//temp next
        q->next = p;//reverse
        //next node
        p = q;
        q = t;
    }//while(q!=NULL);
    phead->next = p;//last node
    return phead;
}
/**
 *
 * 删除当前节点
 *
 * 返回链表头
 */
Node* DeleteCurNode(Node* phead,Node *pcur)
{

    if(phead==NULL||pcur==NULL) return phead;
    Node *q=phead->next;
    Node *t=phead;//prev
    while(q!=NULL&&q!=pcur){
        t = q;
        q = q->next;
    }
    t->next = q->next;//next
    delete q;
    return phead;
}
/**
 * 删除当前节点(除了尾结点)，并没有前缀节点
 *
 * 思路:交换当前节点和下一节点的值，删除下一节点
 *
 */
void DeleteCurNode(Node* node)
{
    if(node==NULL||node->next==NULL)
        return node;
    Node *t = node->next;
    node->v = node->next->v;
    node->next = node->next->next;
    delete t;
}
/**
 * 查询倒数第K个节点
 */
Node* FindLastKNode(Node *phead,int k)
{
    if(phead==NULL||phead->next==NULL||k<=0) return NULL;
    int cnt = 0;
    Node *p = phead;
    Node *q;
    while(p!=NULL&&cnt<k){
        p = p->next;
        ++cnt;
    }
    if(p==NULL) return NULL;//not enough
    q = phead;
    while(p!=NULL){
        q = q->next;
        p = p->next;
    }
    return q;
}
/**
 *
 * 创建单链表
 */
Node* createList(Node *phead){
    int i=0;
    Node *p,*q;
    p = new Node(i);
    phead->next = p;
    q = p;
    for(++i;i<2;++i){
        p = new Node(i);
        q->next = p;
        q = p;
    }
    return phead;
}

void PrintList(Node *phead){
    Node *p = phead->next;
    while(p!=NULL){
        cout<<setw(4)<<p->v;
        p = p->next;
    }
    cout<<endl;
}

void DestroyList(Node *phead){
    if(phead==NULL) return;
    Node *p = phead->next,*q;
    while(p!=NULL){
        q = p->next;
        delete p;
        p = q;
    }
}

void test_reverse(Node* phead)
{
    ReverseList(phead);
    cout<<"After reverse:"<<endl;
    PrintList(phead);
}

void test_delete_cur(Node *phead)
{
    DeleteCurNode(phead,phead->next);
    cout<<"After delete cur:"<<endl;
    PrintList(phead);

    DeleteCurNode(phead,phead->next->next);
    cout<<"After delete cur:"<<endl;
    PrintList(phead);

    Node *p = phead->next;
    while(p->next!=NULL){
        p = p->next;
    }

    DeleteCurNode(phead,p);
    cout<<"After delete cur:"<<endl;
    PrintList(phead);

}

int main()
{
    Node head;
    Node *phead = &head;
    createList(phead);
    PrintList(phead);

    test_reverse(phead);

    test_reverse(phead);

    test_delete_cur(phead);

    DestroyList(phead);

    return 0;
}
