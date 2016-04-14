#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v=-1,ListNode *ne=NULL):val(v),next(ne){}
};

/**
 * 返回头结点
 */
ListNode *removeWithFromEnd(ListNode *phead,int k)
{
    //head have data

    if(phead==NULL||k<=0) return NULL;
    ListNode head2(-1,phead);//add head

    ListNode *p=&head2;
    ListNode *q=p,*prev=q;
    int cnt = 0;
    while(p!=NULL&&cnt<k){
        cnt++;
        p = p->next;
    }
    if(p==NULL) return p;
    while(p!=NULL){
        prev = q;
        q = q->next;
        p = p->next;
    }
    //prev->next = q->next;
    //只有一个节点时，删除头结点
/*
    if(q==phead){
        cout<<"只有一个节点,删除头结点:"<<q->next<<endl;
        phead = q->next;
    }else{
        prev->next = q->next;
    }
    return q;
*/
    prev->next = q->next;
    delete q;
    return head2.next;
}

void PrintList(ListNode *phead)
{
    ListNode *p=phead;
    while(p!=NULL){
        cout<<p->val<<'\t';
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    ListNode *phead = new ListNode(1);
    phead->next = new ListNode(2);
    PrintList(phead);

    phead = removeWithFromEnd(phead,2);
    PrintList(phead);

    return 0;
}
