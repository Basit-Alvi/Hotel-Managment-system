#include<iostream>
 
using namespace std;

struct Reservation {
    int roomNo;
    string guestName;
    string checkIn;
    string checkOut;
    bool isBooked;
};

Reservation room[30];
int totalroom = 30;  


void bookRoom() {

    int i;   

    for(i = 0; i < totalroom; i++) {
        if(!room[i].isBooked)
            break;
    }

    if(i == totalroom) {
        cout << "All rooms are already booked.\n";
        return;
    }

    cin.ignore();   

    cout << "Enter Guest Name: ";
    getline(cin, room[i].guestName);

    cout << "Enter Check-in Date: ";
    getline(cin, room[i].checkIn);

    cout << "Enter Check-out Date: ";
    getline(cin, room[i].checkOut);

    room[i].isBooked = true;
    cout << "Room booked successfully.\n";
}


void cancelBooking() {
    int roomNo;
    cout << "Enter room index (0 to " << totalroom-1 << "): ";
    cin >> roomNo;

//    if(roomNo < 0 || roomNo >= totalroom) {
//        cout << "Invalid room.\n";
//        return;
//    }

    if(room[roomNo].isBooked) {
        room[roomNo].isBooked = false;
        cout << "Booking canceled.\n";
    } else {
        cout << "Room is not booked.\n";
    }
}


void checkRoomAvailability() {
    for(int i = 0; i < totalroom; i++) {
        cout << "Room " << room[i].roomNo << ": ";
        if(room[i].isBooked)
            cout << "Booked\n";
        else
            cout << "Available\n";
    }
}


void viewBooking() {
    bool found = false;

    for(int i = 0; i < totalroom; i++) {
        if(room[i].isBooked) {
            cout << "\nRoom No: " << room[i].roomNo << endl;
            cout << "Guest Name: " << room[i].guestName << endl;
            cout << "Check-in: " << room[i].checkIn << endl;
            cout << "Check-out: " << room[i].checkOut << endl;
            found = true;
        }
    }

    if(!found)
        cout << "No booking found.\n";
}

int main() {

   
    for(int i = 0; i < totalroom; i++) {
        room[i].roomNo =1 + i;   
        room[i].isBooked = false;
    }

    int choice;
    do {
        cout << "\n--- Hotel Reservation Menu ---\n";
        cout << "1. Book Room\n";
        cout << "2. Cancel Booking\n";
        cout << "3. Check Availability\n";
        cout << "4. View Booking\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: bookRoom(); break;
            case 2: cancelBooking(); break;
            case 3: checkRoomAvailability(); break;
            case 4: viewBooking(); break;
            case 5: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice.\n";

        }
    } while(choice != 5);

    return 0;
}

