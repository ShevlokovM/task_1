#include "ResultWriter.h"

ResultWriter::ResultWriter(std::shared_ptr<std::vector<std::string> > string_input_data)
{
    this->string_input_data_ = string_input_data;
}

void ResultWriter::write_data()
{
    std::ofstream result("../result.txt");

    if(result.is_open())
    {
        for(auto & str : *(this->string_input_data_))
        {
            result << str << "\n";
        }
        result.close();
    }
    else
    {
        throw std::logic_error("File result.txt was not opend!");
    }
}
