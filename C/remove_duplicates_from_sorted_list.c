#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* ret = head;
    while (head) {
        while (head->next != NULL && head->val == head->next->val) {
            struct ListNode* tofree = head->next;
            head->next = head->next->next;
            free(tofree);
        }
        head = head->next;
    }
    return ret;
}

int main() {
    return 0;
}