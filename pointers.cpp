// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>


typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    student.f_name = new char[128];
    
    student.l_name = new char[128];
    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);

    std::cout << "Please enter the student's first name: ";
    std::cin.getline(student.f_name, 128);
    
    std::cout << "Please enter the student's last name: ";
    std::cin.getline(student.l_name, 128);
    
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, sizeof(int));

    student.grades = new double[student.n_assignments];
    for(int i = 0; i < student.n_assignments; i++){
        std::string prompt = "Please enter grade for assignment: ";
        prompt += i;
        prompt += ": ";
        student.grades[i] = promptDouble(prompt, 0, 1000);
    }
    

    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student, &average);
    // Output `average`
    std::cout<< average;
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int input;
    std::cout << message;
    std::cin >> input;
    while(!std::cin || (input < min || input > max)){
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Sorry I couldn't understand that please try again";
        std::cin >> input;
    }
    std::cin.ignore();
    return input;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    double input;
    std::cout << message;
    std::cin >> input;
    while(!std::cin || (input < min || input > max)){
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Sorry I couldn't understand that please try again";
        std::cin >> input;
    }
    return input;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    Student student = *(Student*) object;
    double total = 0;
    for(int i = 0; i < student.n_assignments; i++){
        total += student.grades[i];
    }
    *avg = total/student.n_assignments;  
    return;
}
