#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    std::vector<int> v;
	std::stringstream ss(str);
    char ch;
    int a;
    
    while(ss >> a){
        v.push_back(a);
        std::cout << "a: " << a;
        ss >> ch;
    }
    // jika tipe a adalah std::string dengan input "23,25,27"
    // maka 23 akan di masuk ke var a dengan "23"
    // lalu koma masuk ke ch sebagai pemisah
    // delimeter pemisah adalah = koma(',') spasi(' ') titik('.') titik-2(':')
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}