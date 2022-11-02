#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class doctors{
    public:
    string Name;
    string Department;
    string TypeOfEmployment;
    long int PhoneNumber;
    string email_id;
    doctors* next;
};
void NewDoctor(doctors* new_doctor) {
    new_doctor=new doctors;
    cout<<"Name: ";
    cin>>new_doctor->Name;
    cout<<"Department: ";
    cin>>new_doctor->Department;
    cout<<"TypeOfEmployment: ";
    cin>>new_doctor->TypeOfEmployment;
    cout<<"Phone Number: ";
    cin>>new_doctor->PhoneNumber;
    cout<<"email_id: ";
    cin>>new_doctor->email_id;
    new_doctor->next = NULL;
}


class patients{
    public:
    string Name;
    string department;
    string TypeOfEmployment;
    long int PhoneNumber;
    string email_id;
    string address;
    patients* next;
};
void NewPatient(patients* new_patient) {
    new_patient = new patients;
    cout<<"Name: ";
    cin>>new_patient->Name;
    cout<<"Department: ";
    cin>>new_patient->department;
    cout<<"TypeOfEmployment: ";
    cin>>new_patient->TypeOfEmployment;
    cout<<"Phone Number: ";
    cin>>new_patient->PhoneNumber;
    cout<<"email_id: ";
    cin>>new_patient->email_id;
    cout<<"Address: ";
    cin>>new_patient->address;
    new_patient->next = NULL;
}
void InsertPatient(patients* &patient1, patients* str) {
    if(patient1 == NULL) {
        patient1 = str;
        return;
    }
    patients* temp = patient1;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = str;
}
int main() {
    doctors* doctor1 = NULL;
    doctors* str;
    NewDoctor(str);
    patients* patient1 = NULL;
    patients* str2;
    NewPatient(str2);
    fstream MyFile;
    MyFile.open("Doctors.txt", ios::out); //write 
    if(MyFile.is_open()) {
         MyFile << "Name: "<<str->Name<<"\n";
         MyFile << "Department: "<<str->Department<<"\n";
         MyFile << "Type Of Employment: "<<str->TypeOfEmployment<<"\n";
         MyFile.close();
     }
     MyFile.open("Patients.txt", ios::out);
     if(MyFile.is_open()) {
           MyFile << "Name: "<<str2->Name<<"\n";
         MyFile << "Department: "<<str2->department<<"\n";
         MyFile << "Type Of Employment: "<<str2->TypeOfEmployment<<"\n";
     }
}