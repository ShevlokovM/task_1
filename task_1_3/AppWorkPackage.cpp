#include "AppWorkPackage.h"

AppWorkPackage::AppWorkPackage() {}

void AppWorkPackage::init()
{
    this->string_input_data_ = std::make_shared<std::vector<std::string> >();
    this->handlers_ = std::make_shared<std::vector<std::pair<int, int> > >();
    this->input_data_extractor_ptr_ = std::make_shared<InputDataExtractor>(string_input_data_);
    this->param_extractor_ptr_ = std::make_shared<ParamExtractor>(this->handlers_, &this->input_type_, &this->output_type_);
}

void AppWorkPackage::create_run_package()
{
    init();

    try
    {
        this->param_extractor_ptr_->extract();
        this->input_data_extractor_ptr_->extract();
    }
    catch (const std::exception & e)
    {
        std::cerr << "Caught exception: " << e.what();
        return;
    }

    if(this->input_type_ == INT_)
    {
        input_validation_ptr_ = std::make_shared<IntInputValidation>(this->string_input_data_);

    }
    else if(this->input_type_ == FLOAT_)
    {
        input_validation_ptr_ = std::make_shared<IntInputValidation>(this->string_input_data_);
    }
    else
    {
        std::cerr << "Error: inputed type isn't supported!" ;
        return;
    }

    if(!input_validation_ptr_->check_input())
    {
        std::cerr << "Error: wrong inputed data format!" ;
        return;
    }

    if(this->input_type_ == INT_)
    {
        this->handler_ptr_ = std::make_shared<IntHandler>(this->string_input_data_, this->handlers_);
    }
    else if(this->input_type_ == FLOAT_)
    {
        this->handler_ptr_ = std::make_shared<FloatHandler>(this->string_input_data_, this->handlers_);
    }

    try
    {
        this->handler_ptr_->handle();
    }
    catch (const std::exception & e)
    {
        std::cerr << "Caught exception: " << e.what();
        return;
    }

    std::shared_ptr<FinalConverter> final_converter_ptr_;

    if(this->input_type_ == INT_ && this->output_type_ == FLOAT_)
    {
        final_converter_ptr_ = std::make_shared<IntToFloatConverter>(this->string_input_data_);
    }
    else if(this->input_type_ == FLOAT_ && this->output_type_ == INT_)
    {
        final_converter_ptr_ = std::make_shared<FloatToIntConverter>(this->string_input_data_);
    }

    if(final_converter_ptr_)
    {
        final_converter_ptr_->convert();
    }

    std::shared_ptr<ResultWriter> result_writer_ptr_ = std::make_shared<ResultWriter>(this->string_input_data_);

    try
    {
        result_writer_ptr_->write_data();
    }
    catch (const std::exception & e)
    {
        std::cerr << "Caught exception: " << e.what();
        return;
    }
}


