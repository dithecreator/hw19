//
//  printer.hpp
//  hw19
//
//  Created by Дима on 08.10.23.
//

#ifndef printer_hpp
#define printer_hpp
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Wait
{
    // очередь
    int* wait;
    //приоритет
    int* Pri;
    // максимальный размер очереди
    int MaxQueueLength;
    // текущий размер очереди
    int QueueLength;
    string name;
    string time;

public:
    //  конструктор
    Wait(int m);

    //деструктор
    ~Wait();

    // добавление элемента
    void Add(int c, int p);

    // извлечение элемента
    int Extract();

    // очистка очереди
    void Clear();

    // проверка существования элементов в очереди
    bool IsEmpty();

    // проверка на переполнение очереди
    bool IsFull();

    //  количество элементов в очереди
    int GetCount();

    //демонстрация очереди
    void Show();
};


#endif /* printer_hpp */
