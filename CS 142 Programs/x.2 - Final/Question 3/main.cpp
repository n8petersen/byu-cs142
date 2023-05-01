#include <iostream>
using namespace std;

class Door {
public:
    Door(bool open = false, bool locked = true); // Default Constructor

    void OpenDoor();
    void CloseDoor();
    void LockDoor();
    void UnlockDoor();

private:
    bool isOpen;
    bool isLocked;
};

Door::Door(bool open, bool locked) {
    isOpen = open;
    isLocked = locked;
}

void Door::OpenDoor() { // Opens the door, if it is closed and not locked.
    if (isOpen) {
        cout << "The door is already open" << endl;
    }
    else if (isLocked) {
        cout << "Sorry, the door is locked" << endl;
    }
    else isOpen = true;
}

void Door::CloseDoor() { // Closes the door, if it is open.
    if (!isOpen) {
        cout << "The door is already shut" << endl;
    }
    else isOpen = false;
}

void Door::LockDoor() { // Locks the door, if it is shut and unlocked.
    if (isOpen) {
        cout << "Sorry, the door is open" << endl;
    }
    else if (isLocked) {
        cout << "The door is already locked" << endl;
    }
    else isLocked = true;
}

void Door::UnlockDoor() { // Unlocks the door, if it is shut and locked.
    if (isOpen) {
        cout << "Sorry, the door is open" << endl;
    }
    else if (!isLocked) {
        cout << "The door is already unlocked" << endl;
    }
    else isLocked = false;
}




//Do not edit below this line-----------------------------------------------------------------

int main() {
    Door pantryDoor;
    Door frontDoor;


    frontDoor.LockDoor();
    frontDoor.UnlockDoor();
    frontDoor.UnlockDoor();
    frontDoor.OpenDoor();
    frontDoor.LockDoor();
    frontDoor.UnlockDoor();
    frontDoor.CloseDoor();
    frontDoor.LockDoor();
    frontDoor.LockDoor();
    pantryDoor.OpenDoor();
    pantryDoor.UnlockDoor();
    pantryDoor.OpenDoor();
    pantryDoor.OpenDoor();
    frontDoor.CloseDoor();
    pantryDoor.CloseDoor();
    pantryDoor.CloseDoor();
    pantryDoor.LockDoor();
    pantryDoor.OpenDoor();

    return 0;
}
