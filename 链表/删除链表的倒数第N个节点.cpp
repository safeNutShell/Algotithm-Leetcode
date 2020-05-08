/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* first=head;
    for(int i=0;i<n-1;i++){
        first=first->next;
    }
    ListNode* second=head;
    ListNode* third=head;
    while(first->next!=NULL){
        first=first->next;
        third=second;
        second=second->next;
    }
    if(second==head) return second->next;
    third->next=second->next;
    return head;
}

/*
巧妙地使用n个间隔进行控制。
凡是数组、链表相关的，都有可能用多个指针解决问题。
*/
