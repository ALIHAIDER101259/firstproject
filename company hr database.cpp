#include <iostream>
#include <fstream>
using namespace std;
class Person
{
private:
  string name;
  int age;

public:
  Person()
  {
    name = "unknown";
    age = 0;
  }

  void setData(string n = "", int a = 0)
  {
    name = n;
    age = a;
  }

  void display1()
  {
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
  }

  void save(ofstream &f)
  {
    f << "name:" << name;
    f << "age:" << age;
  }
};

class Employee : public Person
{
private:
  int employeeId;
  float Salary;

public:
  Employee()
  {
    employeeId = 0;
    Salary = 0;
  }

  void SetEmployee(int empl, float Sal)
  {
    employeeId = empl;
    Salary = Sal;
  }

  void setCritearia()
  {
    if (Salary >= 10000.0 && Salary <= 20000.0)
    {
      cout << "valid salary" << endl;
    }
    else
    {
      cout << "invalid salary" << endl;
    }
  }

  void display2()
  {
    cout << "employee id:" << employeeId << endl;
    cout << "Salary:" << Salary << endl;
    setCritearia();
  }

  void save(ofstream &f)
  {
    f << "employee id:" << employeeId;
    f << "salary:" << Salary;
  }
};

class Manager : public Employee
{
private:
  string department;
  float bonus;

public:
  Manager()
  {
    department = "";
    bonus = 0.0;
  }
  void setManager(string dep = "", float bon = 0.0)
  {
    department = dep;
    bonus = bon;
  }

  void displayManager()
  {
    cout << "department:" << department << endl;
    cout << "bonus:" << bonus << endl;
  }

  void save(ofstream &f)
  {
    f << "department:" << department;
    f << "bonus:" << bonus;
  }
};

int main()
{

  cout << endl;
  cout << endl;

  Person p1;
  p1.setData("Ali Haider", 20);
  p1.display1();

  Employee e1;
  e1.SetEmployee(65333, 8000.9f);
  e1.display2();

  Manager m1;
  m1.setManager("software-enginerring", 5606.9f);
  m1.displayManager();

  cout << endl;
  cout << endl;

  cout << "1.person class" << endl;
  cout << "2.Employee class" << endl;
  cout << "3.Manager class" << endl;
  cout << "4.Save data" << endl;
  cout << "5.exist program" << endl;

  cout << endl;
  cout << endl;

  int choice;
  do
  {

    cout << "enter your choice" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      p1.display1();
      break;
    }

    case 2:
    {

      e1.display2();
      break;
    }

    case 3:
    {

      m1.displayManager();
      break;
    }

    case 4:
    {

      ofstream myfile("employee.txt");

      if (!myfile)
      {
        cout << "file is not showing!!" << endl;
        break;
      }

      e1.save(myfile);
      myfile << endl;

      p1.save(myfile);
      myfile << endl;

      m1.save(myfile);
      myfile << endl;
      cout << "successfully data save..." << endl;
      break;
    }

    case 5:
    {
      cout << "program end...." << endl;
      break;
    }

    default:
    {
      cout << "invalid value" << endl;
      break;
    }
    }
  } while (choice != 4);
  return 0;
}
