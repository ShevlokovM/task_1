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

// возможные типы входных данных
enum VarTypes
{
    INT_ = 1,
    FLOAT_
};

// главный класс приложения, хранящий ссылки на всю последовательность обработок, и запускающий обработку
class AppWorkPackage
{
    // указатели на классы, реализующие функеционал приложения
    std::shared_ptr<ParamExtractor> param_extractor_ptr_; // указатель на класс, извлекающий параметры обработки
    std::shared_ptr<InputDataExtractor> input_data_extractor_ptr_; // указатель на класс извлекающий входные данные для обработки
    std::shared_ptr<InputValidation> input_validation_ptr_; // указатель на класс проверяющий корректность входных данных (можно было сделать аналогичный для файла конфигурации)
    std::shared_ptr<Handler> handler_ptr_; // указатель на базовый класс обработчик входлных данных

    // входящие/исходящие параметры
    int input_type_; // тип входящих данных
    int output_type_; // тип исходящих данных
    std::shared_ptr<std::vector<std::pair<int, int> > > handlers_; // указатель на массив с цепочкой обработок
    std::shared_ptr<std::vector<std::string> > string_input_data_; // указатель на массив с извлеченными входными данными. Он будет задействован на всех этапах до записи в файл с результатами.
public:
    AppWorkPackage();
    void init();
    void create_run_package();
};

#endif // APPWORKPACKAGE_H
