/*
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode tmp=ListNode(-1);
    ListNode* result=&tmp;
    while(l1!=NULL && l2!=NULL){
        if(l1->val > l2->val){
            result->next=l2;
            l2=l2->next;
        }else{
            result->next=l1;
            l1=l1->next;
        }
        result=result->next;
    }
    result->next=l1==NULL?l2:l1;
    return tmp.next;
}

/*
简单地直接遍历，关键是对指针的操作
可以在开头利用一个“假节点”先建立起整个链表，用函数申请的结果是一个struct，后续操作时注意赋值到一个指针上去
*/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    if(l1->val > l2->val){
        l2->next=mergeTwoLists(l1, l2->next);
        return l2;
    }else{
        l1->next=mergeTwoLists(l1->next, l2);
        return l1;
    }
}
/*
利用递归，每次比较后直接修改l1或l2节点的next指，从而在原空间上形成新的链表
*/
