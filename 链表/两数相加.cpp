/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* first=new ListNode(0);
     ListNode* l3=first;
     int carry=0;
     while(l1!=NULL || l2!=NULL || carry!=0){
         int add=carry;
         int remainder=0;
         if(l1!=NULL) add+=l1->val;
         if(l2!=NULL) add+=l2->val;
         remainder=add%10;
         carry=add/10;
         ListNode* tmp=new ListNode(remainder);
         l3->next=tmp;
         l3=tmp;
         l1=l1?l1->next:NULL;//能否取next得关键在于当前是不是null
         l2=l2?l2->next:NULL;//
     }

     return first->next;
}

/*
重载加法运算没有难度。关键是对指针的操作，要时刻注意是否操作了空指针。
构造函数的返回值是一个地址，因此要用指针存储。
*/
