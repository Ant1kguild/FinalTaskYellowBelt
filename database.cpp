//
// Created by ant1k on 16.3.18.
//

#include "database.h"


void Database::Add(const Date &date, const std::string &event) {
    auto dateAvailability = binary_search(database.begin(), database.end(), date);
    if (dateAvailability) {
        auto eventAvailability = binary_search(database[date].first.begin(), database[date].first.end(), event);
        if (!eventAvailability) {
            database[date].first.insert(event);
            database[date].second.push_back(event);
        }
    } else {
        database[date].first.insert(event);
        database[date].second.push_back(event);
    }

}

void Database::Print(std::ostream &cout) {
    for (const auto &i : database) {
        for (const auto &j : i.second.second) {
            cout << i.first << j << endl;
        }
    }
}


std::string Database::RemoveIf(const std::function<bool(const Date &, const std::string &)> &predicate) {
    int quantity = 0;
    std::string emptyEvent;
            for (auto &i : database) {
            if (predicate(i.first, emptyEvent)) {
                quantity += i.second.first.size();
                database.erase(i.first);
            } else {
                for (auto &j : i.second.first) {
                    if (predicate(i.first, j)) {
                        auto ItVec = find(database[i.first].second.begin(), database[i.first].second.end(), j);
                        database[i.first].first.erase(j);
                        database[i.first].second.erase(ItVec);
                        ++quantity;
                    }
                }
            }
            if (database[i.first].first.empty() && database[i.first].second.empty()) database.erase(i.first);
        }


    return to_string(quantity);
}


std::vector<pair<Date, std::string>>
Database::FindIf(const std::function<bool(const Date &, const std::string &)> &predicate) {
    std::vector<pair<Date, std::string>> quantity;
    for (const auto &i : database) {
        for (const auto &j : i.second.second) {
            if (predicate(i.first, j)) {
                quantity.emplace_back(i.first, j);
            }
        }
    }
    return quantity;
}


std::string Database::Last(const Date &date) {
    std::string DateEvent;
    std::ostringstream lastDate;
    if (date < (*database.begin()).first || database.empty()) {
        throw invalid_argument(lastDate.str());
    } else {
        auto theLastDateInDB = lower_bound(database.begin(), database.end(), date);
        --theLastDateInDB;
        lastDate << (*theLastDateInDB).first << (*theLastDateInDB).second.second.back();
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

std::ostream &operator<<(std::ostream &stream, const std::pair<Date, std::string> &map) {
    stream << map.first << map.second;
    return stream;
}
