<h1>Приложение 1</h1>

<h2>Общие сведения<h2>
<ul>  
<li>Приложение извлекает данные из файла input_data.txt, обрабатывает в соответствии с параметрами 
  обработки из файла config.json, и отправляет результат в файл result.txt.</li>
</ul>

<h2>Сборка</h2>
<ul>
<li>Система сборки - CMAKE</li>
<li>Папки со сборками отладки и выпуска нужно положить рядом с папкой task_1_3, либо потом переложить 
  файлы input_data.txt и config.json на уровень выше папок с билдами. Либо, как вариант, поправить пути к файлам в исходниках.</li>
</ul>

<h2>Настройка файла конфигурации</h2>

<h3>Тип входных данных</h3>
<ul>
  <li>Регулируется параметром "input_type"</li>
  <li>Значение 1 - int</li>
  <li>Значение 2 - float</li>
</ul>

<h3>Тип выходных данных</h3>
<ul>
  <li>Регулируется параметром "output_type"</li>
  <li>Значение 1 - int</li>
  <li>Значение 2 - float</li>
</ul>

<h3>Кол-во обработчиков</h3>
<ul>
  <li>Регулируется параметром "handlers_count"</li>
</ul>

<h3>Параметры обработчиков</h3>
<ul>
  <li>Все данные обработчиков лежат в массиве "handlers"</li>
  <li>Каждый обработчик - это пара из типа обработчика "handler", и аргумента - "argument"</li>
  <li>Виды обработчиков: 1 - умножение, 2 - возведение в степень, 3 - логарифм, 4 - вычисление среднего по последним 10-и обработанным числам</li>
</ul>




