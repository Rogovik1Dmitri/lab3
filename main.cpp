#include "finite-state machine.h"
using namespace std;

int main() {

    //пример конечного автомата который проверяет вхождение подстроки 1, 2, 3
    int states = 4; 
    vector <int> alphabetint = {1, 2, 3}; 
    int state = 0; 
    int final_state = 3; 
     vector <vector <int>> transitions = {{1, 0, 0}, {1, 2, 0}, {1, 0, 3}, {3, 3, 3}};
    vector<int> listint = {1, 2, 3, 2, 2, 1, 1};
    FiniteStateMachine<int> FiniteStateMachineInt(states, alphabetint, state, final_state, transitions);
    cout << FiniteStateMachineInt.check_str(listint) << endl;


    //пример конечного автомата который проверяет вхождение подстроки либо abd либо cbc
    states = 6; 
    vector <char> alphabet = {'a', 'b', 'c', 'd'}; 
    state = 0; 
    final_state = 5; 
    transitions = {{1, 0, 3, 0}, {1, 2, 3, 0}, {1, 0, 3, 5},
                   {1, 4, 3, 0}, {1, 0, 5, 0}, {5, 5, 5, 5}};
    vector<char> listchar = {'a', 'b', 'c', 'b', 'c', 'b', 'b', 'b'};
    FiniteStateMachine<char> FiniteStateMachineChar(states, alphabet, state, final_state, transitions);
    cout << FiniteStateMachineChar.check_str(listchar) << endl;
}