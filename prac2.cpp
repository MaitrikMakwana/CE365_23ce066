#include <iostream>
#include <string>

using namespace std;

#define MAX_STATES 100
#define MAX_SYMBOLS 20

int main() {
    int num_symbols, num_states, start_state, num_accepting;
    char symbols[MAX_SYMBOLS];
    int accepting_states[MAX_STATES];
    int transition[MAX_STATES][MAX_SYMBOLS];
    string input_string;
    int current_state;
    int is_accepting;

   
    cout << "Number of input symbols : ";
    cin >> num_symbols;

 
    cout << "Input symbols : ";
    for (int i = 0; i < num_symbols; i++) {
        cin >> symbols[i];
    }

    cout << "Enter number of states : ";
    cin >> num_states;

 
    cout << "Initial state : ";
    cin >> start_state;

 
    cout << "Number of accepting states : ";
    cin >> num_accepting;

    cout << "Accepting states : ";
    for (int i = 0; i < num_accepting; i++) {
        cin >> accepting_states[i];
    }

   
    cout << "Transition table :\n";
    for (int i = 1; i <= num_states; i++) {
        for (int j = 0; j < num_symbols; j++) {
            cout << i << " to " << symbols[j] << " -> ";
            cin >> transition[i][j];
        }
    }

   
    cout << "Input string : ";
    cin >> input_string;

  
    current_state = start_state;
    int valid_symbol = 1;

    for (int i = 0; i < input_string.length(); i++) {
        int symbol_index = -1;

        for (int j = 0; j < num_symbols; j++) {
            if (input_string[i] == symbols[j]) {
                symbol_index = j;
                break;
            }
        }

        if (symbol_index == -1) {
            valid_symbol = 0;
            break;
        }

        current_state = transition[current_state][symbol_index];
    }

    if (!valid_symbol) {
        cout << "Invalid String\n";
    } else {
        is_accepting = 0;

        for (int i = 0; i < num_accepting; i++) {
            if (current_state == accepting_states[i]) {
                is_accepting = 1;
                break;
            }
        }

        if (is_accepting) {
            cout << "Valid String\n";
        } else {
            cout << "Invalid String\n";
        }
    }

    return 0;
}
