// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <iomanip>
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
    
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);
    std::cout << std::endl;
    student.grades = new double[student.n_assignments];
    for(int i = 0; i < student.n_assignments; i++){
        std::string prompt = "Please enter grade for assignment " + std::to_string(i) + ": ";
        student.grades[i] = promptDouble(prompt, 0, 1000);
    }
    std::cout << std::endl;

    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student, &average);
    // Output `average`
    std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]\n";
    std::cout << std::setprecision(3);
    std::cout<<"  Average grade: " << average<<std::endl;
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
    char* input;
    input = new char[128];
    int number;

    bool valid = false;
    while(!valid){
        int i = 0;
        std::cout << message;
        std::cin.getline(input, 128);

        //make sure the input is valid
        while(input[i] != '\0'){
            if(input[i] < 48 || input[i] > 57){
                valid = false;
                break;
            }else{
                valid = true;
            }
            i++;
        }
        //make sure the number is actually in range
        if(valid){
            number = std::stoi(input);
            if(number > max || number < min){
                valid = false;
                std::cout << "Sorry, I cannot understand your answer"<<std::endl;
            }
        }else{
            std::cout << "Sorry, I cannot understand your answer"<<std::endl;
        }
    }
   
    return number;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{


    char* input;
    input = new char[128];
    double number;

    bool valid = false;
    while(!valid){
        int i = 0;
        std::cout << message;
        std::cin.getline(input, 128);

        //make sure the input is valid
        while(input[i] != '\0'){
            if(input[i] != 47 && (input[i] < 46 || input[i] > 57)){
                valid = false;
                break;
            }else{
                valid = true;
            }
            i++;
        }
        //make sure the number is actually in range
        if(valid){
            try{
                number = std::stod(input);
            }catch(const std::invalid_argument){
                valid = false;
                std::cout << "Sorry, I cannot understand your answer"<<std::endl;
                continue;
            }
            
            if(number > max || number < min){
                valid = false;
                std::cout << "Sorry, I cannot understand your answer"<<std::endl;
            }
        }else{
            std::cout << "Sorry, I cannot understand your answer"<<std::endl;
        }
    }
   
    return number;
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
