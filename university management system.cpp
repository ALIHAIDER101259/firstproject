// university management system
#include <iostream>

#include <string>

using namespace std;

class Person
{
private:
  string name;
  int age;

public:
  Person(string n, int a)
  {
    name = n;
    age = a;
  }

  // setter

  void setName(string nam)
  {
    name = nam;
  }
  void setAge(int ag)
  {
    age = ag;
  }

  // getter

  string getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }
  void displayInfo()
  {
    cout << "person name:" << name << endl;
    cout << "person age:" << age << endl;
  }
};

class Researcher
{
private:
  string field;

public:
  Researcher(string f)
  {
    field = f;
  }

  void displayResearcher()
  {
    cout << field << endl;
  }
};

class Professor : public Person, public Researcher
{
private:
  string course;

public:
  Professor(string n, int a, string f, string cour) : Person(n, a), Researcher(f)
  {
    course = cour;
  }

  void displayProfessorInfo()
  {
    cout << "professor course:" << course << endl;
    displayInfo();
    displayResearcher();
  }
};
class Student : public Person
{
private:
  int rollNo;
  string course;

public:
  Student(string n, int a, int r, string c) : Person(n, a)
  {
    rollNo = r;
    course = c;
  }

  void displayStudentinfo()
  {
    cout << " student rollno:" << rollNo << endl;
    cout << " student course:" << course << endl;
    displayInfo();
  }
};

class Employee : public Student
{
private:
  int employeeId;
  double salary;

public:
  Employee(string n, int a, int r, string c, int e, double s) : Student(n, a, r, c)
  {
    employeeId = e;
    salary = s;
  }
  void displayInformation()
  {
    cout << "employee id:" << employeeId << endl;
    cout << "employee salary:" << salary << endl;
    displayStudentinfo();
  }
};
int main()
{

  cout << "information of first person..." << endl;

  Employee e("ali haider", 20, 65333, "calculus", 7889, 900.087);
  e.displayInformation();

  cout << endl;
  cout << endl;

  Employee e1("usman", 20, 0, " ", 0, 0);

  cout << "your name:" << e1.getName() << endl;
  cout << "your age:" << e1.getAge() << endl;

  cout << "information of second person..." << endl;

  Professor p("Dr. Khan", 45, "Quantum Physics", "Physics 101");
  p.displayProfessorInfo();

  cout << endl;

  cout << "information of third person..." << endl;
  Employee e2("haider", 30, 65222, "software", 390, 9000.87);
  e2.displayInformation();

  cout << endl;
  cout << endl;

  cout << "information of fourth person..." << endl;
  Employee e3("ibrahim", 90, 61111, "cyber", 890, 7000.7);
  e3.displayInformation();

  return 0;
}
