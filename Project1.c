#include <stdio.h>
#include <stdlib.h>

// Function declarations
void checkBalance(float balance);
float deposit();
float withdraw(float balance);

int main() {
    float balance = 1000.0;  // initial balance
    int choice;
    int pin, enteredPin;

    // Simple PIN system
    pin = 1234;
    printf("\n===== Welcome to Mini ATM =====\n");
    printf("Enter your PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Incorrect PIN! Access Denied.\n");
        return 0;
    }

    printf("Login successful \n");

    do {
        printf("\n===== ATM Menu =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance += deposit();
                printf("Deposit successful!\n");
                checkBalance(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

// Function to check balance
void checkBalance(float balance) {
    printf("Your current balance is: Rs.%.2f\n", balance);
}

// Function to deposit money
float deposit() {
    float amount;
    printf("Enter amount to deposit: Rs.");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return 0;
    }
    return amount;
}

// Function to withdraw money
float withdraw(float balance) {
    float amount;
    printf("Enter amount to withdraw: Rs.");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
    } else if (amount > balance) {
        printf("Insufficient balance!\n");
    } else {
        balance -= amount;
        printf("Withdrawal successful!\n");
        checkBalance(balance);
    }

    return balance;
}

