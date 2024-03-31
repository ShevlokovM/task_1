#include "Handler.h"

Handler::Handler(std::shared_ptr<std::vector<std::string> > string_input_data,
                 std::shared_ptr<std::vector<std::pair<int, int> > > handlers)
{
    this->string_input_data_ = string_input_data;
    this->handlers_ = handlers;
}

IntHandler::IntHandler(std::shared_ptr<std::vector<std::string> > string_input_data,
                       std::shared_ptr<std::vector<std::pair<int, int> > > handlers)
    : Handler::Handler(string_input_data, handlers) {}

///
/// \brief IntHandler::handle
/// Обрабатывает int-данные. Достает данные их string-массива, конвертирует в double,
/// чтобы в процессе не терялась точность, и прогоняет их по цепочке обработки.
/// После чего конвертирует их в int, потом еще раз в string, и отправляет обратно
/// вo входящий массив на свое место.
void IntHandler::handle()
{
    // реализация кольцевого буфера для рассчета среднего по последним 10-и результатам.
    // если результатов меньше, то соответственно среднее вычисляется по кол-ву результатов в наличии
    // плюс текущее входное число.
    // можно было сделать банально, просто доставать из входного массива данные, но мне показалось что так интереснее
    int sum[9] = {0,0,0,0,0,0,0,0,0};
    int count = 0;
    int pos = 0;

    // внешний цикл по массиву входных данных, внутренний - по массиву обработчиков
    // цмкл обработчиков состоит из пар, в которой: first - индекс обработки, second - аргумент для обработки
    std::for_each(this->string_input_data_->begin(), this->string_input_data_->end(), [this, &sum, & count, & pos](std::string & number){

        double temp = std::stod(number);

        for(auto & pair_ : *this->handlers_)
        {
            switch(pair_.first)
            {
            case MULT:
                temp *= pair_.second;
                break;
            case POW:
                temp = std::pow(temp, pair_.second);
                break;
            case EXP:
                temp = std::log(temp) / std::log(pair_.second);
                break;
            case AVERAGE:
                int sum_last_10 = temp;
                for(int i = 0; i < 9; i++)
                {
                    sum_last_10 += sum[i];
                }
                temp = sum_last_10 / (count + 1);
                break;
            defafult:
                throw std::logic_error("Wrong handler type!");
            }
        }

        // апдейты для кольцевого буфера
        sum[pos] = temp;
        pos++;
        if(pos == 9)
            pos = 0;
        if(count <= 9)
            count++;

        // сохранение результата
        int handled_number = (int) temp;
        number = std::to_string(handled_number);
    });
}

FloatHandler::FloatHandler(std::shared_ptr<std::vector<std::string> > string_input_data,
                           std::shared_ptr<std::vector<std::pair<int, int> > > handlers)
    : Handler::Handler(string_input_data, handlers) {}

///
/// \brief FloatHandler::handle
/// Обрабатывает floa-данные. Достает данные их string-массива, конвертирует вo float,
/// и прогоняет их по цепочке обработки. После чего конвертирует их в string, и отправляет обратно
/// вo входящий массив на свое место.
void FloatHandler::handle()
{
    // реализация кольцевого буфера для рассчета среднего по последним 10-и результатам.
    // если результатов меньше, то соответственно среднее вычисляется по кол-ву результатов в наличии
    // плюс текущее входное число.
    // можно было сделать банально, просто доставать из входного массива данные, но мне показалось что так интереснее/
    float sum[9] = {0,0,0,0,0,0,0,0,0};
    int count = 0;
    int pos = 0;

    // внешний цикл по массиву входных данных, внутренний - по массиву обработчиков
    // цмкл обработчиков состоит из пар, в которой: first - индекс обработки, second - аргумент для обработки
    std::for_each(this->string_input_data_->begin(), this->string_input_data_->end(), [this, &sum, & count, & pos](std::string & number){

        float temp = std::stof(number);

        for(auto & pair_ : *this->handlers_)
        {
            switch(pair_.first)
            {
            case MULT:
                temp += pair_.second;
                break;
            case POW:
                temp = std::pow(temp, pair_.second);
                break;
            case EXP:
                temp = std::log(temp) / std::log(pair_.second);
                break;
            case AVERAGE:
                float sum_last_10 = temp;
                for(int i = 0; i < 9; i++)
                {
                    sum_last_10 += sum[i];
                }
                temp = sum_last_10 / (count + 1);
                break;
            defafult:
                throw std::logic_error("Wrong handler type!");
            }
        }

        // апдейты для кольцевого буфера
        sum[pos] = temp;
        pos++;
        if(pos == 9)
            pos = 0;
        if(count < 9)
            count++;

        // сохранение результата
        number = std::to_string(temp);
    });
}
