#include<iostream>
using namespace std;

void trafficSignal()
{
  cout<<"welcome traffic signal"<<endl;
    
    cout<<"\n";
    
    cout<<" case 1:green go"<<endl;
    cout<<" case 2:red stop"<<endl;
    cout<<" case 3:yellow be ready"<<endl;
    cout<<" case 4: Exist the program.."<<endl;
    
    cout<<"\n";
    
    int choice;
    cout<<"enter your choice"<<endl;
    cin>>choice;
    
    cout<<"\n";
    
    switch(choice)
    {
        case 1:
        {
        cout<<"green: you can go  🚦"<<endl;
        
        cin.ignore();
        
        string travel;
        cout<<"enter your travel(night or morning)"<<endl;
        getline(cin,travel);
        
        if(travel=="day")
        {
            cout<<"be carefully in morning for driving "<<endl;
        }
        else {
            cout<<"turn your light in night driving"<<endl;
        }
    break;
    }
    
    
    case 2:
    {
    
        cout<<"red: you cannot go 🚫"<<endl;
        
        string value;
        cout<<"enter the value for situation (true:stop/false:wait)"<<endl;
         cin.ignore();
       getline(cin,value);
       
      
        bool isEmergency;
     
        if(value=="true")
        {
             isEmergency=true;
            cout<<"stop 🛑 for emergency situation"<<endl;
            
        }
        
        else{
             isEmergency=false;
            cout<<"wait for it "<<endl;
           
            }
    break;
        
    }
    
    case 3:
    {
       
    
        cout<<"yellow: be ready for go ⚠️"<<endl;
        
        int speed;
        cout<<"enter your speed"<<endl;
        cin>>speed;
        
        if(speed>60)
        {
            cout<<"slow down"<<endl;
        }
        else {
            cout<<"ready for go"<<endl;
        }
    break;
    }
    
    case 4:
    {
       
        cout<<"exist the program..."<<endl;
    
    break;
    }
    
    default:
    {
        cout<<"enter the valid value:"<<endl;
        break;
    }
    }
}
int main()
{
    trafficSignal();
    return 0;
}