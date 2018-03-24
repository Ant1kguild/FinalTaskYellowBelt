//
// Created by ant1k on 16.3.18.
//

#include <utility>
#include "date.h"


DateConversion::DateConversion(std::string encryptedDate) : date(std::move(encryptedDate)) {
    std::stringstream ss(date);
    theFirstCharacter(ss);
    ensureNextSymbolAndSkip(ss);
    checkMonth(ss);
    ensureNextSymbolAndSkip(ss);
    checkDay(ss);
    theLastCharacter(ss);

}

void DateConversion::theFirstCharacter(std::stringstream &ss) {
    int _year = ss.peek();
    if (std::isdigit(ss.peek()) == 0 || ss.eof() || _year < 0) {
        errors.push_back(errorNumber::dateError);
    }
    int year;
    ss >> year;
    changeYear(year);
}

void DateConversion::ensureNextSymbolAndSkip(std::stringstream &ss) {
    if (ss.peek() != '-') {
        errors.push_back(errorNumber::dateError);
    }
    ss.ignore(1);
}

void DateConversion::checkMonth(std::stringstream &ss) {
    int month;
    ss >> month;
    if (month < 1 && month > 12) {
        errors.push_back(errorNumber::monthError);
    } else {
        changeMonth(month);
    }

}

void DateConversion::checkDay(std::stringstream &ss) {
    int day;
    ss >> day;
    if (day < 1 && day > 31) {
        errors.push_back(errorNumber::dayError);
    } else {
        changeDay(day);
    }
}

void DateConversion::theLastCharacter(std::stringstream &ss) {
    if (ss.peek() == ' ' || !ss.eof()) errors.push_back(errorNumber::dateError);
}

DateConversion::~DateConversion() {
    if (!errors.empty()) {
        std::ostringstream error;
        switch (errors.at(0)) {
            case (errorNumber::dateError):
                error << "Wrong date format: " + date;
                throw std::runtime_error(error.str());
            case (errorNumber::monthError):
                error << "Month value is invalid: " + std::to_string(getMonth());
                throw std::runtime_error(error.str());
            case (errorNumber::dayError):
                error << "Day value is invalid: " + std::to_string(getDay());
                throw std::runtime_error(error.str());
        }
    }
}
