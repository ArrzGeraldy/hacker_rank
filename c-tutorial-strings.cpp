#include <iostream>
#include <string>

using namespace std;

int main() {
	std::string a;
    std:: string b;
    
    std::cin >> a;
    std::cin >> b;
    
    std::cout << a.size() << " " << b.size() << std::endl;
    
    std::string concatStr = a+b;
    std::cout << concatStr << std::endl;
    
    // char temp = a[0];
    // a[0] = b[0];
    // b[0] = temp;
    std::swap(a[0],b[0]);
    
    std::cout << a << " " << b << std::endl;;
    
  
    return 0;
}