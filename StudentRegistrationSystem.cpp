#include <iostream>
#include <vector>

using namespace std;

class Student
{
public:
    string name;
    int roll;
    int age;
    string username;
    string password;

    Student(string username, string password, string name, int roll, int age)
    {
        this->username = username;
        this->password = password;
        this->name = name;
        this->roll = roll;
        this->age = age;
    }

    void displayStudentInfo() const
    {
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
        cout << "Age: " << age << endl;
    }
};

// Function to handle login
void login(const vector<Student>& students)
{
    string entered_username, entered_password;
    cout << "\nEnter username: ";
    cin >> entered_username;
    cout << "Enter password: ";
    cin >> entered_password;

    // Search for a matching student
    bool success = false;
    for (const auto& student : students)
    {
        if (student.username == entered_username && student.password == entered_password)
        {
            cout << "\nLogin successful!" << endl;
            cout << "Welcome, " << student.name << endl;
            cout << "Your roll number is " << student.roll << endl;
            cout << "Your age is " << student.age << endl;
            success = true;
            break;
        }
    }

    if (!success)
    {
        cout << "Login failed! Invalid credentials.\n";
    }
}

int main()
{
    cout << "Welcome to the Student Registration System!\n";

    vector<Student> students;
    int num_students;

    cout << "Enter the number of students: ";
    cin >> num_students;

    // Declare variables for input
    string name, username, password;
    int roll, age;

    for (int i = 0; i < num_students; i++)
    {
        cout << "\nEnter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter student roll: ";
        cin >> roll;

        cout << "Enter student age: ";
        cin >> age;

        students.emplace_back(username, password, name, roll, age);
    }

    // Display all students' information
    cout << "\nRegistered Students:\n";
    for (const auto& student : students)
    {
        student.displayStudentInfo();
        cout << "------------------" << endl;
    }

    // Call the new login function
    cout << "\nLogin:\n";
    login(students);

    return 0;
}
