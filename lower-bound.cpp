#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,nQuery;

    std::cin >> n;

    std::vector<int> nums(n);

    for(int& num : nums){
        std::cin >> num;
    }

    std::cin >> nQuery;

    while(nQuery--){
        int query;
        std::cin >> query;

        auto it = std::lower_bound(nums.begin(),nums.end(),query);

        if(it != nums.end() && *it == query){
            std::cout << "Yes " << (it - nums.begin() + 1) << std::endl;
        } else {
            std::cout << "No " << (it - nums.begin() + 1) << std::endl;
        }
    }
    
    return 0;
}
