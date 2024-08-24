
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Student {
public:
    std::string name;
    int roll_number;
    float marks;

    void input() {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter roll number: ";
        std::cin >> roll_number;
        std::cout << "Enter marks: ";
        std::cin >> marks;
    }

    void display() const {
        std::cout << "Name: " << name << ", Roll Number: " << roll_number << ", Marks: " << marks << std::endl;
    }
};

void writeToFile(const std::vector<Student>& students) {
    std::ofstream outFile("students.txt");
    for (const auto& student : students) {
        outFile << student.name << " " << student.roll_number << " " << student.marks << std::endl;
    }
    outFile.close();
}

void readFromFile() {
    std::ifstream inFile("students.txt");
    std::string name;
    int roll_number;
    float marks;
    while (inFile >> name >> roll_number >> marks) {
        std::cout << "Name: " << name << ", Roll Number: " << roll_number << ", Marks: " << marks << std::endl;
    }
    inFile.close();
}

void modifyMarks(int roll_number, float new_marks) {
    std::fstream file("students.txt", std::ios::in | std::ios::out);
    std::string name;
    int r_num;
    float marks;
    std::streampos pos;

    while (file >> name >> r_num >> marks) {
        if (r_num == roll_number) {
            pos = file.tellg(); 
            file.seekp(pos - std::streamoff(sizeof(float))); 
            file << new_marks << std::endl;
            break;
        }
    }
    file.close();
}

int main() {
    std::vector<Student> students(5);
    for (auto& student : students) {
        student.input();
    }

    writeToFile(students);

    std::cout << "\nData read from file:\n";
    readFromFile();

    modifyMarks(1, 95.0); 

    std::cout << "\nData after modification:\n";
    readFromFile();

    return 0;
}




#include <iostream>
#include <string>
	
class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& c) : color(c) {}

    void setColor(const std::string& c) {
        color = c;
    }

    std::string getColor() const {
        return color;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double breadth;

public:
    Rectangle(const std::string& c, double l, double b) : Shape(c), length(l), breadth(b) {}

    double area() const {
        return length * breadth;
    }

    double perimeter() const {
        return 2 * (length + breadth);
    }
};

int main() {	
    Rectangle rect("Red", 5.0, 3.0);
    std::cout << "Color: " << rect.getColor() << std::endl;
    std::cout << "Area: " << rect.area() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;
    return 0;
}


#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
public:
    Animal(std::string n) : name(n) {}
    void display() {
        std::cout << "Animal Name: " << name << std::endl;
    }
};

class Mammal : public Animal {
protected:
    int numberOfLegs;
public:
    Mammal(std::string n, int legs) : Animal(n), numberOfLegs(legs) {}
    void display() {
        Animal::display();
        std::cout << "Number of Legs: " << numberOfLegs << std::endl;
    }
};

class Dog : public Mammal {
public:
    Dog(std::string n, int legs) : Mammal(n, legs) {}
    void bark() {
        std::cout << name << " says: Woof!" << std::endl;
    }
};

int main() {
    Dog myDog("Buddy", 4);
    myDog.display();
    myDog.bark();
    return 0;
}



#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    std::string address;

    Person(std::string n, std::string a) : name(n), address(a) {}
};

class Employee {
public:
    int employeeID;
    double salary;

    Employee(int id, double sal) : employeeID(id), salary(sal) {}
};

class Teacher : public Person, public Employee {
public:
    std::string subject;

    Teacher(std::string n, std::string a, int id, double sal, std::string sub)
        : Person(n, a), Employee(id, sal), subject(sub) {}
};

int main() {
    Teacher teacher("HASSAN", " St 1A", 101, 50000.0, "Mathematics");
    std::cout << "Name: " << teacher.name << "\n"
        << "Address: " << teacher.address << "\n"
        << "Employee ID: " << teacher.employeeID << "\n"
        << "Salary: " << teacher.salary << "\n"
        << "Subject: " << teacher.subject << std::endl;
    return 0;
}
