#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    //Declaring a global variable to store the head of the linked list
    ListNode* temp;

    bool isPalindrome(ListNode* head) {
        temp = head;

        //Calling the recursive function
        return check(head);
    }
    
    bool check(ListNode* p) {
        //Base case
        if (p == NULL) return true;

        //Recursively calling the function to reach the end of the linked list
        //When the function returns, it will check the value of the node with the global variable
        bool ans = check(p->next) & (temp->val == p->val); 

        //Incrementing the global variable to the next node
        temp = temp->next;
        return ans;
    }
};