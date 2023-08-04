#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Patient
{
    string Name;
    string Gender;
    long int Mobile;
    int Md_tk;
    float Payment;
    Patient *next;
};

class Patients_Info
{
public:
    Patient *head;
    int count = 0;
    Patients_Info() : head(nullptr), count(0) {}

    ~Patients_Info()
    {
        Patient *current = head;
        while (current != nullptr)
        {
            Patient *next = current->next;
            delete current;
            current = next;
        }
    }

    Patient *insert(const Patient &data)
    {
        Patient *newNode = new Patient{data.Name, data.Gender, data.Mobile, data.Md_tk, data.Payment, nullptr};
        if (head == nullptr)
            head = newNode;
        else
        {
            Patient *current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = newNode;
        }
        return head;
    }

    int number_of_patients()
    {
        return count;
    }
};

Patient *get_patient_info();
void print_patients(Patient *head);
#endif
