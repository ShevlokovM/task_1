#ifndef FINALCONVERTER_H
#define FINALCONVERTER_H

#pragma once
#include <iostream>
#include <memory>
#include <vector>

class FinalConverter
{
protected:
    std::shared_ptr<std::vector<std::string> > string_input_data_;
public:
    FinalConverter(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual void convert() = 0;
};

class IntToFloatConverter : public FinalConverter
{
public:
    IntToFloatConverter(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual void convert();
};

class FloatToIntConverter : public FinalConverter
{
public:
    FloatToIntConverter(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual void convert();
};
#endif // FINALCONVERTER_H
