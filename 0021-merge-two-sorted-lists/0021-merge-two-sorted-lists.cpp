class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        if (list1->val <= list2->val) {
            head = tail = list1;
            list1 = list1->next;
        }
        else {
            head = tail = list2;
            list2 = list2->next;
        }
        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }

        if (list1 == nullptr)
            tail->next = list2;
        else
            tail->next = list1;

        return head;
    }
};