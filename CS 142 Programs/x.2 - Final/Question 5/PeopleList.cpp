#include "PeopleList.h"
#include <iostream>

using namespace std;

//TODO: Make to it adds people to the list in the correct order
// currently it just adds them to the end of the list.
/*
void PeopleList::Add(Person toAdd){
    //determine where to put the new person...
    unsigned int indexToInsertAt = 0;

    //special case -- no people in the list yet
    if(people.size() == 0){
        indexToInsertAt = 0;
    }
        //find the correct location, which is the position where the
        //next element in the list is "bigger"
    else {
        while(indexToInsertAt < people.size() && toAdd.LessThan(people.at(indexToInsertAt))){
            indexToInsertAt++;
        }
    }
    people.insert(people.begin() + indexToInsertAt, toAdd);
}
 */

void PeopleList::Add(Person toAdd) {
    unsigned int i;

    for (i = 0; i < people.size(); ++i) {
        if (toAdd.LessThan(people.at(i))) {
            people.insert(people.begin() + i, toAdd);
            break; // Exits the for loop
        }
    }

    // Change "true" to "i == ??" (determine what ?? should be)
    if (i == people.size()) { // No higher number was found, so append to end
        people.push_back(toAdd);

    }
}

void PeopleList::PrintList(){
    for(unsigned int i = 0; i < people.size(); i++){
        cout << people.at(i).Name() << " " << people.at(i).Age() << endl;
    }
}

int PeopleList::Size(){
    return people.size();
}
