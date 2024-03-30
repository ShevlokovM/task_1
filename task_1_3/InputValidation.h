#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

class InputValidation
{
protected:
    std::shared_ptr<std::vector<std::string> > string_input_data_;
public:
    InputValidation(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual bool check_input() = 0;
};

class IntInputValidation : public InputValidation
{
public:
    IntInputValidation(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual bool check_input() override;
};

class FloatInputValidation : public InputValidation
{
public:
    FloatInputValidation(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual bool check_input() override;
};

#endif // INPUTVALIDATION_H
