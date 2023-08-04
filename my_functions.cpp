#include "functions.h"

Patients_Info Patient_list;

Patient *get_patient_info()
{
	Patient *ptr;
	Patient Patient;

	if (Patient_list.number_of_patients() > 100)
	{
		cout << "Can't take anymore Patients info\n";
		return 0;
	}
	else
	{
		cout << "Name: ";
		getline(cin, Patient.Name);
		cout << "Gender (male\"m\"/female\"f\"): ";
		cin >> Patient.Gender;
		cout << "Patient's Mobile:";
		cin >> Patient.Mobile;
		cout << "Total No of Medicine taken: ";
		cin >> Patient.Md_tk;
		cout << "Patient's Payment: ";
		cin >> Patient.Payment;
		if (Patient.Md_tk > 5)
		{
			Patient.Payment += 0.15 * Patient.Payment;
		}
	}
	ptr = Patient_list.insert(Patient);
	return ptr;
}

void print_patients(Patient *head = Patient_list.head)
{
	Patient *current = head;
	while (current != nullptr)
	{
		cout << current->Name << "\t" << current->Gender << "\t" << current->Mobile << "\t" << current->Md_tk << "\t" << current->Payment << endl;
		current = current->next;
	}
}