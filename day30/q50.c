/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Reverse both lists to start addition from least significant digit
    struct ListNode* r1 = reverseList(l1);
    struct ListNode* r2 = reverseList(l2);
    
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    
    struct ListNode* current = dummyHead;
    int carry = 0;
    
    while (r1 != NULL || r2 != NULL || carry != 0) {
        int x = (r1 != NULL) ? r1->val : 0;
        int y = (r2 != NULL) ? r2->val : 0;
        int sum = carry + x + y;
        
        carry = sum / 10;
        
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = sum % 10;
        current->next->next = NULL;
        current = current->next;
        
        if (r1 != NULL) r1 = r1->next;
        if (r2 != NULL) r2 = r2->next;
    }
    
    struct ListNode* result = reverseList(dummyHead->next);
    free(dummyHead);
    return result;
}