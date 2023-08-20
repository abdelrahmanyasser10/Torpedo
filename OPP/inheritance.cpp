#include <iostream>

using namespace std;

class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
{
private:
    string Name;
    string Company;
    int Age;

public:
    void setName(string name) {}
    string getName() { return nullptr; }
    void setCompany(string company) {}
    string getComapny() { return nullptr; }
    void setAge(int age) {}
    int getAge() { return 0; }
    void IntroduceYourself() {}
    Employee(string Name, string Company, int Age) {}
    void AskForPromotion()
    {
        if (Age >= 21)
            cout << Name << " got promoted!!" << endl;
        else
            cout << Name << ", No promotion for you" << endl;
    }
};

int main()
{
    Employee employee1("Abdelrahman", "Torpedo", 21);
    Employee employee2("Menna", "Microsoft", 20);

    employee1.AskForPromotion();
    employee2.AskForPromotion();
}