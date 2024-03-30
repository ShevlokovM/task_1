#ifndef PARAMEXTRACTOR_H
#define PARAMEXTRACTOR_H

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>
#include <nlohmann/json.hpp>

class ParamExtractor
{
    int * input_type_;
    int * output_type_;
    std::shared_ptr<std::vector<std::pair<int, int> > > handlers_;
public:
    ParamExtractor(std::shared_ptr<std::vector<std::pair<int, int> > > handlers, int * input_type, int * output_type);
    void extract();
};

#endif // PARAMEXTRACTOR_H
