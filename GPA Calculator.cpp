#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  cout<<"================================================================="<<endl;
  cout<<"                         GPA CALCULATOR                          "<<endl;
  cout<<"================================================================="<<endl;

  int courseRange;
  cout<<"how much do you want to enter the subjects in integer form"<<endl;
  cin>>courseRange;


  int credits[50];

  string subjects[50];

  string grade[50];

  double addPoints=0;     //extra variable
  int totalCreditHours=0;
  double initialPoints;




  double calculategpa;

  cin.ignore();

  for(int i=0;i<courseRange;i++)
  {


    cout<<"enter the subjects"<<endl;
    getline(cin,subjects[i]);


    

   

    cout<<"enter the credit hours"<<endl;
    cin>>credits[i];

    

    cout<<"enter the grade"<<endl;
    cin>>grade[i];

    cin.ignore();

    


    if(grade[i]=="A+" || grade[i]=="a+")
    {
       initialPoints =4.3;
    }
    else if(grade[i]=="A" || grade[i]=="a")
    {
      initialPoints=4;
    }
    else if(grade[i]=="A-" || grade[i]=="a-")
    {
      initialPoints= 3.7;
    }
    else if(grade[i]=="B+" || grade[i]=="b+"){
      initialPoints= 3.3;
    }
    else if(grade[i]=="B" || grade[i]=="b"){
      initialPoints= 3.0;
    }
    else if(grade[i]=="C+" || grade[i]=="c+")
    {
      initialPoints= 2.3;
    }
    else if(grade[i]=="C"|| grade[i]=="c")
    {
      initialPoints =2.0;
    }
    else if(grade[i]=="C-"|| grade[i]=="c-"){
      initialPoints= 1.7;
    }
    else if(grade[i]=="D+" || grade[i]=="d+"
    )
    {
      initialPoints= 1.3;
    }
    else if(grade[i]=="D"|| grade[i]=="d"){
      initialPoints= 1;
    }
    else {
      initialPoints= 0;
    }

    totalCreditHours=totalCreditHours+credits[i];
    addPoints += initialPoints * credits[i];

    
  }

  calculategpa=addPoints/totalCreditHours;


  cout<<"output subjects and credit hours by user"<<endl;

  for(int i=0;i<courseRange;i++)
  {

    cout<<"========================================================================"<<endl;
    cout<<"                                    output                             "<<endl;
    cout<<"========================================================================"<<endl;
    cout<<left;
    cout<<setw(15)<<subjects[i]
    <<setw(15)<<credits[i]
    <<setw(15)<<grade[i]<<endl;
  }
  

  cout<<"==============================================================================="<<endl;
  cout<<"                                final GPA                       "<<endl;
  cout<<"==============================================================================="<<endl;
  cout<<calculategpa<<endl;

  return 0;


}