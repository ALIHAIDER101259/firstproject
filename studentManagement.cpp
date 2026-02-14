#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
 
    string name;
    cout<<"enter your name:"<<endl;
    getline(cin,name);


    int rollNo;
    cout<<"enter your roll no"<<endl;
    cin>>rollNo;

    cin.ignore();
     
    
    int total=0;
    float average=0;
    
   int marks[4];
   
    cout<<"enter your marks:"<<endl;
   
    
   for(int i=0; i<4;i++)
   {
       
       try{
       cin>>marks[i];
       
       if(marks[i]<0 || marks[i]>100)
       {
           throw "invalid marks";
       }
       }
       catch(const char*message){
           cout<<message;
           return 0;
       }
  
       
       total=total+marks[i];
   }
    average=total/4.0;
   
   
   cout<<"your total marks:"<<total<<endl;

   cout<<"\n";
   try
   {
      cout<<"your average are:"<<average<<endl;
    
    if(average>100)
    {
      throw "invalid average";
    
    }
  }
    
    catch(const char*msg){
      cout<<msg;
      return 0;
    }
   
   
   if(average>=90 && average<=100)
   {
       cout<<"grade A+"<<endl;
   }
   else if(average>=80 && average<=89)
   {
       cout<<"grade A "<<endl;
   }
   else if(average>=75 && average<=79){
       cout<<"grade b+"<<endl;
   }
   else if(average>=70 && average<=74){
       cout<<"grade b"<<endl;
   }
   else if(average>=60 && average<=69){
       cout<<"grade c"<<endl;
   }
   else if(average>=50 && average<=59){
       cout<<"grade d"<<endl;
   }
   else {
       cout<<"grade f"<<endl;
   }
   
   cout<<"information................."<<endl;
   cout<<"name:"<<name<<endl;
   cout<<"rollNO:"<<rollNo<<endl;
  cout<<"total:"<<total<<endl;  
  cout<<"average:"<<average<<endl;


  cout<<"what you want to see:"<<endl;
  cout<<"1.summary:"<<endl;
  cout<<"2.save data:"<<endl;

  int choice;
  cout<<"enter your choice:"<<endl;
  cin>>choice;

  
  
  switch(choice)
  {
      case 1:
  {
   cout<<"information................."<<endl;
   cout<<"name:"<<name<<endl;
   cout<<"rollNO:"<<rollNo<<endl;
  cout<<"total:"<<total<<endl;
  cout<<"average:"<<average<<endl;
  break;
  }
  
  case 2:{
      ofstream file("student.txt" );
      file<<name<<endl;
      file<<rollNo<<endl;
      file<<total<<endl;
      file<<average<<endl;
      file.close();
      cout<<"data save successfully";
      break;
  }
  
  default:
  cout<<" enter the right values"<<endl;
  break;
      }
  
  return 0;
    }
    

