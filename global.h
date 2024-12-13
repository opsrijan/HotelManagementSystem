#include<bits/stdc++.h>
#include <conio.h>
using namespace std;

struct customer{
    int id;
    string name;
    int age;
    bool male;
    string phone;
    string mail;
    int checkInDate;
    int checkInMonth;
    int checkOutDate;
    int checkOutMonth;
};

struct employee{
    struct hotel* workhotel;
    int id;
    string name;
    int age;
    bool male;
    string phone;
    string mail;
    long long salary;
    string job;
};

struct room{
    int id;
    bool booked;
    bool clean;
    int size;
    long long price;
    struct customer* renter;
};

struct hotel{
    string branch;
    int stars;
    vector <room*> rooms;
    vector <employee*> employees;
};

struct hotelChain{
    vector <hotel*> hotels;
};
