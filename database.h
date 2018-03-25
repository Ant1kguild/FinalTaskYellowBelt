//
// Created by ant1k on 16.3.18.
//

#pragma once

#include "date.h"
#include "node.h"
#include <map>
#include <algorithm>
#include <functional>
#include <set>


struct DateEvent {
    std::map<Date, std::vector<string>> dateEvent;
    std::map<std::string, std::set<Date>> eventsDate;
};



class Database {
public:
    void Add(const Date &date, const std::string &event);

    void Print(std::ostream &cout);

    using Predicate =  std::function<PredicateIt(const Date &, const std::string &)>;

    std::string RemoveIf(const Predicate &predicate);

    std::vector<pair<Date, std::string>> FindIf(const Predicate &predicate);

    friend void TestAddDateEvent();

    std::string Last(const Date &date);

private:
    DateEvent database;

    bool removeByPredicate(const Predicate &function,
                           map<Date, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator iterator,
                           __gnu_cxx::__normal_iterator<string *, vector<string>> normal_iterator);

    bool findByPredicate(const Predicate &function,
                         map<Date, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator iterator,
                         __gnu_cxx::__normal_iterator<string *, vector<string>> normal_iterator);
};


std::ostream &operator<<(std::ostream &stream, const std::pair<Date, std::string> &map);

void TestAddDateEvent();