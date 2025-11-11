#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define INPUT_MAX 50

// CPF (Brazilian Individual Taxpayer) constants
#define CPF_LEN 11
#define CPF_WEIGHT1 10
#define CPF_WEIGHT2 11

// CNPJ (Brazilian Corporate Taxpayer) constants
#define CNPJ_LEN 14
#define CNPJ_WEIGHT1 {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}
#define CNPJ_WEIGHT2 {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}


// --- ANSI Color Codes ---
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

// --- Function Prototypes ---
void checkCPF(char cpf[]);
void checkCNPJ(char cnpj[]);
void extractDigits(char *input);
void clearScreen();
void Printbanner();

/**
 * @brief Main program entry point.
 */
int main() {
    clearScreen();
    Printbanner();

    char document[INPUT_MAX] = {0};

    printf(CYAN "Enter the CPF or CNPJ: " RESET);
    scanf("%49s", document);
    printf("\n");

    extractDigits(document);

    int length = strlen(document);

    if (length == CPF_LEN) 
        checkCPF(document);
    else if (length == CNPJ_LEN)
        checkCNPJ(document);
    else
        printf(RED BOLD "Invalid option!\n" RESET);

    return 0;
    
}

/**
 * @brief Validates an 11-digit CPF number.
 * @param cpf A string containing 11 digits.
 */
void checkCPF(char cpf[]) {

    bool is_digit1 = false;
    bool is_digit2 = false;

    int length;
    int valor;
    int peso;
    int resto;

    // First Digit Check
    length = CPF_LEN - 2;

    valor = 0;
    peso = CPF_WEIGHT1;
    
    for (int i = 0; i < length; i++, peso--) {
        valor += (cpf[i] - '0') * peso; // Convert char digit to int
    }

    resto = valor % 11;
    int digit1 = (resto < 2) ? 0 : 11 - resto;
    
    if (digit1 == (cpf[9] - '0'))
        is_digit1 = true;

    // Second Digit Check
    length = CPF_LEN - 1;

    valor = 0;
    peso = CPF_WEIGHT2;

    for (int i = 0; i < length; i++, peso--) {
        valor += (cpf[i] - '0') * peso;
    }

    resto = valor % 11;
    int digit2 = (resto < 2) ? 0 : 11 - resto;

    if (digit2 == (cpf[10] - '0'))
        is_digit2 = true;

    if (is_digit1 && is_digit2)
        printf(GREEN BOLD "Valid CPF!\n" RESET);
    else
        printf(RED BOLD "Invalid CPF!\n" RESET);

}

/**
 * @brief Validates a 14-digit CNPJ number.
 * @param cnpj A string containing 14 digits.
 */
void checkCNPJ(char cnpj[]) {
    bool is_digit1 = false;
    bool is_digit2 = false;

    int length;
    int valor;
    int resto;

    // First Digit Check
    length = CNPJ_LEN - 2;

    valor = 0;
    int peso1[] = CNPJ_WEIGHT1;

    for (int i = 0; i < length; i++) {
        valor += (cnpj[i] - '0') * peso1[i];
    }

    resto = valor % 11;
    int digit1 = (resto < 2) ? 0 : 11 - resto;

    if (digit1 == (cnpj[12] - '0'))
        is_digit1 = true;

    // Second Digit Check
    length = CNPJ_LEN - 1;

    valor = 0;
    int peso2[] = CNPJ_WEIGHT2;

    for (int i = 0; i < length; i++) {
        valor += (cnpj[i] - '0') * peso2[i];
    }

    resto = valor % 11;
    int digit2 = (resto < 2) ? 0 : 11 - resto;

    if (digit2 == (cnpj[13] - '0'))
        is_digit2 = true;

    if (is_digit1 && is_digit2)
        printf(GREEN BOLD "Valid CNPJ!\n" RESET);
    else
        printf(RED BOLD "Invalid CNPJ!\n" RESET);

}

/**
 * @brief Sanitizes a string in-place, keeping only digit characters.
 * @param input The string to sanitize.
 */
void extractDigits(char *input) {
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9')
            input[j++] = input[i]; 
    }
    input[j] = '\0'; // Null-terminate the sanitized string
    
}

/**
 * @brief Clears the terminal screen using platform-specific commands.
 */
void clearScreen() {
    // Platform-specific screen clearing
    #if defined(_WIN32)
        system("cls");
    #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
        system("clear");
    #endif
    
}

/**
 * @brief Prints the ASCII art application banner.
 */
void Printbanner() {
    printf(CYAN BOLD
        "    ______/ /             __   ____  ____       \n"
        "   / ____/ /_  ___  _____/ /__/ __ )/ __ '      \n"
        "  / /   / __ '/ _ '/ ___/ //_/ __  / /_/ /      \n"
        " / /___/ / / /  __/ /__/ ,< / /_/ / _, _/       \n"
        " '____/_/ /_/'___/'___/_/|_/_____/_/ |_|        \n"
        "===========================================     \n"
        "        CheckBR - Document Validator            \n"
        "===========================================     \n" 
        "\n"
    RESET);
        
}


