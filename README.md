# Сортировка строк файла

Домашнее задание по Программной Инженерии. Костарев Александр, СГН3-33Б.

## Условие задачи

В текстовом файле содержатся строки, содержащие слова из латинских букв и цифры. 
Преобразовать строки файла следующим образом: упорядочить слова по алфавите, и в конце 
добавить сумму цифр (если цифры есть в строке).

## Запуск программы

Для сборки программы необходим `cmake`. Чтобы произвести сборку введите в корне проекта:
```sh
$ ./build.sh
```

Запуск (где `file.txt` - имя изменяемого файла):
```sh
$ ./run.sh file.txt
```

**ВАЖНО**: Программа изменяет подаваемый на вход файл. Для сохранения данных рекомендуется сделать копию.

## Запуск тестов

Тесты находятся в директории `tests/`. Для того чтобы произвести сборку модульных тестов:
```sh
$ cd tests
$ ./build-unit-tests.sh
```

Запуск модульных тестов:
```sh
$ ./run-unit-tests.sh
```

Запуск тестов методом "белого ящика":
```sh
$ ./run-white-box-tests.sh
```

Для того, чтобы запустить все тесты сразу:
```sh
$ ./run-tests.sh
```

## Спецификация

Спецификацию, допущения и псевдокод (первую часть ДЗ) можно найти 
[здесь](https://docs.google.com/document/d/1cJst3UozToNJ838CUsn6B6ivlfLkuEFXmQhlgxiyjGQ/edit?usp=sharing)).
