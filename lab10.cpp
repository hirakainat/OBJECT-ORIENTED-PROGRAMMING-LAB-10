#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    
    Person(const string& n, int a) : name(n), age(a){}
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    virtual ~Person() 
    {
        cout << "Person object destroyed." << endl;
    }
};
class Student : public Person
{
private:
    string studentID;

public:
    Student(const string& n, int a, const string& id) : Person(n, a), studentID(id) {}
    void displayInfo() override
    {
        Person::displayInfo(); 
        cout << "Student ID: " << studentID << endl;
    }
    ~Student() override 
    {
        cout << "Student object destroyed." << endl;
    }
};
class School 
{
private:
    const string schoolName;
    School(const string& name) : schoolName(name) {}

public:
   
    static School* createSchool(const string& name) 
    {
        return new School(name);
    }
    const string& getSchoolName() const 
    {
        return schoolName;
    }
};
int main() 
{
    string name, studentID;
    int age;
    cout << "Enter Person's name: ";
    getline(cin, name); 
    cout << "Enter Person's age: ";
    cin >> age;
    cout << "Enter Student's ID: ";
    cin.ignore(); 
    getline(cin, studentID);
    Person* p1 = new Person(name, age);
    Student* s1 = new Student(name, age, studentID);

    cout << endl << "Person Information:" << endl;
    p1->displayInfo();

    cout << endl << "Student Information:" << endl;
    s1->displayInfo();

    cout << endl << "Enter School Name: ";
    cin.ignore();
    getline(cin, name);

    School* school = School::createSchool(name);

    cout << endl << "School Name: " << school->getSchoolName() << endl;

    delete p1;
    delete s1;
    delete school;
    system("pause");
    return 0;
}