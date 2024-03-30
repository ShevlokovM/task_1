#ifndef HANDLER_H
#define HANDLER_H

#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdexcept>


enum HandlerTypes
{
    MULT = 1,
    POW,
    EXP,
    AVERAGE
};


class Handler
{
protected:
    std::shared_ptr<std::vector<std::string> > string_input_data_;
    std::shared_ptr<std::vector<std::pair<int, int> > > handlers_;
public:
    Handler(std::shared_ptr<std::vector<std::string> > string_input_data,
            std::shared_ptr<std::vector<std::pair<int, int> > > handlers);
    virtual void handle() = 0;
};

class IntHandler : public Handler
{
public:
    IntHandler(std::shared_ptr<std::vector<std::string> > string_input_data,
               std::shared_ptr<std::vector<std::pair<int, int> > > handlers);
    virtual void handle() override;
};

class FloatHandler : public Handler
{
public:
    FloatHandler(std::shared_ptr<std::vector<std::string> > string_input_data,
                 std::shared_ptr<std::vector<std::pair<int, int> > > handlers);
    virtual void handle() override;
};

#endif // HANDLER_H
