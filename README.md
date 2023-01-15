# :lotus_position_man:  Get Next Line (GNL)  :lotus_position_man:


Цель этого проекта — написать функцию, которая возвращает строку, заканчивающуюся символом новой строки, считанную из дескриптора файла.

Этот проект не только позволит вам добавить очень удобную функцию в вашу коллекцию, но также позволит вам изучить очень интересную новую концепцию в программировании на C:
**"статические переменные"**

### Прототип функции
```c
int	get_next_line(int fd, char **line);
```
## Компиляция проекта 

Ваша программа должна компилироваться с флагом -D BUFFER_SIZE=xx, который будет использоваться в качестве размера буфера для вызовов чтения в вашем get_next_line.

Основное условие проекта: Функция "get_next_line" должна корректно работает при чтении из файла и при чтении из стандартного ввода.


**GNL с файлами**
```bash
gcc tests/main.c -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

./a.out tests/files/test01_with_lines
```

**GNL с текстом из терминала (stdin)**
```bash
gcc tests/main_stdin.c -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

./a.out
```


## Что нужно знать о GNL

Согласно теме проекта - "get_next_line" читает строку из файла, после чего готовится к чтению следующей строки. Вызов функции GNL в цикле позволит читать текст, доступный в файловом дескрипторе, по одной строке за раз, пока не достигнет EOF (конеца файла).

Ниже представлена фрагмент файла main, написанного для проверки функции GNL

```c
int main(int argc, char **argv)
{
	int fd, ret, line_count;
	char *line;

	line_count = 1;
	ret = 0;
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf(" \n [ Return: %d ] | A line has been read #%d => %s\n", ret, line_count, line);
			line_count++;
			free(line);
		}
		printf(" \n [ Return: %d ] A line has been read #%d: %s\n", ret, line_count++, line);
		printf("\n");
		if (ret == -1)
			printf("-----------\n An error happened\n");
		else if (ret == 0)
		{
			printf("-----------\n EOF has been reached\n");
			free(line);
		}
		close(fd);
	}
```

Одной из основных переменных проекта является fd (строка ниже), который возвращает целое чесло, что будет использоваться в качестве параметра для функции get_next_line .
```bash
fd = open(argv[1], O_RDONLY);
```

Функция **get_next_line** вернет целое число , которое будет использоваться для оценки всех строк до конца файла.

### Возвращаемые значения
 | Значение | Описание         |
 |-----------|----------------------|
 |  1| Строка прочитана |
 |  0| EOF (конец файла) |
 |  -1| Произошла ошибка |