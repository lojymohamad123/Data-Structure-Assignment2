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

bool isPerioritiest(Patient firstPatient, Patient secondPatient) {
    if (firstPatient.severity > secondPatient.severity) return true;
    if (firstPatient.severity == secondPatient.severity && firstPatient.arrivalTime < secondPatient.arrivalTime) return true;
    return false;
}

int parent(int index){
    return (index-1)/2;
}

void heapify(vector<Patient> &patients, int index) {
    int size = patients.size();
    int perioritiestPatientIndex = index;
    int leftChild = (2 * index) + 1;
    int rightChild = (2 * index) + 2;
    // max heap for severity
    if (leftChild < size && isPerioritiest(patients[leftChild], patients[perioritiestPatientIndex])) {
        perioritiestPatientIndex = leftChild;
    }
    if (rightChild < size && isPerioritiest(patients[rightChild], patients[perioritiestPatientIndex])) {
        perioritiestPatientIndex = rightChild;
    }
    // if the most perioritiest patient is not the current node
    if (perioritiestPatientIndex != index) {
        swap(patients[index], patients[perioritiestPatientIndex]);
        heapify(patients, perioritiestPatientIndex);
    }
}

void BUILD_Heap(vector<Patient> &patients){
    int size = patients.size();
    for(int i = (size/2)-1; i>=0; i--){
        heapify(patients, i);
    }
}

Patient HEAP_MAXIMUM(vector<Patient> &patients){
    if(patients.size() == 0){
        cout << "Empty Heap" << endl;
        return Patient{-1, "", -1, -1};
    }
    return patients[0];
}

Patient HEAP_EXTRACT_MAX(vector<Patient> &patients){
    int size = patients.size();
    if (size == 0){
        cout << "Empty Heap" << endl;
        return Patient{-1, "", -1, -1};
    }
    Patient max = patients[0];
    patients[0] = patients[size-1];
    patients.pop_back();
    heapify(patients, 0);
    return max;
}

void heap_increase_key(vector<Patient> &patients, int index, Patient key){
    patients[index] = key;
    while (index > 0 && isPerioritiest(patients[index], patients[parent(index)])) {
        swap(patients[index], patients[parent(index)]);
        index = parent(index);
    }
}

void insert_patient(vector<Patient> &patients, Patient patient){
    patients.push_back(patient);
    heap_increase_key(patients, patients.size()-1, patient);
}

int main() {
    
}