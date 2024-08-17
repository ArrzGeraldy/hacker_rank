#include <iostream>
#include <sstream>

class Student{
    private:
        int age;
        std::string first_name;
        std::string last_name;
        int standard;

    public:
        void set_age(int age){
            this->age = age;
        }

        void set_standard(int x){
            this->standard = x;
        }

        void set_first_name(std::string fname){
            this->first_name = fname;
        }
        void set_last_name(std::string lname){
            this->last_name = lname;
        }

        int get_age(){
            return this->age;
        }

        int get_standard(){
            return this->standard;
        }

        std::string get_last_name(){
            return this->last_name;
        }

        std::string get_first_name(){
            return this->first_name;
        }

        std::string to_string(){
            std::string str = std::to_string(age) + ',' + first_name + ',' + last_name + ',' +  std::to_string(standard);

            return str;
        }

};


int main() {
    int age, standard;
    std::string first_name, last_name;
    
    std::cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    std::cout << st.get_age() << "\n";
    std::cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    std::cout << st.get_standard() << "\n";
    std::cout << "\n";
    std::cout << st.to_string();
    
    return 0;
}