// file name:CS112_A2_T3_s12_20231182_20231007_20231076.cpp
// this is a fraction calculator you can use to do any operation between two fractions
// Author: muhannad salah , section_s12
// Emails: /muhannad salah:smohand119@gmail.com/ /ahmed hatem:ahmedhatem10000@gmail.com/ /Sama Waleed:samaw7824@gmail.com/
// ID1: 20231182 – the part he did: the plus operation
// ID2: 20231007 – the part he did: the minus operation
// ID3: 20231076 – the part she did: the multiple and division operation
// the algorithm link for encryption and decryption program:https://drive.google.com/file/d/1lAAGKBQwXijj7M2p-g3HL92F2j404Iu9/view?usp=sharing



#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>


// validition function
bool validation(const std::string& input) {
    for (char c : input) {
        if (!std::isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != ' ') {
            return false;
        }
    }
    return true;
}

int main() {
    using namespace std;
    string input;
// infinity loop
    while (true) {
        // the main menu
        cout << "Please enter a rational number operations (or exit): ";
        getline(cin, input);

        if (input == "exit") {
            cout << "Thank you for using the rational number calculator";
            break;
        }
        // checks for the operation and spaces
        if (!validation(input)) {
            cerr << "Invalid operation." << endl;
            continue;
        }

        istringstream iss(input);
        string firstnum, operation, secondnum;

        if (getline(iss, firstnum, ' ') &&
            getline(iss, operation, ' ') &&
            getline(iss, secondnum, ' ')) {
            string numerator1, denominator1, numerator2, denominator2;
            int numerator11, denominator11, numerator12, denominator12;

            size_t found = firstnum.find_first_of('/');
            if (found != std::string::npos) {
                numerator1 = firstnum.substr(0, found);
                denominator1 = firstnum.substr(found + 1);
            } else {
                numerator1 = firstnum;
                denominator1 = "1"; // Default denominator to 1
            }

            size_t find = secondnum.find_first_of('/');
            if (find != std::string::npos) {
                numerator2 = secondnum.substr(0, find);
                denominator2 = secondnum.substr(find + 1);
            } else {
                numerator2 = secondnum;
                denominator2 = "1"; // Default denominator to 1
            }

            numerator11 = stoi(numerator1);
            numerator12 = stoi(numerator2);
            denominator11 = stoi(denominator1);
            denominator12 = stoi(denominator2);

            int den;
            int num;
            // THE PLUS OPERATION
            if (operation == "+") {
                den = denominator11 * denominator12;
                num = (numerator11 * denominator12) + (numerator12 * denominator11);
                if (den == 0){
                    cout << "Invalid input." << endl;
                }else{
                    cout << num << "/" << den << endl;
                }

             // THE MINUS OPERATION
            } else if (operation == "-") {
                den = denominator11 * denominator12;
                num = (numerator11 * denominator12) - (numerator12 * denominator11);
                if (den == 0){
                    cout << "Invalid input." << endl;
                }
                if (num == 0) {
                    cout << "0" << endl;
                } else {
                    cout << num << "/" << den << endl;
                }
            // THE MULTIPLE OPERATION
            } else if (operation == "*") {
                den = denominator11 * denominator12;
                num = numerator11 * numerator12;
                if (den == 0){
                    cout << "Invalid input."<<endl;
                }else{
                    cout << num << "/" << den << endl;
                }

            // THE DIVISION OPERATION
            } else if (operation == "/") {
                if (denominator12 == 0) {
                    cerr << "Division by zero" << endl;
                    continue;
                }
                num = numerator11 * denominator12;
                den = denominator11 * numerator12;
                if (den == 0){
                    cout << "Invalid input."<<endl;
                }else{
                    cout << num << "/" << den << endl;
                }

            }

        } else {
            cout << "Error: Input doesn't contain spaces." << endl;
        }
    }
    return 0;
}


//the pseudo code of the code


/*FUNCTION validation(input: STRING) -> BOOLEAN
    FOR EACH character c IN input DO
        IF c IS NOT a digit AND c IS NOT one of '+', '-', '*', '/', ' ' THEN
            RETURN FALSE
        END IF
    END FOR
    RETURN TRUE
END FUNCTION

FUNCTION main()
    DECLARE input: STRING

    WHILE TRUE DO
        OUTPUT "Please enter a rational number operations (or exit): "
        READ input FROM stdin

        IF input EQUALS "exit" THEN
            OUTPUT "Thank you for using the rational number calculator"
            BREAK
        END IF

        IF NOT validation(input) THEN
            OUTPUT TO stderr: "Invalid operation."
            CONTINUE
        END IF

        DECLARE iss: STRINGSTREAM
        DECLARE firstnum, operation, secondnum: STRING

        IF GETLINE(iss, firstnum, ' ') AND
           GETLINE(iss, operation, ' ') AND
           GETLINE(iss, secondnum, ' ') THEN

            DECLARE numerator1, denominator1, numerator2, denominator2: STRING
            DECLARE numerator11, denominator11, numerator12, denominator12: INTEGER

            DECLARE found, find: INTEGER
            found = FIND_FIRST_OF('/', firstnum)
            IF found NOT EQUAL TO std::string::npos THEN
                numerator1 = SUBSTRING(firstnum, 0, found)
                denominator1 = SUBSTRING(firstnum, found + 1)
            ELSE
                numerator1 = firstnum
                denominator1 = "1" // Default denominator to 1
            END IF

            find = FIND_FIRST_OF('/', secondnum)
            IF find NOT EQUAL TO std::string::npos THEN
                numerator2 = SUBSTRING(secondnum, 0, find)
                denominator2 = SUBSTRING(secondnum, find + 1)
            ELSE
                numerator2 = secondnum
                denominator2 = "1" // Default denominator to 1
            END IF

            numerator11 = TO_INTEGER(numerator1)
            numerator12 = TO_INTEGER(numerator2)
            denominator11 = TO_INTEGER(denominator1)
            denominator12 = TO_INTEGER(denominator2)

            DECLARE den, num: INTEGER

            IF operation EQUALS "+" THEN
                den = denominator11 * denominator12
                num = (numerator11 * denominator12) + (numerator12 * denominator11)
                IF den EQUALS 0 THEN
                    OUTPUT "Invalid input."
                ELSE
                    OUTPUT num CONCATENATED WITH "/" CONCATENATED WITH den
                END IF
            ELSE IF operation EQUALS "-" THEN
                den = denominator11 * denominator12
                num = (numerator11 * denominator12) - (numerator12 * denominator11)
                IF den EQUALS 0 THEN
                    OUTPUT "Invalid input."
                END IF
                IF num EQUALS 0 THEN
                    OUTPUT "0"
                ELSE
                    OUTPUT num CONCATENATED WITH "/" CONCATENATED WITH den
                END IF
            ELSE IF operation EQUALS "*" THEN
                den = denominator11 * denominator12
                num = numerator11 * numerator12
                IF den EQUALS 0 THEN
                    OUTPUT "Invalid input."
                ELSE
                    OUTPUT num CONCATENATED WITH "/" CONCATENATED WITH den
                END IF
            ELSE IF operation EQUALS "/" THEN
                IF denominator12 EQUALS 0 THEN
                    OUTPUT TO stderr: "Division by zero"
                    CONTINUE
                END IF
                num = numerator11 * denominator12
                den = denominator11 * numerator12
                IF den EQUALS 0 THEN
                    OUTPUT "Invalid input."
                ELSE
                    OUTPUT num CONCATENATED WITH "/" CONCATENATED WITH den
                END IF
            END IF

        ELSE
            OUTPUT "Error: Input doesn't contain spaces."
        END IF
    END WHILE
END FUNCTION
*/
