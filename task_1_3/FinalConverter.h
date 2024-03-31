#ifndef FINALCONVERTER_H
#define FINALCONVERTER_H

#pragma once
#include <iostream>
#include <memory>
#include <vector>

// класс отвечающий за финальную конвертацию данных, перед записью в файл
class FinalConverter
{
protected:
    std::shared_ptr<std::vector<std::string> > string_input_data_; // указатель на массив с обрабатываемыми данными
public:
    FinalConverter(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual void convert() = 0;
};

// конвертация int - float
class IntToFloatConverter : public FinalConverter
{
public:
    IntToFloatConverter(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual void convert();
};

// конвертация float - int
class FloatToIntConverter : public FinalConverter
{
public:
    FloatToIntConverter(std::shared_ptr<std::vector<std::string> > string_input_data);
    virtual void convert();
};
#endif // FINALCONVERTER_H
