/*  # Brute Force Approach 

	Space Complexity = O(N)
	TIME Complexity = O(N)

	Approch - Here first we assign the value in an array (vector), 
		then we simply check the array that wheather array is 
		panlindrom. 
*/

class Solution {
public:
	bool isPalindrome(ListNode* head) {
			
		vector<int> v;
        ListNode *temp=head; 
        
        while(temp!=NULL) // Traverse the linked List 
        {
            // Insest List values to vector 
            v.push_back(temp->val); 
            
            // Incrementing the pointer 
            temp=temp->next; 
        }
        
        
        // Check the vector is Palindrom ? 
        int i=0, j=v.size()-1; 
        while(i<j)
        {	
            if(v[i++]!=v[j--])
                return false; 
        }
        
        return true;
	}
};


/*  # Optimal Approach 

	Space Complexity = O(1)
	TIME Complexity = O(N)

	Approch - Here first we Reverse the first half list, 
		then we simply compare the First Half to Another Half.
*/

class Solution {
public:
	
	// Reverse Linked-List Function 
    ListNode* reverse(ListNode* head){
        
        ListNode* curr = head, prev = NULL;
        
        while(curr!=NULL)
        {	
            ListNode* curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
            
        }
        
        return prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
		//using fast and slow pointers to find middle of the linked list
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Reversed the List From Middle
        ListNode* rev_head = reverse(slow);
        
        // after finding mid we are reversing the List from middle to the end
        ListNode* curr = head;
		
		/* 
		now we are checking whether the first half and the reversed 
		half is same or not if same return true else fasle */
		
        while(curr!=NULL && rev_head!=NULL)
        {
            if(curr->val!=rev_head->val){
                return false;
            }
            
            curr = curr->next;
            rev_head = rev_head->next;
        }
                
        return true;
    }
};
