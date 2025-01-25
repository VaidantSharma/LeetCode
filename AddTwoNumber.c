/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3 = NULL;
    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    struct ListNode* temp3 = NULL;
    int carry = 0;
    while(temp1 !=NULL || temp2 !=NULL || carry!=0){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        if(temp1 != NULL){
            carry += temp1->val;
            temp1= temp1->next; 
        }
        if(temp2 != NULL){
            carry += temp2->val;
            temp2= temp2->next; 
        }
        newNode->val = carry%10;
        carry = carry/10;
        if(l3==NULL){
            l3 = newNode;
            temp3 = l3;
        }else{
            temp3->next = newNode;
            temp3 = temp3->next;
        }
    }
    return l3;
}