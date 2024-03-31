#ifndef PARAMEXTRACTOR_H
#define PARAMEXTRACTOR_H

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>
#include <nlohmann/json.hpp>

// класс извлекающий параметры обработки из json-файла
class ParamExtractor
{
    int * input_type_; // тип входящих данных
    int * output_type_; // тип исходящих данных
    std::shared_ptr<std::vector<std::pair<int, int> > > handlers_; // указатель на массив обработчиков
public:
    ParamExtractor(std::shared_ptr<std::vector<std::pair<int, int> > > handlers, int * input_type, int * output_type);
    void extract();
};

#endif // PARAMEXTRACTOR_H
