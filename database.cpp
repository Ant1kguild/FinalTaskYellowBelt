//
// Created by ant1k on 16.3.18.
//

#include "database.h"
#include <set>


void Database::Add(const Date &date, const std::string &event) {
    auto dataEvent = database.dateEvent;
    //auto eventDate = database.eventsDate;
    auto itDate = dataEvent.find(date);
    //auto itEvent = eventDate.find(event);
    // проверяем что такая дата есть
    if (itDate != dataEvent.end()) {
        auto itEvent = find(itDate->second.begin(), itDate->second.end(), event); // ищем наличие события в дате
        if (itEvent == itDate->second.end()) {
            itDate->second.push_back(event);
        }
    } else {
        vector<string> e {event};
        dataEvent.insert(make_pair(date, e));
        dataEvent[date] = e;
    }
}

void Database::Print(std::ostream &cout) {
    for (const auto &i : database.dateEvent) {
        for (const auto &j : i.second) {
            cout << i.first << j << endl;
        }
    }
}


std::string Database::RemoveIf(const Predicate &predicate) {
    int quantity = 0;
    auto datesEvents = database.dateEvent;
    for (auto it = datesEvents.begin(); it != datesEvents.end(); ++it) {
        cout << it->second.size();
        for (auto it2 = it->second.begin(); it2 != it->second.end(); /*++it2*/) {
            std::cout << endl << "/" << it->first << *it2 << "/" << endl;
            if (removeByPredicate(predicate, it, it2)) {
                ++quantity;
            } else {
                ++it2;
            }
        }
    }
    return to_string(quantity);
}


std::vector<pair<Date, std::string>>
Database::FindIf(const Predicate &predicate) {
    std::vector<pair<Date, std::string>> quantity;
    auto datesEvents = database.dateEvent;
    for (auto it = datesEvents.begin(); it != datesEvents.end(); ++it) {
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            if (findByPredicate(predicate, it, it2)) quantity.emplace_back((*it).first, *it2);
        }
    }
    return quantity;
}

bool operator<(std::pair<const Date, std::vector<string>> &lhs, const Date &rhs) {
    return lhs.first < rhs;
}

std::string Database::Last(const Date &date) {
    std::string DateEvent;
    std::ostringstream lastDate;
    if (date < (*database.dateEvent.begin()).first || database.dateEvent.empty()) {
        throw invalid_argument(lastDate.str());
    } else {
        auto theLastDateInDB = lower_bound(database.dateEvent.begin(), database.dateEvent.end(), date);
        --theLastDateInDB;
        lastDate << (*theLastDateInDB).first << (*theLastDateInDB).second.back();
        DateEvent = lastDate.str();
        return DateEvent;
    }

}


void TestAddDateEvent() {
    {
//        Database db;
//        std::map<Date, std::vector<std::string>> test1;
//        test1[{1985, 10, 28}].emplace_back("My dr");
//        db.Add({1985, 10, 28}, "My dr");
//        JUnit::AssertEqual(test1, db.database, "Test #1");
//        JUnit::Assert((!db.database.empty()), "Test #1.1");
//        JUnit::Assert((db.database.size() == 1), "Test #1.2");
//        JUnit::Assert((db.database.size() < 2), "Test #1.3");
//        JUnit::Assert(!db.database.at({1985, 10, 28}).first.empty(), "Test #1.4.1");
//        JUnit::Assert(!db.database.at({1985, 10, 28}).second.empty(), "Test #1.4.2");
//        JUnit::Assert(db.database.at({1985, 10, 28}).first.size() == 1, "Test #1.5.1");
//        JUnit::Assert(db.database.at({1985, 10, 28}).second.size() == 1, "Test #1.5.2");
//        JUnit::Assert(db.database.at({1985, 10, 28}).first.size() < 2, "Test #1.6.1");
//        JUnit::Assert(db.database.at({1985, 10, 28}).second.size() < 2, "Test #1.6.2");
//        db.Add({1985, 10, 28}, "My dr");
//        JUnit::AssertEqual(test1, db.database, "Test #2");
//        JUnit::Assert((!db.database.empty()), "Test #2.1");
//        JUnit::Assert((db.database.size() == 1), "Test #2.2");
//        JUnit::Assert((db.database.size() < 2), "Test #2.3");
//        JUnit::Assert(!db.database.at({1985, 10, 28}).first.empty(), "Test #2.4.1");
//        JUnit::Assert(!db.database.at({1985, 10, 28}).second.empty(), "Test #2.4.2");
//        JUnit::Assert(db.database.at({1985, 10, 28}).first.size() == 1, "Test #2.5.1");
//        JUnit::Assert(db.database.at({1985, 10, 28}).second.size() == 1, "Test #2.5.2");
//        JUnit::Assert(db.database.at({1985, 10, 28}).first.size() < 2, "Test #2.6.1");
//        JUnit::Assert(db.database.at({1985, 10, 28}).second.size() < 2, "Test #2.6.2");
//        db.Add({1985, 10, 28}, "My dr");
//        JUnit::AssertEqual(test1, db.database, "Test #3");
//        JUnit::Assert((!db.database.empty()), "Test #3.1");
//        JUnit::Assert((db.database.size() == 1), "Test #3.2");
//        JUnit::Assert((db.database.size() < 2), "Test #3.3");
//        JUnit::Assert(!db.database.at({1985, 10, 28}).first.empty(), "Test #3.4.1");
//        JUnit::Assert(!db.database.at({1985, 10, 28}).second.empty(), "Test #3.4.2");
//        JUnit::Assert(db.database.at({1985, 10, 28}).first.size() == 1, "Test #3.5.1");
//        JUnit::Assert(db.database.at({1985, 10, 28}).second.size() == 1, "Test #3.5.2");
//        JUnit::Assert(db.database.at({1985, 10, 28}).first.size() < 2, "Test #3.6.1");
//        JUnit::Assert(db.database.at({1985, 10, 28}).second.size() < 2, "Test #3.6.2");
//        test1[{1985, 10, 28}].emplace_back("My Day");
//        db.Add({1985, 10, 28}, "My dr");
//        db.Add({1985, 10, 28}, "My Day");
//        db.Add({1985, 10, 28}, "My Day");
//        db.Add({1985, 10, 28}, "My Day");
//        JUnit::AssertEqual(test1, db.database, "Test #4");
//        JUnit::Assert((!db.database.empty()), "Test #4.1");
//        JUnit::Assert((db.database.size() == 1), "Test #4.2");
//        JUnit::Assert((db.database.size() < 2), "Test #4.3");
//        JUnit::Assert(!db.database.at({1985, 10, 28}).first.empty(), "Test #4.4.1");
//        JUnit::Assert(!db.database.at({1985, 10, 28}).second.empty(), "Test #4.4.2");
//        JUnit::Assert(db.database.at({1985, 10, 28}).first.size() == 1, "Test #4.5.1");
//        JUnit::Assert(db.database.at({1985, 10, 28}).second.size() == 1, "Test #4.5.2");
//        JUnit::Assert(db.database.at({1985, 10, 28}).first.size() < 3, "Test #4.6.1");
//        JUnit::Assert(db.database.at({1985, 10, 28}).second.size() < 3, "Test #4.6.2");
    }


}

bool Database::removeByPredicate(const Database::Predicate &function,
                                 map<Date, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator it1,
                                 __gnu_cxx::__normal_iterator<string *, vector<string>> it2) {
    if (findByPredicate(function, it1, it2)) {

        auto it = database.eventsDate.find(*it2);
        if (it != database.eventsDate.end()) {
            it->second.erase(it1->first);
            if (it->second.empty()) database.eventsDate.erase(it);
        }
        it1->second.erase(it2);
        it2++;
        if (it1->second.empty()) database.dateEvent.erase(it1);
        return true;
    }
    return false;
}

bool Database::findByPredicate(const Database::Predicate &function,
                               map<Date, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator it1,
                               __gnu_cxx::__normal_iterator<string *, vector<string>> it2) {
    auto result = function((*it1).first, *it2);
    switch (result.date) {
        case Condition::Any:
        case Condition::This:
            switch (result.event) {
                case Condition::Any:
                case Condition::This:
                    return true;
                case Condition::None:
                    it2++;
                    return false;
            }
        case Condition::None:
            it1++;
            return false;

    }
    return false;
}

std::ostream &operator<<(std::ostream &stream, const std::pair<Date, std::string> &map) {
    stream << map.first << map.second;
    return stream;
}
