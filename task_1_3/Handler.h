#ifndef HANDLER_H
#define HANDLER_H

#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdexcept>

// все возможные в приложении типы обработки данных
enum HandlerTypes
{
    MULT = 1,
    POW,
    EXP,
    AVERAGE
};

// класс применяющий цепочку обработок к каждому элементу массива входных данных
class Handler
{
protected:
    std::shared_ptr<std::vector<std::string> > string_input_data_; // указатель на массив с обрабатываемыми данными
    std::shared_ptr<std::vector<std::pair<int, int> > > handlers_; // массив содержащий цепочку обработок
public:
    Handler(std::shared_ptr<std::vector<std::string> > string_input_data,
            std::shared_ptr<std::vector<std::pair<int, int> > > handlers);
    virtual void handle() = 0;
};

// класс обрабатывающй int
class IntHandler : public Handler
{
public:
    IntHandler(std::shared_ptr<std::vector<std::string> > string_input_data,
               std::shared_ptr<std::vector<std::pair<int, int> > > handlers);
    virtual void handle() override;
};

// класс обрабатывающй float
class FloatHandler : public Handler
{
public:
    FloatHandler(std::shared_ptr<std::vector<std::string> > string_input_data,
                 std::shared_ptr<std::vector<std::pair<int, int> > > handlers);
    virtual void handle() override;
};

#endif // HANDLER_H
