#ifndef INPUTDATAEXTRACTOR_H
#define INPUTDATAEXTRACTOR_H

#pragma once
#include <memory>
#include <vector>
#include <fstream>

class InputDataExtractor
{
    std::shared_ptr<std::vector<std::string> > string_input_data_;
public:
    InputDataExtractor(std::shared_ptr<std::vector<std::string> > string_input_data);
    void extract();
};

#endif // INPUTDATAEXTRACTOR_H
