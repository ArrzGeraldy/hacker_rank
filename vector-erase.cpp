#include <vector>
#include <iostream>


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n; std::cin >> n;
    std::vector<int> v(n);

    for(int& num : v){
        std::cin >> num;
    }


    int query;
    std::cin >> query;

    v.erase(v.begin() + query-1);

   
    int rBegin,rEnd;

    std::cin >> rBegin >> rEnd;
    v.erase(v.begin() + (rBegin - 1), v.begin() + (rEnd - 1));
    // query = rBegin - 1;

    // while(rBegin < rEnd){
    //     v.erase(v.begin() + query);
    //     rBegin++;
    // }

    std::cout << v.size() << std::endl;

    for(int& num : v){
        std::cout << num << " ";
    }

    
    return 0;
}
