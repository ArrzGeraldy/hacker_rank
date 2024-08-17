#include<iostream>
#include<vector>

void printArr(std::vector<int> v){
    std::cout << "arr: ";
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


int main(){
    //meningkatkan kecepatan I/O
    std::ios::sync_with_stdio(false);  // Menonaktifkan sinkronisasi dengan C I/O ex:scanf() dll

    // menghindari operasi pembersihan otomatis pada std::cout setiap kali std::cin digunakan.
    std::cin.tie(NULL);  // Menonaktifkan tie untuk cin dan cout

    int size_a, q;
    std::cin >> size_a >> q;

    std::vector<std::vector<int>> a(size_a);

    for(int i = 0; i < size_a; ++i){
        int size_i;

        std::cin >> size_i;

        std::vector<int> arr(size_i,0);
        for(int j = 0; j < size_i; ++j){
            std::cin >> arr[j];
        }

        // printArr(arr);
        a[i] = arr;
    }

    for(int k = 0; k < q; ++k){
        int i, int j;
        std::cin >> i >> j;
        std::cout << a[i][j] << std::endl; 

    }

    return 0;
}