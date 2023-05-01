#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Document.h
class Document{
private:
    string name;
    string extension;
    string contents;
public:
    Document(string nameIn, string extensionIn, string contentsIn);
    string GetName();
    void Rename(string newDocumentName);
    string GetExtension();
    string GetContents();
    void Print();

};

//Document.cpp
Document::Document(string nameIn, string extensionIn, string contentsIn){
    name = nameIn;
    extension = extensionIn;
    contents = contentsIn;
}
string Document::GetName(){
    return name;
}
void Document::Rename(string newDocumentName){
    name = newDocumentName;
}
string Document::GetExtension(){
    return extension;
}
string Document::GetContents(){
    return contents;
}
void Document::Print(){
    cout << "Name: " << name << "." << extension << endl;
    cout << "Contents: " << contents << endl;
}

//main.cpp----------
void DisplayMenu(){
    cout << "Choose an option below: "<< endl;
    cout << "1. Add a document to your list"<< endl;
    cout << "2. Rename one of your documents"<< endl;
    cout << "3. Share one of your documents with a friend"<< endl;
    cout << "4. Display all of the documents"<< endl;
    cout << "5. Quit"<< endl << endl;
}
std::string GetUserString(const std::string& prompt = "") {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}

int GetUserInt(const std::string& prompt = "") {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddDocument(vector<Document*>& myDocuments) {
    string name = GetUserString("Enter the document name: ");
    string extension = GetUserString("Enter the document extension: ");
    string content = GetUserString("Enter the document content: ");

    Document* ptrDocument;
    ptrDocument = new Document(name, extension, content);

    myDocuments.push_back(ptrDocument);
}

void RenameDocument(vector<Document*>& myDocuments) {
    int index = GetUserInt("Enter the index of your document you want to rename: ");
    string newName = GetUserString("Enter the updated name of the document: ");

    Document * currDoc = myDocuments.at(index);
    currDoc->Rename(newName);
    myDocuments.at(index) = currDoc;
}

void ShareDocument(vector<Document*> myDocuments, vector<Document*>& friendDocuments) {
    int index = GetUserInt("Enter the index of your document you want to share: ");
    Document * currDoc = myDocuments.at(index);
    friendDocuments.push_back(currDoc);
}

void DisplayDocuments(vector<Document*> myDocuments, vector<Document*> friendDocuments) {
    unsigned int i;

    cout << "-------------------Your List------------------" << endl;
    for (i = 0; i < myDocuments.size(); i++) {
        myDocuments[i]->Print();
    }

    cout << "--------------Your Friend's List--------------" << endl;
    for (i = 0; i < friendDocuments.size(); i++) {
        friendDocuments[i]->Print();
    }
    cout << "----------------------------------------------" << endl;
}

void ClearMemory(vector<Document*>& myDocuments, vector<Document*>& friendDocuments) {
    unsigned int i;

    for (i = 0; i < myDocuments.size(); i++) {
        delete myDocuments[i];
        myDocuments.erase(myDocuments.begin() + i);
        i--;
    }

    for (i = 0; i < friendDocuments.size(); i++) {
        friendDocuments.erase(friendDocuments.begin() + i);
        i--;
    }
}

// Modify the main function to handle each menu option
// Consider creating a new function (above main) per menu option
int main(){
    const int ADD_DOCUMENT_OPTION = 1;
    const int RENAME_DOCUMENT_OPTION = 2;
    const int SHARE_YOUR_DOCUMENT_OPTION = 3;
    const int DISPLAY_ALL_DOCUMENTS_OPTION = 4;
    const int QUIT_OPTION = 5;

    vector<Document*> myDocuments;
    vector<Document*> friendDocuments;

    int option;
    DisplayMenu();
    option = GetUserInt();

    while(option != QUIT_OPTION){

        if(option == ADD_DOCUMENT_OPTION){
            AddDocument(myDocuments);
        }
        else if(option == RENAME_DOCUMENT_OPTION){
            RenameDocument(myDocuments);
        }
        else if(option == SHARE_YOUR_DOCUMENT_OPTION){
            ShareDocument(myDocuments, friendDocuments);
        }
        else if(option == DISPLAY_ALL_DOCUMENTS_OPTION){
            DisplayDocuments(myDocuments, friendDocuments);
        }

        option = GetUserInt("Enter option: \n");
    }

    ClearMemory(myDocuments, friendDocuments);

    return 0;
}
