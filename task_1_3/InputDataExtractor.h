#ifndef INPUTDATAEXTRACTOR_H
#define INPUTDATAEXTRACTOR_H

#pragma once
#include <memory>
#include <vector>
#include <fstream>

// класс извлекающий входные данные из файла в string-массив, который дальше пройдет через все обработки
class InputDataExtractor
{
    std::shared_ptr<std::vector<std::string> > string_input_data_; // указатель на массив с обрабатываемыми данными
public:
    InputDataExtractor(std::shared_ptr<std::vector<std::string> > string_input_data);
    void extract();
};

#endif // INPUTDATAEXTRACTOR_H
