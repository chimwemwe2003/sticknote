#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define the class outside of the main() function.
class Note {
public:
    string content;

    Note(string text) {
        content = text;
    }
};

// Declare the vector outside of the main() function so it's accessible globally.
vector<Note> notes;

// Function to create a note.
void createNote() {
    string text;
    cout << "Enter your note: ";
    cin.ignore(); // Ensure getline works after cin >>.
    getline(cin, text);
    notes.push_back(Note(text));
}

// Function to display all notes.
void displayNotes() {
    for (size_t i = 0; i < notes.size(); ++i) {
        cout << i + 1 << ": " << notes[i].content << endl;
    }
}

// Function to delete a note.
void deleteNote() {
    int index;
    cout << "Enter the note number to delete: ";
    cin >> index;

    if (index > 0 && index <= notes.size()) {
        notes.erase(notes.begin() + index - 1);
        cout << "Note deleted successfully!" << endl;
    } else {
        cout << "Invalid note number." << endl;
    }
}

// Main menu system
int main() {
    int choice;

    do {
        cout << "\nSticky Notes Menu:\n";
        cout << "1. Create Note\n";
        cout << "2. Display Notes\n";
        cout << "3. Delete Note\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createNote();
            break;
        case 2:
            displayNotes();
            break;
        case 3:
            deleteNote();
            break;
        case 4:
            cout << "Exiting the app. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}