#include "InputDataExtractor.h"

InputDataExtractor::InputDataExtractor(std::shared_ptr<std::vector<std::string> > string_input_data)
{
    this->string_input_data_ = string_input_data;
}

///
/// \brief InputDataExtractor::extract
/// извлекает данные из файла, и кладет их в string-массив
void InputDataExtractor::extract()
{
    std::ifstream data_file("../input_data.txt");

    if(data_file.is_open())
    {
        while(true)
        {
            if(data_file.eof())
                break;

            std::string line;
            std::getline(data_file, line);
            if(line != "")
                this->string_input_data_->push_back(line);
        }

        data_file.close();
    }
    else
    {
        throw std::logic_error("Data file was not opened!");
    }
}
