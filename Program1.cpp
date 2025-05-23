//
// Created by Aung Naing Thu on 5/15/2025.
//

#include <iostream>
#include <string.h>

class Student
{
    private:
        int salary = 0;

    public:
        int roll;
        char name[20];

    Student(int roll, char name[], int salary)
    {
        this->roll = roll;
        strcpy(this->name, name);
        this->salary = salary;
    }

    // Getter Function
    int getSalary()
    {
        return salary;
    }

    // Setter Function
    void setSalary(int salary)
    {
        this->salary = salary;
    }

};

int main()
{
    Student s1(1, "Aung", 10000);

    std::cout << s1.roll << " " << s1.name << std::endl;
    std::cout << s1.getSalary() << std::endl;


    return 0;
}
