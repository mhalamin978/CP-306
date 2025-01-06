#include<iostream>
using std::string ;
using namespace std;
    class Employee {
        // I can add more stuff..
public:
        string Name; 
        string Company;
        int Age;

        void IntroduceYourself(){
            std::cout<<"Name: "<<Name<<std::endl;
            std::cout<<"age: "<<Age<<std::endl;
            std::cout<<"Company: "<<Company<<std::endl;
        }
        Employee(string name, string company, int age) {
        Name = name;
        Company =company;
        Age=age;
    }
    };
    
int main(){
    //Lets create a obj for class Employee
    int number;
    Employee em1 = Employee("alo","Aloz company", 21);
     em1.IntroduceYourself(); 
    /*
    em1.Name="akk";
    em1.Company="alo";
    em1.Age =21;
    em1.IntroduceYourself(); 
    */
   Employee em2 = Employee("jon", "stark industry",29);
   em2.IntroduceYourself();
/*
    Employee em2;
    em2.Name ="jon";
    em2.Company ="amazon";
    em2.Age =34;
    em2.IntroduceYourself();
*/
    return 0;
}