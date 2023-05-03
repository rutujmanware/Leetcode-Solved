// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin(),nums1.end());
//         sort(nums2.begin(),nums2.end());
//         vector<vector<int>> ans(2);
//         for(int i=0,j=0;i<nums1.size() && j<nums2.size();){
//             if(i<nums1.size() && j<nums2.size()){
//                 if(nums1[i] == nums2[j]){
//                     int x = nums1[i];
//                     int y = nums2[j];
                    
//                     while(i<nums1.size()&&nums1[i] == x  ){
//                         i++;
//                     }
//                     while( j<nums2.size() && nums2[j] == y ){
//                         j++;
//                     }
                    
//                 }
//                 else if(nums1[i]<nums2[j]){
                    
//                     ans[0].push_back(nums1[i]);
//                      int x=nums1.size();
//                  while(i<nums1.size() && nums1[i] ==x)
//                     i++;
//                 }
//                 else {
//                     ans[1].push_back(nums2[j]);
//                      int y = nums2.size();
//                 while(j<nums2.size() && nums2[j] ==y)
//                     j++;
//                 }
//             }
//             while(i<nums1.size() && j==nums2.size()){
//                 ans[0].push_back(nums1[i]);
//                 int x=nums1.size();
//                  while(i<nums1.size() && nums1[i] ==x)
//                     i++;
//             }
//             while(j<nums2.size() && i==nums1.size()){
//                 ans[1].push_back(nums2[j]);
//                 int y = nums2.size();
//                 while(j<nums2.size() && nums2[j] ==y)
//                     j++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> distinct_nums1, distinct_nums2;
        for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct_nums1.push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct_nums2.push_back(num);
            }
        }

        return {distinct_nums1, distinct_nums2};
    }
};