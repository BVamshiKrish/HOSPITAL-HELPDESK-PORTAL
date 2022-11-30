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

    ifstream inputFile1;
    inputFile1.open("BM2043_PATIENTS.csv");

    string line1 = "";
    getline(inputFile1,line) ;
    line = "";

    while ( getline(inputFile1,line))
    {
        string Name ;
        string designation;
        string department ;
        string email;
        string rollno;
        string phoneno;
        string Ethicsrating;
        string Address ;
        stringstream inputString(line);

        getline(inputString,Name, ',') ;
        getline(inputString,designation,',');
        getline(inputString,department,',') ;
        getline(inputString,email, ',');
        getline(inputString,rollno, ',');
        getline(inputString,phoneno,',');
        getline(inputString,Ethicsrating,',');
        getline(inputString,Address,',');

        line = "";
        InsertPatient(patient1,Name,designation,department,email,rollno,phoneno,Ethicsrating,Address);
    }
    
    Homepage:

    cout <<"Welcome to IIT HYDERABAD HOSPITAL HELPDESK PORTAL" << endl;
    cout << "1.Directory of Doctors "<< endl;
    cout << "2.Directory of Patients "<< endl;
    cout << "3.Appointment Management System "<< endl;
    cout << "4.Feedback Management Portal "<< endl;
    cout <<"Please select any option:"<< endl ;

    int x;
    cin>> x;    

    switch (x)
    {
    case 1:
    cout << "1.Add a new Doctor" << endl;
    cout << "2.Delete a Doctor " << endl;
    cout << "3.To view doctors list  " << endl;
    cout << "4.BACK "<<endl;
    cout << "Choose any one option:" << endl;

    int a;
    cin>>a ;

    if(a == 1){
     
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
        cout << "Enter New doctor name : " ;
        getline(cin >> ws ,Name) ;
        cout << endl;
        
        cout <<"Enter name of Department :" ;
        cin >> Department;
        cout << endl;

        cout <<"Enter type of employment :" ;
        cin >> TypeOfEmployment;
        cout << endl;

        cout <<"Enter Phone number :" ;
        cin >> PhoneNumber;
        cout << endl;

        cout <<" Enter feedback :" ;
        cin >> Feedback;
        cout << endl;  

        cout << "Enter email ID :" ;
        cin>> email_id ;
        cout << endl;

        cout <<" Enter number of patients:" ;
        cin >> Patients ;
        cout << endl;

        cout<<" Enter time slot keys"<<endl;
        cout<<"enter 1 for 9AM-10AM"<<endl;
        cout<<"enter 2 for 10AM-11AM"<<endl;
        cout<<"enter 3 for 11AM-12PM"<<endl;
        cout<<"enter 4 for 2PM-3PM"<<endl;
        cout<<"enter 5 for 3PM-4PM"<<endl;
        cout<<"enter 6 for 4PM-5PM"<<endl;

        cout << " Enter Slot 1:"<<endl;
        cin >> Slot1;

        cout << " Enter Slot 2:"<<endl;
        cin >> Slot2;

        cout << " Enter Slot 3:"<<endl;
        cin >> Slot3;

        cout << " Enter Slot 4:"<<endl;
        cin >> Slot4;

        cout << " Enter Slot 5:"<<endl;
        cin >> Slot5;

    InsertDoctor(doctor1,Name,email_id,PhoneNumber,TypeOfEmployment,Department,Feedback,Patients,Slot1,Slot2,Slot3,Slot4,Slot5);
    goto Homepage;
    break; 
    } 

    else if (a == 2){
       
       string Name;
        
        cout << "Enter doctor name to delete: " ;
        getline(cin >> ws ,Name) ;
        cout << endl;
        
        DeleteDoc(doctor1,Name);
        break;
    }

    else if(a==3){

       string Name;
       string Department;
       string TypeOfEmployment;
       string PhoneNumber;
       string Feedback;
       string email_id;
       string Patients;

        cout <<" Enter the name of the doctor to view the list:" << endl;
        getline(cin >> ws,Name);
        SearchByNameDoc(doctor1,Name) ;
        goto Homepage ;
        break;

        cout << "Enter phone view Doctor:" << endl;
        cin>>PhoneNumber ;
        SearchByPhoneNoDoc(doctor1,PhoneNumber);
        goto Homepage;
        break;
    }
     
    break;
    
    case 2:
    cout << "Enter pateint name to view details :" << endl;
    // getline(cin>> ws,abc);
    break;

    case 3:
    goto Appointment ;
    break;
     
    case 4:
    cout << "Enter patient name :"<< endl;
    cout << "Enter doctor name:" << endl;

    goto Homepage;
    break;

    default:
    goto Homepage;
    break;

    }    
    
  Appointment:

   string PatName;
   cout<<"Enter your name"<<endl;
   cin>>PatName;
   if(Namesearch(patient1, PatName)) {
    patient* PAT = Ns(patient1, PatName);
   }
   else {
    cout <<"Enter your details " << endl;
    string email_id1;
    string PhoneNumber1;
    string Designation1;
    string Department1;
    string Roll_no1;
    string Ethics_rating1 = "";
    string Address1 = "";
    
    cout << "Enter email: " ;
    cin >> email_id1;

    cout <<"Phone no :";
    cin >> PhoneNumber1;

    cout <<"Designation:" ;
    cin >> Designation1;

    cout << "department :" ;
    cin >> Department1 ;

    cout <<"Roll number :" ;
    cin >> Roll_no1;
    
    InsertPatient(patient1,PatName,Designation1,Department1,email_id1,Roll_no1,PhoneNumber1,Ethics_rating1,Address1) ;
    patient* PAT = Ns(patient1, PatName);
    goto  specialist;
   }

  specialist:
    
    cout <<"Enter the type of specalist:"<<endl ;
    cout << "1.GENERAL MEDICINE"<<endl;
    cout << "2.NEUROLOGY"<< endl;
    cout << "3.ORTHOPEDICS"<< endl;
    cout << "4.CARDIOLOGY"<< endl;
    cout << "5.GYNECOLOGY"<< endl;
    cout << "6.PULMONOLOGY"<< endl;
    cout << "7.PEDIATRICS"<< endl;


    int a;
    cin>> a;

   cout<<"All the available specialists:"<< endl;
   
   switch (a){
    case 1: SearchByDeptDoc(doctor1,"GENERAL MEDICINE") ;  
    break;
    
    case 2: SearchByDeptDoc(doctor1,"NEUROLOGY") ;  
    break;
        
    case 3: SearchByDeptDoc(doctor1,"ORTHOPEDICS") ;  
    break;
       
    case 4: SearchByDeptDoc(doctor1,"CARDIOLOGY") ;  
    break;
        
    case 5: SearchByDeptDoc(doctor1,"GYNECOLOGY") ;  
    break;
        
    case 6: SearchByDeptDoc(doctor1,"PULMONOLOGY") ;  
    break;
        
    case 7: SearchByDeptDoc(doctor1,"PEDIATRICS") ;  
    break;
   
   default: 
    cout <<"Select a number in range"<< endl;
    goto specialist; 
    break;
   }

   SLOTS:

   string selectdoc;
   cout <<"Enter doctor name:"<<endl ;
   getline(cin >> ws,selectdoc);

    if(NameSearchDoc(doctor1,selectdoc)){
        doctor* Doc = NSDoc(doctor1, selectdoc);
    
    cout << "Available time slots for : "<< selectdoc << endl ;
    if((Doc->Slot1=="1" or Doc->Slot2=="1" or Doc->Slot3=="1" or Doc->Slot4=="1" or Doc->Slot5=="1") and Doc->q1.size()<5)   cout<<"1. 9AM-10AM"<<endl;
    if((Doc->Slot1=="2" or Doc->Slot2=="2" or Doc->Slot3=="2" or Doc->Slot4=="2" or Doc->Slot5=="2") and Doc->q2.size()<5)   cout<<"2. 10AM-11AM"<<endl;
    if((Doc->Slot1=="3" or Doc->Slot2=="3" or Doc->Slot3=="3" or Doc->Slot4=="3" or Doc->Slot5=="3") and Doc->q3.size()<5)   cout<<"3. 11AM-12AM"<<endl;
    if((Doc->Slot1=="4" or Doc->Slot2=="4" or Doc->Slot3=="4" or Doc->Slot4=="4" or Doc->Slot5=="4") and Doc->q4.size()<5)   cout<<"4. 2PM-3PM"<<endl;
    if((Doc->Slot1=="5" or Doc->Slot2=="5" or Doc->Slot3=="5" or Doc->Slot4=="5" or Doc->Slot5=="5") and Doc->q5.size()<5)   cout<<"5. 3PM-4PM"<<endl;
    if((Doc->Slot1=="6" or Doc->Slot2=="6" or Doc->Slot3=="6" or Doc->Slot4=="6" or Doc->Slot5=="6") and Doc->q6.size()<5)   cout<<"6. 4PM-5PM"<<endl;
    
    cout<<"7. BACK"<<endl;

    }

    else {
    cout <<"Enter correct name:"<<endl;
    goto SLOTS;
    }

   int b; 
   cout << "Choose a time slot:" << endl;
   cin>>b;
   string slot = to_string(b);
   doctor* Doc = NSDoc(doctor1, selectdoc);
   patient* PAT = Ns(patient1, PatName);
   switch (b) {

   case 1 :
    if(Doc->q1.size()==5) {
            cout<<"Slot is fully booked"<<endl;
      }
    else {
            Doc->q1.push(PAT);
    }
     cout << "your appointment is booked" << endl;
    break;

   case 2 :
    if(Doc->q2.size()==5) {
            cout<<"Slot is fully booked"<<endl;
    
     }
    else {
            Doc->q2.push(PAT);
    }
     cout << "your appointment is booked" << endl;
    
    break;
    case 3 :
          if(Doc->q3.size()==5) {
            cout<<"Slot is fully booked"<<endl;
         }
         else {
            Doc->q3.push(PAT);
         }
         goto SLOTS;
    break;
    case 4 :
          if(Doc->q4.size()==5) {
            cout<<"Slot is fully booked"<<endl;
         }
         else {
            Doc->q4.push(PAT);
         }
    break;
    case 5 :
          if(Doc->q5.size()==5) {
            cout<<"Slot is fully booked"<<endl;
         }
         else {
            Doc->q5.push(PAT);
         }
    break;
    case 6 :
          if(Doc->q6.size()==5) {
            cout<<"Slot is fully booked"<<endl;
         }
         else {
            Doc->q6.push(PAT);
         }
    break;
    
    default: "Choose out of given slots";
    goto SLOTS;
    break;

   }

   cout<<"Your appointment is booked";
   cout <<"APPOINTMENT DETAILS:" << endl;
   cout <<"Patient Name :" << PatName << endl;
   cout <<"Doctor Name :" << selectdoc << endl;
   
   goto Homepage ;
   

 return 0;

}
