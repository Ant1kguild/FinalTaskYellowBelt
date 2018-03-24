//
// Created by ant1k on 17.3.18.
//

#pragma once

#include <utility>
#include <memory>

#include "comparison.h"
#include "logical_operation.h"
#include "date.h"

enum class Condition {
    Any,
    None,
    This
};



struct PredicateIt {
    PredicateIt(Condition _date, Condition _event): date(_date), event(_event) {}
    Condition date;
    Condition event;

    static PredicateIt createDate(bool result) {
        return PredicateIt(result ? Condition::This : Condition::None, Condition::Any);
    }

    static PredicateIt createEvent(bool result) {
        return PredicateIt(Condition::Any, result ? Condition::This : Condition::None);
    }


};



class Node {
public:
    Node() = default;

    virtual PredicateIt Evaluate(Date date, const std::string &event) = 0;
};

class EmptyNode : public Node {
public:
    EmptyNode() = default;

    PredicateIt Evaluate(Date date, const std::string &event) override {
        return PredicateIt(Condition::Any,Condition::Any);
    }


};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp, Date date);

    PredicateIt Evaluate(Date date, const std::string &event) override;

private:
    Comparison _cmp;
    Date _date;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison cmp, std::string value);

    PredicateIt Evaluate(Date date, const std::string &event) override;

private:
    Comparison _cmp;
    std::string _value;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation &logical_operation,
                         std::shared_ptr<Node> left,
                         std::shared_ptr<Node> right);

    PredicateIt Evaluate(Date date, const std::string &event) override;

private:
    LogicalOperation _logical_operation;
    std::shared_ptr<Node> _left;
    std::shared_ptr<Node> _right;
};


