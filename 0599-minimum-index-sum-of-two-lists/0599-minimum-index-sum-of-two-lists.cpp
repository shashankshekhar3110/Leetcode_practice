class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        vector<string> ans;
        int minSum = INT_MAX;

        for(int i = 0; i < list1.size(); i++) {
            
            for(int j = 0; j < list2.size(); j++) {
                
                if(list1[i] == list2[j]) {
                    
                    int sum = i + j;

                    if(sum < minSum) {
                        ans.clear();
                        ans.push_back(list1[i]);
                        minSum = sum;
                    }
                    else if(sum == minSum) {
                        ans.push_back(list1[i]);
                    }
                }
            }
        }

        return ans;
    }
};