#include <iostream>

using namespace std;

class calculator
{

public:
    int x;
    int y;
    char op;
    void calc(int a, int b, char sign)
    {
        if (sign == '+')
            cout << a + b << endl;
        else if (sign == '/' && b != 0)
            cout << a / b << endl;
    }
};


class Shapes{
protected:
    virtual void Area() = 0; 
    virtual void Perimeter() = 0;
};


class Rectangles : protected Shapes
{
private:
    float length;
    float width;

public:
    Rectangles(float length, float width){
        this->length = length;
        this->width = width;
    }
    void Area()
    {
        float area = this->length * this->width;
        cout << "Area of Rectangle = " << area << endl;
    }
    void Perimeter()
    {
        float perimeter = 2 * (this->length + this->width);
        cout << "Perimeter of Rectangle = " << perimeter <<endl;
    }
};

class Triangles : protected Shapes
{
private:
    float base;
    float height;
    float side_a;
    float side_b;
    float side_c;
    

public:
    Triangles(float base, float height)
    {
        this->base = base;
        this->height= height;
    }

    Triangles(float side_a, float side_b, float side_c)
    {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c; 
    }  

    void Area()
    {
        float area = (1/2) * this->base * this->height;
        cout << "Area of Triangle = " << area << endl;
    }
    void Perimeter()
    {
        float perimeter = this->side_a + this->side_b + this->side_c;
    }
};

class Circles : protected Shapes
{
private:
    float Radius;
    const double PI = 3.14159265359;
public: 
    Circles(float Radius)
    {
        this->Radius = Radius;
    }
    void Area()
    {
        float area = PI * this->Radius * this->Radius;
        cout << "Area of Circle = " << area << endl;
    }
    void Perimeter()
    {
        float circumference = 2 * PI * Radius;
        cout << "Circumference of Circle = " << circumference << endl; 
    }
};

class Squares : protected Shapes
{
private:
    float L;
public:
    Squares(float L)
    {
        this->L = L;
    }
    
    void Area()
    {
        float area = L * L;
        cout << "Area of Square = " << area << endl;
    }
    void Perimeter()
    {
        float perimeter = 4 * L;
        cout << "Perimeter of Square = " << perimeter << endl;
    }

};

int main()
{       
    return 0;
}