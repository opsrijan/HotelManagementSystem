#include "global.h"

void displayAvailableRooms(hotel* h){
    cout<<"\n Taj hotel group";
    cout<<h->branch;
    cout<<"\nroom_id    cleaned    size     price(in $)\n";
    if (!h) return;
    for (int i=0; i<h->rooms.size(); i++){
        if (!h->rooms[i]->booked){
            cout<<h->rooms[i]->id<<"\t\t";
            if (h->rooms[i]->clean) cout<<"YES\t";
            else cout<<"NO \t";
            cout<<h->rooms[i]->size<<"\t";
            cout<<h->rooms[i]->price<<"\n";
        }
    }
    cout<<"\nAll rooms printed.\n";
}

void displayAllRooms(hotel* h){
    cout<<"\nTaj hotel group\n\t";
    cout<<h->branch<<"  ";
    for (int i=0; i<h->stars; i++) cout<<'*';
    cout<<"\nroom_id     cleaned     size    booked     price(in $)   customerName\n";
    if (!h) return;
    for (int i=0; i<h->rooms.size(); i++){
        cout<<h->rooms[i]->id<<"\t    ";
        if (h->rooms[i]->clean) cout<<"YES\t\t";
        else cout<<"NO \t\t";
        cout<<h->rooms[i]->size<<"\t";
        if (h->rooms[i]->booked) cout<<"YES\t   ";
        else cout<<"NO \t   ";
        cout<<h->rooms[i]->price<<"\t\t ";
        if (h->rooms[i]->renter) cout<<h->rooms[i]->renter->name<<"\n";
        else cout<<endl;
    }
    cout<<"\nAll rooms printed.\n";
}

void displayAllEmployees(hotel* h) {
    if (!h) {
        cout << "Invalid hotel.\n";
        return;
    }

    if (h->employees.empty()) {
        cout << "No employees currently work at hotel " << h->branch << ".\n";
        return;
    }

    cout << "\nEmployees in hotel " << h->branch << ":\n";
    cout << "ID\tName\t\tAge\tGender\tPhone\t\t\tEmail\t\t\tJob\t\t\tSalary\n";

    for (const auto& emp : h->employees) {
        cout << emp->id << "\t"<< emp->name << "\t\t"<< emp->age << "\t" << (emp->male ? "Male" : "Female") << "\t" << emp->phone << "\t"<< emp->mail << "\t"<< emp->job << "\t\t"<< emp->salary << "\n";
    }
}


void displayCustomerLog(hotel* h) {
    if (!h) {
        cout << "Invalid hotel.\n";
        return;
    }

    bool hasCustomers = false;

    cout << "Customer Log for Hotel: " << h->branch << "\n";
    cout << "--------------------------------------------------\n";
    cout << "Room ID | Customer ID | Name        | Gender | Phone        | Email                | Check-in    | Check-out\n";
    cout << "--------------------------------------------------\n";

    for (const auto& room : h->rooms) {
        if (room->renter != nullptr) {
            hasCustomers = true;
            customer* c = room->renter;

            // Format gender
            string gender = c->male ? "Male" : "Female";

            // Display customer details
            cout << setw(8) << room->id << " | ";
            cout << setw(11) << c->id << " | ";
            cout << setw(12) << c->name << " | ";
            cout << setw(6) << gender << " | ";
            cout << setw(12) << c->phone << " | ";
            cout << setw(20) << c->mail << " | ";
            cout << setw(4) << c->checkInDate << "/" << setw(2) << c->checkInMonth << " | ";
            cout << setw(4) << c->checkOutDate << "/" << setw(2) << c->checkOutMonth << "\n";
        }
    }

    if (!hasCustomers) {
        cout << "No customers have checked in yet.\n";
    }

    cout << "--------------------------------------------------\n";
}


void checkInCustomer(hotel* h) {
    if (!h) {
        cout << "Invalid hotel.\n";
        return;
    }
    customer* newCustomer = new customer;

    cout<<"Enter customer ID: ";
    cin>>newCustomer->id;
    cout<<"Enter customer name: ";
    cin.ignore();
    getline(cin, newCustomer->name);
    cout<< "Enter age: ";
    cin>> newCustomer->age;
    cout<< "Gender (0 for Female, 1 for Male): ";
    cin>> newCustomer->male;
    cout<< "Enter phone number: ";
    cin >>newCustomer->phone;
    cout <<"Enter email: ";
    cin >>newCustomer->mail;
    cout<< "Check-in date (DD MM): ";
    cin>> newCustomer->checkInDate >> newCustomer->checkInMonth;
    cout <<"Check-out date (DD MM): ";
    cin >>newCustomer->checkOutDate >> newCustomer->checkOutMonth;

    cout << "\nAvailable rooms: \n";
    displayAvailableRooms(h);

    int roomId;
    cout << "Enter the room ID to assign: ";
    cin >> roomId;

    for (auto& room : h->rooms) {
        if (room->id == roomId && !room->booked) {
            room->booked = true;
            room->renter = newCustomer;
            cout << "Customer " << newCustomer->name << " has been checked into the room " << room->id << ".\n";
            return;
        }
    }

    cout << "Invalid room ID or room already booked.\n";
    delete newCustomer;
}

void checkOutCustomer(hotel* h) {
    if (!h) {
        cout << "Invalid hotel.\n";
        return;
    }

    int roomId;
    cout << "Enter the room ID for check-out: ";
    cin >> roomId;

    for (auto& room : h->rooms) {
        if (room->id == roomId && room->booked) {
            customer* renter = room->renter;
            if (!renter) {
                cout << "No customer in this room.\n";
                return;
            }

            int stayDays = (renter->checkOutMonth - renter->checkInMonth) * 30 +
                           (renter->checkOutDate - renter->checkInDate);

            if (stayDays <= 0) stayDays = 1; // Default to 1 day if dates are invalid.

            double totalCost = stayDays * room->price;
            cout << "Customer " << renter->name << " has checked out.\n";
            cout << "Total cost for stay: $" << totalCost << "\n";

            delete renter;
            room->renter = nullptr;
            room->booked = false;
            return;
        }
    }

    cout << "Invalid room ID or room not currently booked.\n";
}

void updateRoomStatus(hotel* h) {
    if (!h) {
        cout << "Invalid hotel.\n";
        return;
    }

    int roomId;
    cout << "Enter the room ID to update: ";
    cin >> roomId;

    for (auto& room : h->rooms) {
        if (room->id == roomId) {
            cout << "Current room status:\n";
            cout << "Clean: " << (room->clean ? "Yes" : "No") << "\n";
            cout << "Booked: " << (room->booked ? "Yes" : "No") << "\n";

            int choice;
            cout << "1. Toggle cleanliness\n";
            cout << "2. Toggle booking status (if no renter)\n";
            cout << "3. Press any other key to skip.\n";
            cin >> choice;

            if (choice == 1) {
                room->clean = !room->clean;
                cout << "Cleanliness updated.\n";
            } else if (choice == 2 && !room->booked) {
                room->booked = !room->booked;
                cout << "Booking status updated.\n";
            } else {
                cout << "Invalid choice or room currently booked.\n";
            }
            return;
        }
    }

    cout << "Room ID not found.\n";
}

void addEmployee(hotel* h) {
    if (!h) {
        cout << "Invalid hotel.\n";
        return;
    }

    employee* newEmployee = new employee;

    cout << "Enter employee ID: ";
    cin >> newEmployee->id;
    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, newEmployee->name);
    cout << "Enter age: ";
    cin >> newEmployee->age;
    cout << "Gender (0 for Female, 1 for Male): ";
    cin >> newEmployee->male;
    cout << "Enter phone number: ";
    cin >> newEmployee->phone;
    cout << "Enter email: ";
    cin >> newEmployee->mail;
    cout << "Enter job title: ";
    cin.ignore();
    getline(cin, newEmployee->job);
    cout << "Enter salary: ";
    cin >> newEmployee->salary;

    newEmployee->workhotel = h;
    h->employees.push_back(newEmployee);
    cout << "Employee " << newEmployee->name << " has been added.\n";
}

void deleteEmployee(hotel* h) {
    if (!h) {
        cout << "Invalid hotel.\n";
        return;
    }

    int empId;
    cout << "Enter the employee ID to delete: ";
    cin >> empId;

    for (auto it = h->employees.begin(); it != h->employees.end(); ++it) {
        if ((*it)->id == empId) {
            delete *it;
            h->employees.erase(it);
            cout << "Employee with ID " << empId << " has been deleted.\n";
            return;
        }
    }

    cout << "Employee ID not found.\n";
}

void addRoom(hotel* h) {
    if (!h) {
        cout << "Invalid hotel.\n";
        return;
    }

    room* newRoom = new room;
    cout << "Enter Room ID: ";
    cin >> newRoom->id;

    for (const auto& existingRoom : h->rooms) {
        if (existingRoom->id == newRoom->id) {
            cout << "Room ID already exists.\n";
            delete newRoom;
            return;
        }
    }

    cout << "Enter Room Size: ";
    cin >> newRoom->size;

    cout << "Enter Room Price: ";
    cin >> newRoom->price;

    newRoom->booked = false;
    newRoom->clean = true;
    newRoom->renter = nullptr;

    h->rooms.push_back(newRoom);

    cout << "Room added successfully.\n";
}

void deleteRoom(hotel* h) {
    if (!h) {
        cout << "Invalid hotel.\n";
        return;
    }

    if (h->rooms.empty()) {
        cout << "No rooms available to delete in hotel " << h->branch << ".\n";
        return;
    }

    cout << "Enter the Room ID to delete: ";
    int roomId;
    cin >> roomId;

    for (auto it = h->rooms.begin(); it != h->rooms.end(); ++it) {
        if ((*it)->id == roomId) {
            delete *it;
            h->rooms.erase(it);
            cout << "Room with ID " << roomId << " deleted successfully.\n";
            return;
        }
    }

    cout << "Room with ID " << roomId << " not found.\n";
}
