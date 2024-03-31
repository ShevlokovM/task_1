#ifndef RESULTWRITER_H
#define RESULTWRITER_H

#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

// записывает данные в файл с результатами
class ResultWriter
{
    std::shared_ptr<std::vector<std::string> > string_input_data_; // указатель на массив с обрабатываемыми данными
public:
    ResultWriter(std::shared_ptr<std::vector<std::string> > string_input_data);
    void write_data();
};

#endif // RESULTWRITER_H
