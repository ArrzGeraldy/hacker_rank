#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

// Write your Student class here
class Student{
    private:
        std::vector<int> scores;

    public:
        Student() : scores(5) {};

        void input(){
            for(int i = 0; i < this->scores.size(); ++i){
                std::cin >> this->scores[i];
            }
        }

        int calculateTotalScore(){
            int sum = 0;
            for(int score : this->scores){
                sum += score;
            }

            return sum;
        }
};


int main() {
    int n; // number of students
    std::cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    std::cout << count;
    
    return 0;
}
