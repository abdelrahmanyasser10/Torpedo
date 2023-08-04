#include "functions.h"

using namespace std;

int main()
{
	Patient *ptr = get_patient_info();
	print_patients(ptr);
	return (0);
}
