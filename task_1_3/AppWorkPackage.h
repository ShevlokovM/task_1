#ifndef APPWORKPACKAGE_H
#define APPWORKPACKAGE_H

#pragma once

#include <memory>
#include "ParamExtractor.h"
#include "InputDataExtractor.h"
#include "InputValidation.h"
#include "Handler.h"
#include "FinalConverter.h"
#include "ResultWriter.h"

enum VarTypes
{
    INT_ = 1,
    FLOAT_
};

class AppWorkPackage
{
    // указатели на классы, реализующие функеционал приложения
    std::shared_ptr<ParamExtractor> param_extractor_ptr_;
    std::shared_ptr<InputDataExtractor> input_data_extractor_ptr_;
    std::shared_ptr<InputValidation> input_validation_ptr_;
    std::shared_ptr<Handler> handler_ptr_;

    // входящие/исходящие параметры
    int input_type_;
    int output_type_;
    std::shared_ptr<std::vector<std::pair<int, int> > > handlers_;
    std::shared_ptr<std::vector<std::string> > string_input_data_;
public:
    AppWorkPackage();
    void init();
    void create_run_package();
};

#endif // APPWORKPACKAGE_H
