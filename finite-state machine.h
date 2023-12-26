#ifndef FINITE_STATE_MACHINE_H
#define FINITE_STATE_MACHINE_H
#include <string>
#include <vector>
#include <iostream>

template  <class Type>
class FiniteStateMachine {
    public:
        FiniteStateMachine(int states_, std:: vector <Type> alphabet_, int state_, 
        int final_state_, std::vector <std::vector <int>>  transition_) {
            states = states_;
            alphabet = alphabet_;
            state = state_;
            final_state = final_state_;
            transition = transition_;
        }


        //главная функция которая получает вектор с объектами типа Type и возвращает 
        //true (1) если принимает этот вектор
        //false (0) если не принимает
        bool check_str(std::vector<Type> str) {
            
            Type str_now; // объект который будем искать в алфавите на каждом следующем шагу
            int ind;
            for (int i = 0; i < str.size(); ++i) {
                str_now = str[i]; // определяем текущий объект
                ind = alphabet_ind(str_now); //ищем индекс в алфавите этого объекта
                if (ind >= 0) { //если такой объект присутсвует в алфавите то ind будет >=0
                    state = transition[state][ind]; //ссовершаем переход к новому состоянию
                } else { // если такого объекта нет то ind равен -1 а значит автомат не может принять эту строку
                    return 0;  
                }
            }
            if (state == final_state) return 1; //если в итоге состояние равно состоянию выхода то строка (вектор) приянта
            else return 0;
        }

    private:
        //набор состояний (он же и количество строк в матрице перехода)
        int states; 


        //алфавит это вектор объектов типа Type
        std:: vector<Type> alphabet; 

        int state; //начальное состояние (оно же текущее)
        int final_state; //состояние выхода

        //transitions - двумерный массив (матрица) переходов
        //индексом строки для массива является текущее состояние по которому
        //индексом столбца (второй параметр) является позиция встреченного элемента в алфавите
        std:: vector <std::vector <int>>  transition;



        //передаем в функцию объект типа Type и проверяем есть ли такой же объект в алфавите
        //если нет то возвращаем -1
        int alphabet_ind(Type char_now) {
            for (int k = 0; k < alphabet.size(); ++k) { 
                if (alphabet[k] == char_now) return k;
            }
            return -1;
        }
};

#endif // FINITE_STATE_MACHINE_H