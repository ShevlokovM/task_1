#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

// базовый абстрактный класс, организующий проверку валидности данных
class InputValidation
{
protected:
    std::shared_ptr<std::vector<std::string> > string_input_data_; // указатель на массив с обрабатываемыми данными
public:
    InputValidation(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual bool check_input() = 0;
};

// класс проверяющий валидность int-данных
class IntInputValidation : public InputValidation
{
public:
    IntInputValidation(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual bool check_input() override;
};

// класс проверяющий валидность float-данных
class FloatInputValidation : public InputValidation
{
public:
    FloatInputValidation(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual bool check_input() override;
};

#endif // INPUTVALIDATION_H
