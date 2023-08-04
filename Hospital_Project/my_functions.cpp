#include "functions.h"

Patients_Info Patient_list;

void get_patient_info()
{
	Patient Patient;

	if (Patient_list.number_of_patients() > 100)
	{
		cout << string(105, '-') << endl;
		cout << "Can't take anymore Patients info\n";
		cout << string(105, '-') << endl;
		menu_options();
	}
	else
	{
		cout << string(105, '-') << endl;
		cout << "First Name: ";
		cin >> Patient.First_Name;
		cout << "Last Name: ";
		cin >> Patient.Last_Name;
		cout << "Gender (male\"m\"/female\"f\"): ";
		cin >> Patient.Gender;
		cout << "Patient's Mobile: ";
		cin >> Patient.Mobile;
		cout << "Total No of Medicine taken: ";
		cin >> Patient.Md_tk;
		cout << "Patient's Payment: ";
		cin >> Patient.Payment;
		if (Patient.Md_tk > 5)
		{
			Patient.Payment = Payment_Bouns(Patient.Payment);
		}
	}
	Patient_list.insert(Patient);
	cout << string(105, '-') << endl;
	menu_options();
}

void print_patients(Patient *head)
{
	char choice;
	if (head == nullptr)
	{
		cout << "No patients were added" << endl;
		while (true)
		{
			cout << "Would you like to add new patients? (y/n): ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				get_patient_info();
				break;
			}
			else if (choice == 'n' || choice == 'N')
			{
				cout << string(105, '-') << endl;
				cout << "Thanks for using my program :)" << endl;
				cout << string(105, '-') << endl;
				exit(0);
			}
			else
			{
				cout << "Please choose between 'y' and 'n'" << endl;
			}
		}
	}
	else
	{
		cout << left << setw(20) << "First Name" << setw(15) << "Last Name" << setw(10) << "Gender"
			 << setw(15) << "Mobile" << setw(25) << "Total No of Medicine taken" << setw(20) << "Total Payment" << endl;
		cout << string(105, '-') << endl;
		Patient *current = head;
		while (current != nullptr)
		{
			cout << left << setw(20) << current->First_Name << setw(15) << current->Last_Name
				 << setw(10) << current->Gender << setw(15) << current->Mobile
				 << setw(25) << current->Md_tk << setw(20) << fixed << setprecision(2) << current->Payment << endl
				 << endl;
			current = current->next;
		}
		cout << string(105, '-') << endl;
		menu_options();
	}
}

float Payment_Bouns(float payment)
{
	payment += 0.15 * payment;
	return payment;
}

void menu_options()
{
	int choice;

	while (true)
	{
		cout << "Options:" << endl
			 << "1.Add new Patient's info" << endl
			 << "2.Print all patients data" << endl
			 << "3.End program" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			get_patient_info();
			break;
		case 2:
			print_patients(Patient_list.head);
			break;
		case 3:
			cout << string(105, '-') << endl;
			cout << "Thanks for using my program :)" << endl;
			cout << string(105, '-') << endl;
			exit(0);
			break;
		default:
			cout << string(105, '-') << endl;
			cout << "Please choose from the following options." << endl;
			cout << string(105, '-') << endl;
			continue;
		}
	}
}