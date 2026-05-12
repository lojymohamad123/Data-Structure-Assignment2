#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Patient {
    int id;
    string name;
    int severity;
    int arrivalTime;
};

// Compare priority
// Higher severity = higher priority
// If equal severity -> earlier arrival time = higher priority
bool isHigherPriority(Patient firstPatient, Patient secondPatient) {

    if (firstPatient.severity > secondPatient.severity)
        return true;

    if (firstPatient.severity == secondPatient.severity &&
        firstPatient.arrivalTime < secondPatient.arrivalTime)
        return true;

    return false;
}

int parent(int index) {
    return (index - 1) / 2;
}

// Heapify Down
void heapify(vector<Patient>& patients, int index) {

    int size = patients.size();

    int highestPriorityIndex = index;

    int leftChild = (2 * index) + 1;
    int rightChild = (2 * index) + 2;

    if (leftChild < size &&
        isHigherPriority(patients[leftChild],
                         patients[highestPriorityIndex])) {

        highestPriorityIndex = leftChild;
    }

    if (rightChild < size &&
        isHigherPriority(patients[rightChild],
                         patients[highestPriorityIndex])) {

        highestPriorityIndex = rightChild;
    }

    if (highestPriorityIndex != index) {

        swap(patients[index], patients[highestPriorityIndex]);

        heapify(patients, highestPriorityIndex);
    }
}

// Build Heap
void BUILD_Heap(vector<Patient>& patients) {

    int size = patients.size();

    for (int i = (size / 2) - 1; i >= 0; i--) {

        heapify(patients, i);
    }
}

// View Next Patient
Patient HEAP_MAXIMUM(vector<Patient>& patients) {

    if (patients.empty()) {

        cout << "Heap is Empty\n";

        return Patient{-1, "", -1, -1};
    }

    return patients[0];
}

// Treat Next Patient
Patient HEAP_EXTRACT_MAX(vector<Patient>& patients) {

    int size = patients.size();

    if (size == 0) {

        cout << "Heap is Empty\n";

        return Patient{-1, "", -1, -1};
    }

    Patient maxPatient = patients[0];

    patients[0] = patients[size - 1];

    patients.pop_back();

    if (!patients.empty()) {
        heapify(patients, 0);
    }

    return maxPatient;
}

// Heapify Up
void heap_increase_key(vector<Patient>& patients, int index) {

    while (index > 0 &&
           isHigherPriority(patients[index],
                            patients[parent(index)])) {

        swap(patients[index], patients[parent(index)]);

        index = parent(index);
    }
}

// Insert Patient
void insert_patient(vector<Patient>& patients, Patient patient) {

    patients.push_back(patient);

    int index = patients.size() - 1;

    heap_increase_key(patients, index);
}

// Update Severity
void updateSeverity(vector<Patient>& patients,
                    int id,
                    int newSeverity) {

    for (int i = 0; i < patients.size(); i++) {

        if (patients[i].id == id) {

            int oldSeverity = patients[i].severity;

            patients[i].severity = newSeverity;

            // If severity increased -> move up
            if (newSeverity > oldSeverity) {

                while (i > 0 &&
                       isHigherPriority(patients[i],
                                        patients[parent(i)])) {

                    swap(patients[i], patients[parent(i)]);

                    i = parent(i);
                }
            }

            // If severity decreased -> move down
            else {

                heapify(patients, i);
            }

            cout << "Severity Updated Successfully\n";

            return;
        }
    }

    cout << "Patient Not Found\n";
}

// Display All Patients
void displayPatients(vector<Patient>& patients) {

    if (patients.empty()) {

        cout << "No Patients Available\n";

        return;
    }

    cout << "\n----- All Patients (Level Order) -----\n";

    for (Patient p : patients) {

        cout << "ID: " << p.id
             << " | Name: " << p.name
             << " | Severity: " << p.severity
             << " | Arrival Time: " << p.arrivalTime
             << endl;
    }
}

int main() {

    vector<Patient> patients;

    // Insert 20+ patients

    insert_patient(patients, {1, "Ali", 5, 1});
    insert_patient(patients, {2, "Sara", 9, 2});
    insert_patient(patients, {3, "Omar", 7, 3});
    insert_patient(patients, {4, "Mona", 10, 4});
    insert_patient(patients, {5, "Ahmed", 6, 5});
    insert_patient(patients, {6, "Laila", 8, 6});
    insert_patient(patients, {7, "Youssef", 3, 7});
    insert_patient(patients, {8, "Nour", 9, 8});
    insert_patient(patients, {9, "Khaled", 2, 9});
    insert_patient(patients, {10, "Salma", 7, 10});
    insert_patient(patients, {11, "Hassan", 4, 11});
    insert_patient(patients, {12, "Mariam", 6, 12});
    insert_patient(patients, {13, "Tamer", 10, 13});
    insert_patient(patients, {14, "Rana", 5, 14});
    insert_patient(patients, {15, "Ziad", 8, 15});
    insert_patient(patients, {16, "Farah", 7, 16});
    insert_patient(patients, {17, "Karim", 1, 17});
    insert_patient(patients, {18, "Dina", 9, 18});
    insert_patient(patients, {19, "Amr", 4, 19});
    insert_patient(patients, {20, "Nada", 8, 20});
    insert_patient(patients, {21, "Mostafa", 6, 21});

    int choice;

    do {

        cout << "\n----- Emergency Room Priority System -----\n";

        cout << "1. Insert Patient\n";
        cout << "2. Treat Next Patient\n";
        cout << "3. View Next Patient\n";
        cout << "4. Update Severity\n";
        cout << "5. Display All Patients\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 1) {

            Patient p;

            cout << "Enter Patient ID: ";
            cin >> p.id;

            cout << "Enter Patient Name: ";
            cin >> p.name;

            cout << "Enter Severity Level (1-10): ";
            cin >> p.severity;

            cout << "Enter Arrival Time: ";
            cin >> p.arrivalTime;

            insert_patient(patients, p);

            cout << "Patient Added Successfully\n";
        }

        else if (choice == 2) {

            Patient treatedPatient = HEAP_EXTRACT_MAX(patients);

            if (treatedPatient.id != -1) {

                cout << "\n----- Treated Patient -----\n";

                cout << "ID: " << treatedPatient.id << endl;
                cout << "Name: " << treatedPatient.name << endl;
                cout << "Severity: " << treatedPatient.severity << endl;
                cout << "Arrival Time: "
                     << treatedPatient.arrivalTime << endl;
            }
        }

        else if (choice == 3) {

            Patient nextPatient = HEAP_MAXIMUM(patients);

            if (nextPatient.id != -1) {

                cout << "\n----- Next Patient -----\n";

                cout << "ID: " << nextPatient.id << endl;
                cout << "Name: " << nextPatient.name << endl;
                cout << "Severity: " << nextPatient.severity << endl;
                cout << "Arrival Time: "
                     << nextPatient.arrivalTime << endl;
            }
        }

        else if (choice == 4) {

            int id;
            int newSeverity;

            cout << "Enter Patient ID: ";
            cin >> id;

            cout << "Enter New Severity: ";
            cin >> newSeverity;

            updateSeverity(patients, id, newSeverity);
        }

        else if (choice == 5) {

            displayPatients(patients);
        }

        else if (choice == 0) {

            cout << "Program Ended\n";
        }

        else {

            cout << "Invalid Choice\n";
        }

    } while (choice != 0);

    return 0;
}