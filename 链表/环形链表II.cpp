/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                break;
        }
        if(fast==NULL || fast->next==NULL){
            return NULL;
        }
        ListNode *start=head;
        while(start!=slow){
            slow=slow->next;
            start=start->next;
        }
        return slow;
    }
};

/*
典型的寻找链表的循环开始点
与数组“寻找重复数字”是同一问题
*/
