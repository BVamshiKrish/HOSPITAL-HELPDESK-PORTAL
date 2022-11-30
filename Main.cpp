#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
using namespace std;

class patient{
    public:
    string Name;
    string email_id;
    string PhoneNumber;
    string Designation;
    string Department;
    string Roll_no;
    string Ethics_rating;
    string Address;
    patient* next;

    patient(string Name,string email_id,string PhoneNumber,string Department,string Roll_no,string Ethics_rating,string Address,string Designation) {
        this->Name = Name;
        this->Department = Department;
        this->PhoneNumber = PhoneNumber;
        this->email_id = email_id;
        this->Roll_no = Roll_no;
        this->Ethics_rating = Ethics_rating;
        this->Address = Address;
        this->Designation = Designation;
        next = NULL;
    }
};

bool Namesearch(patient* &first, string Name) {
    patient* temp = first;                  
    while(temp!=NULL) {
        if(temp->Name == Name) {
            return true;
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL) {
        return false;
    }
}

patient* Ns(patient* &first, string Name) {
    patient* temp = first;                  
    while(temp!=NULL) {
        if(temp->Name == Name) {
            return temp;
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL) {
        return NULL;
    }
}

void InsertPatient(patient* &first, string Name,string Designation ,string Department ,string email_id,string Roll_no,string PhoneNumber,string Ethics_rating,string Address) {
    patient* new_pat = new patient(Name,Designation,Department,email_id,Roll_no,PhoneNumber,Ethics_rating,Address);
    patient* temp = first;
    if(Namesearch(first, Name)==true) {
        return;
    }

    if(first==NULL) {
        first = new_pat;
    }
    else {
        while(temp!=NULL && temp->next != NULL && temp->next->Name.compare(Name)<0) {
            temp = temp->next;
        }
        if(temp == first) {
            if(temp->Name.compare(Name)>0) {
            new_pat->next = first;
            first = new_pat;
            }
            else {
                new_pat->next = first->next;
                first->next = new_pat;
            }
        }
        else if(temp->next == NULL) {
            temp->next = new_pat;
        }
        else {
            new_pat->next = temp->next;
            temp->next = new_pat;
        }
    }
}

void DeletePat(patient* &patient1, string Name) {
    patient* temp = patient1;

     if(patient1->Name == Name) {
        patient* remove = patient1;
        patient1 = patient1->next;
        delete remove;
    }                                                  
    while(temp!=NULL) {
        if(temp->next->Name == Name) {
            patient* dead = temp->next;
            temp->next = temp->next->next;
            delete dead;
            break;
        }
        temp = temp->next;
    }
}

void SearchByname(patient* patient1, string Name) {
    patient* temp = patient1;
    if(patient1==NULL) {
        return;
    }
    while(temp!=NULL) {
        if(temp->Name == Name) {
            cout<<temp->Name<<"  "<<temp->Department<<"  "<<"  "<<temp->PhoneNumber<<"  "<<temp->email_id<<"  "<<temp->Roll_no<<"  "<<temp->Ethics_rating<<"  "<<temp->Address<<"  "<<temp->Designation<< endl;
            break;
        }
        temp = temp->next;
    }
}

void SearchByPhoneno(patient* patient1, string PhoneNumber) {
    patient* temp = patient1;
    if(patient1==NULL) {
        return;
    }
    while(temp!=NULL) {
        if(temp->PhoneNumber == PhoneNumber) {
            cout<<temp->Name<<"  "<<"  "<<temp->Department<<"  "<<temp->PhoneNumber<<"  "<<temp->email_id<<"  "<<temp->Roll_no<<"  "<<temp->Ethics_rating<<"  " <<temp->Address<<"  "<<temp->Designation <<endl;
            break;
        }
        temp = temp->next;
    }
}
void UpdatePat(patient* patient1, string Name, string email_id, string PhoneNumber,string Department,string Roll_no,string Ethics_rating,string Address,string Designation) {
    patient* Pat = Ns(patient1, Name);
    Pat->email_id = email_id;
    Pat->PhoneNumber = PhoneNumber;
    Pat->Department = Department;
    Pat->Designation = Designation;
    Pat->Roll_no = Roll_no;
    Pat->Ethics_rating = Ethics_rating;
    Pat->Address = Address;

}

void displayPats(patient* patient1) {
    if(patient1 == NULL) {
        return;
    }
    patient* temp = patient1;
    while(temp!=NULL) {
        cout<<temp->Name<<"  "<<temp->Department<<"  "<<"  "<<temp->PhoneNumber<<"  "<<temp->email_id<<"  "<<temp->Department<<"  "<<temp->Roll_no<<"  "<<temp->Ethics_rating<<"  "<<temp->Address<<"  "<<temp->Designation <<endl;
        temp = temp->next;
    }
}

class doctor{
    public:
    string Name;
    string email_id;
    string PhoneNumber;
    string TypeOfEmployment;
    string Department;
    string Feedback;
    string Patients;
    string Slot1;
    string Slot2;
    string Slot3;
    string Slot4;
    string Slot5;
    queue <patient*> q1;
    queue <patient*> q2;
    queue <patient*> q3;
    queue <patient*> q4;
    queue <patient*> q5;
    queue <patient*> q6;
    doctor* next;

    doctor(string Name,string email_id,string PhoneNumber,string TypeOfEmployment,string Department, string Feedback, string Patients, string Slot1, string Slot2, string Slot3, string Slot4, string Slot5) {
        this->Name = Name;
        this->Department = Department;
        this->TypeOfEmployment = TypeOfEmployment;
        this->PhoneNumber = PhoneNumber;
        this->email_id = email_id;
        this->Feedback = Feedback;
        this->Patients = Patients;
        this->Slot1 = Slot1;
        this->Slot2 = Slot2;
        this->Slot3 = Slot3;
        this->Slot4 = Slot4;
        this->Slot5 = Slot5;
        next = NULL;
    }
};
bool NameSearchDoc(doctor* &first, string Name) {
    doctor* temp = first;                  
    while(temp!=NULL) {
        if(temp->Name == Name) {
            return true;
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL) {
        return false;
    }
}
doctor* NSDoc(doctor* &first, string Name) {
    doctor* temp = first;                  
    while(temp!=NULL) {
        if(temp->Name == Name) {
            return temp;
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL) {
        return NULL;
    }
}
void InsertDoctor(doctor* &first, string Name,string email_id,string PhoneNumber,string TypeOfEmployment,string Department, string Feedback, string Patients, string Slot1, string Slot2, string Slot3, string Slot4, string Slot5) {
    doctor* new_doc = new doctor(Name,email_id, PhoneNumber,TypeOfEmployment,Department, Feedback, Patients, Slot1, Slot2, Slot3, Slot4, Slot5);
    doctor* temp = first;
    if(NameSearchDoc(first, Name)==true) {
        return;
    }

    if(first==NULL) {
        first = new_doc;
    }
    else {
        while(temp!=NULL && temp->next != NULL && temp->next->Name.compare(Name)<0) {
            temp = temp->next;
        }
        if(temp == first) {
            if(temp->Name.compare(Name)>0) {
            new_doc->next = first;
            first = new_doc;
            }
            else {
                new_doc->next = first->next;
                first->next = new_doc;
            }
        }
        else if(temp->next == NULL) {
            temp->next = new_doc;
        }
        else {
            new_doc->next = temp->next;
            temp->next = new_doc;
        }
    }
}
void DeleteDoc(doctor* &doctor1, string Name) {
    doctor* temp = doctor1;

     if(doctor1->Name == Name) {
        doctor* remove = doctor1;
        doctor1 = doctor1->next;
        delete remove;
    }                                                  
    while(temp!=NULL) {
        if(temp->next->Name == Name) {
            doctor* dead = temp->next;
            temp->next = temp->next->next;
            delete dead;
            break;
        }
        temp = temp->next;
    }
}
void SearchByDeptDoc(doctor* doctor1, string Department){
    doctor* temp = doctor1;
    if(doctor1 == NULL) {
       return;
    }
    while(temp!=NULL) {
       if(temp->Department == Department)
       cout<<temp->Name<<"  "<<temp->PhoneNumber<<"  " << temp->Feedback<<"  "<<temp->Patients<< endl;
       temp = temp->next;
    }      
}
void SearchByNameDoc(doctor* doctor1, string Name) {
    doctor* temp = doctor1;
    if(doctor1==NULL) {
        return;
    }
    while(temp!=NULL) {
        if(temp->Name == Name) {
            cout<<temp->Name<<"  "<<temp->Department<<"  "<<temp->TypeOfEmployment<<"  "<<temp->PhoneNumber<<"  "<<temp->email_id<<"  "<<temp->Feedback<<"  "<<temp->Patients<< endl;
            break;
        }
        temp = temp->next;
    }
}

void SearchByPhoneNoDoc(doctor* doctor1, string PhoneNumber) {
    doctor* temp = doctor1;
    if(doctor1==NULL) {
        return;
    }
    while(temp!=NULL) {
        if(temp->PhoneNumber == PhoneNumber) {
            cout<<temp->Name<<"  "<<temp->Department<<"  "<<temp->TypeOfEmployment<<"  "<<temp->PhoneNumber<<"  "<<temp->email_id<<"  "<<temp->Feedback<<"  "<<temp->Patients<< endl;
            break;
        }
        temp = temp->next;
    }
}
void displayDocs(doctor* doctor1) {
    if(doctor1 == NULL) {
        return;
    }
    doctor* temp = doctor1;
    while(temp!=NULL) {
        cout<<temp->Name<<"  "<<temp->Department<<"  "<<temp->TypeOfEmployment<<"  "<<temp->PhoneNumber<<"  "<<temp->email_id<<"  "<<temp->Feedback<<"  "<<temp->Patients<< endl;
        temp = temp->next;
    }
}
bool link(doctor* doctor1, string DocName, string PatName, string Slot) {
    doctor* Doc = NSDoc(doctor1, DocName);
    queue<patient*> q; 
    if(Slot == "1")  q = Doc->q1;
    if(Slot == "2")  q = Doc->q2;
    if(Slot == "3")  q = Doc->q3;
    if(Slot == "4")  q = Doc->q4;
    if(Slot == "5")  q = Doc->q5;
    if(Slot == "6")  q = Doc->q6;
    while(!q.empty() and !(q.front()->Name==PatName)) {
        q.pop();
    }
    if(q.empty())  return false;
    else  return true;
}

void feedback(doctor* &doctor1,string DocName,int x){

    doctor* doc = NS(doctor1, DocName);

    string feedback,patients,emailid,phoneNumber,typeOfEmployment,department,slot1,slot2,slot3,slot4,slot5 ;
    doc->Feedback=feedback;
    doc->Patients=patients;
    doc->email_id = emailid;
    doc->PhoneNumber = phoneNumber;
    doc->TypeOfEmployment = typeOfEmployment;
    doc->Department = department;
    doc->Slot1 = slot1;
    doc->Slot2 = slot2;
    doc->Slot3 = slot3;
    doc->Slot4 = slot4;
    doc->Slot5 = slot5;
    
    int feedback1 = stoi(feedback);
    int patients1 = stoi(patients);
  
    feedback1=((feedback1*patients1)+x)/(patients1+1);
    patients1++;

    feedback = to_string(feedback1);
    patients = to_string(patients1);
    UpdateDoc(doctor1, DocName,emailid,phoneNumber,typeOfEmployment,department, feedback,patients,slot1,slot2,slot3,slot4,slot5);

    SearchByName(doctor1,DocName);
}

int main() {
    doctor* doctor1 = NULL;
    ifstream inputFile;
    inputFile.open("BM2043_PROJECT_DATA_1.csv");

    string line="";
    getline(inputFile, line);
    line="";
    while(getline(inputFile, line))
    {
       string Name;
       string Department;
       string TypeOfEmployment;
       string PhoneNumber;
       string Feedback;
       string email_id;
       string Patients;
       string Slot1;
       string Slot2;
       string Slot3;
       string Slot4;
       string Slot5;

       stringstream inputString(line);
       getline(inputString, Name, ',');
       getline(inputString, email_id, ',');
       getline(inputString, PhoneNumber, ',');
       getline(inputString, TypeOfEmployment, ',');
       getline(inputString, Department, ',');
       getline(inputString, Feedback, ',');
       getline(inputString, Patients, ',');
       getline(inputString, Slot1, ',');
       getline(inputString, Slot2, ',');
       getline(inputString, Slot3, ',');
       getline(inputString, Slot4, ',');
       getline(inputString, Slot5, ',');

       line="";

      if(!NameSearchDoc(doctor1,Name) && TypeOfEmployment =="DOCTOR" ) {
      InsertDoctor(doctor1,Name,email_id,PhoneNumber,TypeOfEmployment,Department,Feedback,Patients,Slot1,Slot2,Slot3,Slot4,Slot5);
      }
    }
}
