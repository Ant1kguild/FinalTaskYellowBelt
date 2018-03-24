//
// Created by ant1k on 16.3.18.
//

#include "date.h"

Date ParseDate(std::istringstream &is) {
    std::string parseDate;
    is >> parseDate;
    try {
        DateConversion date(parseDate);
        return {date.getYear(), date.getMonth(), date.getDay()};
    } catch (std::runtime_error &ex) {
        std::cout << ex.what() << std::endl;
    }
}