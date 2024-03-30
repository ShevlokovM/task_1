#include "FinalConverter.h"

FinalConverter::FinalConverter(std::shared_ptr<std::vector<std::string> > string_input_data)
{
    this->string_input_data_ = string_input_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////

IntToFloatConverter::IntToFloatConverter(std::shared_ptr<std::vector<std::string> > string_input_data)
    : FinalConverter::FinalConverter(string_input_data){}

void IntToFloatConverter::convert()
{
    for(auto & str : *(this->string_input_data_))
    {
        str += ".0";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////

FloatToIntConverter::FloatToIntConverter(std::shared_ptr<std::vector<std::string> > string_input_data)
    : FinalConverter::FinalConverter(string_input_data){}

void FloatToIntConverter::convert()
{
    for(auto & str : *(this->string_input_data_))
    {
        std::string::size_type n = str.find('.');
        str = str.substr(0, n);
    }
}
