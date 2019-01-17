
#include <iostream>

int main(int argc, char* args[]) {

    // An average Green Fox attendee codes 6 hours daily
    int dayWorkHours = 6;

    // The semester is 17 weeks long
    int semesterWeeks = 17;

    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    std::cout << dayWorkHours * 5 * semesterWeeks << std::endl;


    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52
    float averWeekWorkHours = 52.;
    float part = (dayWorkHours * 5 * semesterWeeks) / (averWeekWorkHours * semesterWeeks);
    std::cout << part*100 << "%" << std::endl;



    return 0;
}