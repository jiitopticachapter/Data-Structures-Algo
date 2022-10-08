// https://leetcode.com/problems/linked-list-cycle-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Using Hashmaps - O(n) space complexity (Naive approach)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *temp=head;
        unordered_map<ListNode *,int> umap;
        while(temp!=NULL){
            if(umap.find(temp)!=umap.end()) return temp;
            umap[temp]=head->val;
            temp=temp->next;
        }
        return NULL;
    }
};


// Floyd Cycle Detection Algorithm - O(1) space complexity
// Also know as hare and tortoise algorithm
// refer here - https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // O(1) space
        if(!head || !head->next)
            return NULL;
        
        // Floyd Cycle Detection Algorithm
        ListNode *slow = head, *fast = head;
        ListNode *meeting = NULL;
        bool cyclePresent = false;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                meeting = slow;
                cyclePresent = true;
                break;
            }
        }
        if(!cyclePresent)
            return NULL;
        while(1) {
            if(head == meeting)
                return head;
            head = head -> next;
            meeting = meeting -> next;
        }
    }
};