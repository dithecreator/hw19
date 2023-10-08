//
//  printer.cpp
//  hw19
//
//  Created by Дима on 08.10.23.
//

#include "printer.hpp"
//
//  main.cpp
//  priorityQueue
//
//  Created by Дима on 08.10.23.
//

#include <iostream>
#include <string.h>
#include <time.h>
#include <string>
#include <ctime>
using namespace std;


void Wait::Show() {
    cout << "\n-------------------------------------\n";
    //демонстрация очереди
    for (int i = 0; i < QueueLength; i++) {
        cout << wait[i] << " - " << Pri[i] << " - " << time[i] << \n\n";
    }
    cout << "\n-------------------------------------\n";
}

Wait::~Wait()
{
    //удаление очереди
    delete[]wait;
    delete[]Pri;
}

Wait::Wait(int m)
{
    //получаем размер
    MaxQueueLength = m;
    //создаём очередь
    wait = new int[MaxQueueLength];
    Pri = new int[MaxQueueLength];
    // изначально очередь пуста
    QueueLength = 0; 
}

void Wait::Clear()
{
    // эффективная очистка очереди
    QueueLength = 0;
}

bool Wait::IsEmpty()
{
    // пуст?
    return QueueLength == 0;
}

bool Wait::IsFull()
{
    // полон?
    return QueueLength == MaxQueueLength;
}

int Wait::GetCount()
{
    //  количество присутствующих элементов в стеке
    return QueueLength;
}

void Wait::Add(int c, int p)
{
    // если в очереди есть свободное место, то увеличиваем количество
    // значений и вставляем новый элемент

    time_t currentTime;
       struct tm localTimeInfo;
       time(&currentTime);
       localtime_r(&currentTime, &localTimeInfo);
    if (!IsFull())
        {
            cout << "priority: ";
            cin >> Pri[QueueLength];
            cout << "name: ";
            cin >> name;
            time[QueueLength] = to_string(t.wHour) + ":" + to_string(t.wMinute) + ":" + to_string(t.wSecond);
            QueueLength++;
        }
}

int Wait::Extract()
{
    // если в очереди есть элементыm то возвращаем тот,
    // у которого наивысший приоритет и сдвигаем очередь
    if (!IsEmpty()) {


        //пусть приоритетный элемент - нулевой
        int max_pri = Pri[0];
        //а приоритетный индекс = 0
        int pos_max_pri = 0;

        //ищем приоритет
        for (int i = 1; i < QueueLength; i++)
            //если встречен более приоритетный элемент
            if (max_pri < Pri[i]) {
                max_pri = Pri[i];
                pos_max_pri = i;
            }

        //вытаскиваем приоритетный элемент
        int temp1 = wait[pos_max_pri];
        int temp2 = Pri[pos_max_pri];

        //сдвинуть все элементы
        for (int i = pos_max_pri; i < QueueLength - 1; i++) {
            wait[i] = wait[i + 1];
            Pri[i] = Pri[i + 1];
        }
        //уменьшаем количество
        QueueLength--;
        // возврат извлеченного элемента
        return temp1;

    }
    else return -1;
}




