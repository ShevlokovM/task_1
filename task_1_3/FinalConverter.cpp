#include "FinalConverter.h"

FinalConverter::FinalConverter(std::shared_ptr<std::vector<std::string> > string_input_data)
{
    this->string_input_data_ = string_input_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////

IntToFloatConverter::IntToFloatConverter(std::shared_ptr<std::vector<std::string> > string_input_data)
    : FinalConverter::FinalConverter(string_input_data){}

///
/// \brief IntToFloatConverter::convert
/// конвертирует int во float. (можно это сделать просто приведением типов, но сделано по-другом для разнообразя)
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

///
/// \brief FloatToIntConverter::convert
/// конвертирует float в int. (можно это сделать просто приведением типов, но сделано по-другом для разнообразя)
void FloatToIntConverter::convert()
{
    for(auto & str : *(this->string_input_data_))
    {
        std::string::size_type n = str.find('.');
        str = str.substr(0, n);
    }
}
