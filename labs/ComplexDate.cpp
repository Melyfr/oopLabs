#include "Complex.h"

ComplexDate::~ComplexDate() {
}

char* ComplexDate::getDate() {
    char* dateString = new char[sizeof(1900 + date->tm_year) + sizeof(1 + date->tm_mon) + sizeof(date->tm_mday)+34];
    sprintf(dateString, "Дата создания объекта: %d/%d/%d\n", 1900 + date->tm_year, 1 + date->tm_mon, date->tm_mday);
    return dateString;
}

int ComplexDate::getYear() {
    return (1900 + date->tm_year);
}

int ComplexDate::getMonth() {
    return (1 + date->tm_mon);
}

int ComplexDate::getDay() {
    return (date->tm_mday);
}