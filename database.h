//
// Created by ant1k on 16.3.18.
//

#pragma once

#include "date.h"
#include <map>
#include <algorithm>
#include <functional>
#include <set>


class Database {
public:
    void Add(const Date &date, const std::string &event);

    void Print(std::ostream &cout);

    using Predicate =  std::function<bool(const Date &, const std::string &)>;

    std::string RemoveIf(const std::function<bool(const Date &, const std::string &)> &predicate);

    std::vector<pair<Date, std::string>> FindIf(const std::function<bool(const Date &, const std::string &)> &predicate);

    friend void TestAddDateEvent();

    std::string Last(const Date &date);

private:
    std::map<Date, std::pair<std::set<std::string>, std::vector<std::string>>> database;
};


std::ostream &operator<<(std::ostream &stream, const std::pair<Date, std::string> &map);

void TestAddDateEvent();