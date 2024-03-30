#include "InputValidation.h"

InputValidation::InputValidation(std::shared_ptr<std::vector<std::string> > string_input_data)
{
    this->string_input_data_ = string_input_data;
}

///////////////////////////////////////////////////////////////////////////////////////////////

IntInputValidation::IntInputValidation(std::shared_ptr<std::vector<std::string> > string_input_data)
    : InputValidation::InputValidation(string_input_data) {}

bool IntInputValidation::check_input()
{
    for(auto & word : *string_input_data_)
    {
        for(auto & sign :word)
        {
            if(!std::isdigit(sign)) return false; // можно использовать регулярные выражения
        }
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////

FloatInputValidation::FloatInputValidation(std::shared_ptr<std::vector<std::string> > string_input_data)
    : InputValidation::InputValidation(string_input_data) {}

bool FloatInputValidation::check_input()
{
    for(auto & word : *string_input_data_)
    {
        bool dot_finded = false;
        for(auto & sign :word)
        {
            if(!std::isdigit(sign) || sign != '.') // можно использовать регулярные выражения
                return false;
            else if (sign == '.' && dot_finded)
                return false;
            else if (sign == '.' && !dot_finded)
                dot_finded = true;
        }
    }
    return true;
}
