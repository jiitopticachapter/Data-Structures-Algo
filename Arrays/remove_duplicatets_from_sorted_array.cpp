class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        //Declaring a set to store the unique elements
        set<int> s;

        //Inserting the elements of the array into the set
        //This will automatically remove the duplicates
        for (int i = 0; i < a.size(); i++) {
            s.insert(a[i]);
        }

        //Clearing the array
        a.clear();

        //Inserting the elements of the set into the array
        for (auto& it: s) {
            a.push_back(it);
        }

        //Returning the size of the array
        return s.size();
    }
};