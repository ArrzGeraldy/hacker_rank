#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    std::cin >> n;

    std::vector<int> nums(n);


    // for(int i = 0; i < nums.size(); ++i){
    //     std::cin >> nums[i];
    // }

    for(int& num : nums){
        std::cin >> num;
    }

    std::sort(nums.begin(),nums.end());

    for(int i = 0; i < nums.size(); ++i){
        std::cout << nums[i] << " ";
    }



    return 0;
}
