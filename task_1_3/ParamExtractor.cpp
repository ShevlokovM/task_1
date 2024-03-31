#include "ParamExtractor.h"

ParamExtractor::ParamExtractor(std::shared_ptr<std::vector<std::pair<int, int> > > handlers, int * input_type, int * output_type)
{
    this->handlers_ = handlers;
    this->input_type_ = input_type;
    this->output_type_ = output_type;
}

///
/// \brief ParamExtractor::extract
/// извлекает данные из json-файла конфигурации
void ParamExtractor::extract()
{
    nlohmann::json json_config;   

    std::ifstream config("../config.json");

    if(config.is_open())
    {
        auto file_content = config.rdbuf();
        std::stringstream temp_file_content;
        temp_file_content << file_content;        
        json_config = nlohmann::json::parse(temp_file_content.str());
        config.close();
    }
    else
    {
        throw std::logic_error("Congig file was not opend!");
    }

    *input_type_ = json_config["input_type"];
    *output_type_ = json_config["output_type"];
    int handlers_count = json_config["handlers_count"];

    nlohmann::json json_handlers = json_config["handlers"];
    for(int i = 0; i < handlers_count; i++)
    {
        handlers_->emplace_back( json_handlers[i]["handler"], json_handlers[i]["argument"] );
    }
}

