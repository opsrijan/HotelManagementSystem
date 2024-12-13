#include "func.h"

int main(){
    hotelChain* Taj= new hotelChain();
    hotel* h1 = new hotel();
    hotel* h2 = new hotel();
    vector <hotel*> taj;
    taj.push_back(h1);
    taj.push_back(h2);
    Taj->hotels=taj;

    employee* h1manager = new employee();
    h1manager->id=1;
    h1manager->name = "Ankit";
    h1manager->age=18;
    h1manager->job="manager";
    h1manager->male=1;
    h1manager->mail="k.srijan@iitg.ac.in";
    h1manager->phone="9006926888";
    h1manager->salary=100000;
    h1->employees.push_back(h1manager);

    employee* h1janitor = new employee();
    h1manager->id=2;
    h1manager->name = "Raj";
    h1manager->age=20;
    h1manager->job="janitor";
    h1manager->male=1;
    h1manager->mail="r.raj@iitg.ac.in";
    h1manager->phone="9006926888";
    h1manager->salary=50000;
    h1->employees.push_back(h1janitor);


    h1 -> stars = 5;
    h1->branch="Delhi";
    vector <room*> h1rooms;
    room* h1room101 = new room();
    room* h1room102 = new room();
    room* h1room201 = new room();
    room* h1room202 = new room();
    h1rooms.push_back(h1room101);
    h1rooms.push_back(h1room102);
    h1rooms.push_back(h1room201);
    h1rooms.push_back(h1room202);
    h1->rooms=h1rooms;

    h1room101->booked=0;
    h1room101->clean=1;
    h1room101->id=101;
    h1room101->renter=NULL;
    h1room101->size=2;
    h1room101->price=2000;
    
    h1room102->booked=0;
    h1room102->clean=1;
    h1room102->id=102;
    h1room102->renter=NULL;
    h1room102->size=1;
    h1room102->price=1000;
    
    h1room201->booked=0;
    h1room201->clean=1;
    h1room201->id=201;
    h1room201->renter=NULL;
    h1room201->size=2;
    h1room201->price=2000;
    
    h1room202->booked=0;
    h1room202->clean=1;
    h1room202->id=202;
    h1room202->renter=NULL;
    h1room202->size=3;
    h1room202->price=3000;





    employee* h2manager = new employee();
    h2manager->id=3;
    h2manager->name = "Bhanu";
    h2manager->age=30;
    h2manager->job="manager";
    h2manager->male=0;
    h2manager->mail="srijankumar2005@gmail.com";
    h2manager->phone="9155555112";
    h2manager->salary=100000;
    h2->employees.push_back(h2manager);

    
    employee* h2janitor = new employee();
    h1manager->id=4;
    h1manager->name = "Haloi";
    h1manager->age=37;
    h1manager->job="janitor";
    h1manager->male=1;
    h1manager->mail="r.raj@iitg.ac.in";
    h1manager->phone="9006926888";
    h1manager->salary=50000;
    h1->employees.push_back(h1janitor);


    h2->stars=4;
    h2->branch="Mumbai";
    vector <room*> h2rooms;
    room* h2room101 = new room();
    room* h2room102 = new room();
    room* h2room201 = new room();
    room* h2room202 = new room();
    h2rooms.push_back(h2room101);
    h2rooms.push_back(h2room102);
    h2rooms.push_back(h2room201);
    h2rooms.push_back(h2room202);
    h2->rooms=h2rooms;

    h2room101->booked=0;
    h2room101->clean=1;
    h2room101->id=101;
    h2room101->renter=NULL;
    h2room101->size=2;
    h2room101->price=2000;
    
    h2room102->booked=0;
    h2room102->clean=1;
    h2room102->id=102;
    h2room102->renter=NULL;
    h2room102->size=1;
    h2room102->price=1000;
    
    h2room201->booked=0;
    h2room201->clean=1;
    h2room201->id=201;
    h2room201->renter=NULL;
    h2room201->size=2;
    h2room201->price=2000;

    h2room202->booked=0;
    h2room202->clean=1;
    h2room202->id=202;
    h2room202->renter=NULL;
    h2room202->size=3;
    h2room202->price=3000;

    vector <string> feedbacks;
    feedbacks.push_back("fuddu");
    feedbacks.push_back("fdshkldfs");
    feedbacks.push_back("dfjkdsjiofjdso");
    feedbacks.push_back("fudi");

    while(true){
        cout<<"Welcome to Taj Hotel Group\n";
        cout<<"1. Log in as admin.\n";
        cout<<"2. Log in as customer.\n";
        int n;
        cin>>n;
        system("clear");
        string username, password;
        if (n==1){
            while (true){
                cout<<"Enter username:  (abc)";
                cin>>username;
                cout<<"Enter password:  (123)";
                cin>>password;
                system("clear");
                if (username=="abc" && password=="123"){
                    while(true){
                        cout<<"Logged in as the admin.\n";
                        cout<<"Welcome to Taj Hotel Group.\n";
                        cout<<"01. Check a particular hotel.\n";
                        cout<<"02. View all feedbacks.\n";
                        cout<<"03. Logout.\n";
                        cin>>n;
                        system("clear");
                        if (n==1){
                            n=0;
                            while(true){
                                if (Taj->hotels.size()==0){
                                    cout<<"No hotels in the hotel chain.\n\n";
                                    break;
                                }
                                cout<<"Branches in TAJ HOTEL GROUP:\n";
                                for (int i=0; i<Taj->hotels.size(); i++){
                                    cout<<i+1<<". "<<Taj->hotels[i]->branch<<endl;
                                }
                                int x;
                                cin>>x;
                                system("clear");
                                if (x>Taj->hotels.size() || x<1){
                                    cout<<"Enter a valid choice.\n";
                                }
                                else{
                                    while(true) {    
                                        cout<<"Welcome to Taj Hotel Group.\n\t";
                                        hotel* currHotel=Taj->hotels[x-1];
                                        cout<<currHotel->branch <<" --> "<<currHotel->stars<<" stars\n";
                                        cout<<"\n01. Check-in a customer.\n";
                                        cout<<"02. Check-out a customer.\n";
                                        cout<<"03. View all rooms.\n";
                                        cout<<"04. View available rooms.\n";
                                        cout<<"05. View all employees.\n";
                                        cout<<"06. View customer log\n";
                                        cout<<"07. Update room status.\n";
                                        cout<<"08. Add a new employee.\n";
                                        cout<<"09. Delete an employee.\n";
                                        cout<<"10. Add a new room.\n";
                                        cout<<"11. Delete a room.\n";
                                        cout<<"12. Log out.\n";
                                        cin>>n;
                                        system("clear");
                                        if (n==1){
                                            checkInCustomer(currHotel);
                                        }
                                        else if (n==2){
                                            checkOutCustomer(currHotel);
                                        }
                                        else if (n==3){
                                            displayAllRooms(currHotel);
                                        }
                                        else if (n==4){
                                            displayAvailableRooms(currHotel);
                                        }
                                        else if (n==5){
                                            displayAllEmployees(currHotel);
                                        }
                                        else if (n==6){
                                            displayCustomerLog(currHotel);
                                        }
                                        else if (n==7){
                                            updateRoomStatus(currHotel);
                                        }
                                        else if (n==8){
                                            addEmployee(currHotel);
                                        }
                                        else if (n==9){
                                            deleteEmployee(currHotel);
                                        }
                                        else if (n==10){
                                            addRoom(currHotel);
                                        }
                                        else if (n==11){
                                            deleteRoom(currHotel);
                                        }
                                        else if (n==12){
                                            n=-1;
                                            break;
                                        }
                                        else{
                                            cout<<"Enter a valid choice.\n";
                                        }
                                    }
                                }
                                if (n==-1) break;
                            }
                        }
                        else if (n==2){
                            //view all Feedbacks.
                            for (int i=0; i<feedbacks.size(); i++){
                                cout<<i+1<<". "<<feedbacks[i]<<endl;
                            }
                            cout<<"Delete a feedback?\n0. No\t\t 1. Yes\n";
                            cin>>n;
                            system("clear");
                            if (n){
                                cout<<"Which feedback to erase?\n";
                                cin>>n;
                                system("clear");
                                if (n<=feedbacks.size() && n>0){
                                    feedbacks.erase(feedbacks.begin()+n-1);
                                }else{
                                    cout<<"Enter a valid index.\n";
                                }
                            }

                        }
                        else if (n==3){
                            n=-1;
                            break;
                        }
                        else{ 
                            cout<<"Enter a valid choice.\n";
                        }
                    }   
                }
                else{
                    while(true){
                        cout<<"Wrong username, password.\n";
                        cout<<"01. Retry.\n";
                        cout<<"02. Back.\n";
                        cin>>n;
                        system("clear");
                        if (n==1){
                            break;
                        }else if (n==2){
                            n=-1;
                            break;
                        }
                        else{
                            cout<<"Enter a valid choice.\n";
                        }
                    }
                }
                if (n==-1) break;
            }
        } 
        else if (n==2){
            while(true){
                cout<<"Logged in as a customer.\n";
                cout<<"Welcome to Taj Hotel Group.\n";
                cout<<"1. Log a complaint / Give Feedback\n";
                cout<<"2. View important contacts\n";
                cout<<"3. Log Out.\n";
                cin>>n;
                if (n==1){
                    system("clear");
                    cout<<"Log a complaint / Give Feedback\n";
                    string s; cin>>s;
                    feedbacks.push_back(s);
                }
                else if (n==2){
                    system("clear");
                    cout<<"01. Reception\n";
                    cout<<"02. Janitor\n";
                    cout<<"03. AC/geyser issue\n";
                    cout<<"108 Emergency contact\n";
                    cout<<"102 Ambulance\n";
                    cout<<"103 Fire truck\n";
                }
                else if (n==3){
                    n=-1;
                    break;
                }
                else{
                    cout<<"Enter a valid choice.\n";
                }
            }
        } 
        else{
            system("clear");
            cout<<"Press 1 or 2.\n";
        }
    }


    
return 0;
}
