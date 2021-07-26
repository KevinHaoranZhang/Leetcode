#include <algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int my_size = size1+ size2;
        std::vector<double> my_vec;
        for(int i = 0; i < size1; i++){
            
            my_vec.push_back(nums1[i]);
        }
        for(int j = 0; j < size2; j++){
                my_vec.push_back(nums2[j]);
            }
        std::sort(my_vec.begin(), my_vec.end());
        if(my_size%2 == 0)
            return (my_vec[my_size/2]+my_vec[my_size/2-1])/2;
        else
            return my_vec[my_size/2];
    }
};


