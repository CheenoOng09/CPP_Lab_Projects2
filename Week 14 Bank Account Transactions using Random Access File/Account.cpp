#include "Account.h"
#include <string>

using namespace std;

ClientData::ClientData(int accountNumberValue, string lastNameValue, string firstNameValue, double balanceValue) {
    setAccountNumber(accountNumberValue);
    setLastName(lastNameValue);
    setFirstName(firstNameValue);
    setBalance(balanceValue);
}

void ClientData::setAccountNumber(int accountNumberValue) {
    accountNumber = accountNumberValue;
}

int ClientData::getAccountNumber() const {
    return accountNumber;
}

void ClientData::setLastName(string lastNameString) {
    int length = lastNameString.size();
    length = length < 15 ? length : 14;
    lastNameString.copy(lastName, length);
    lastName[length] = '\0';
}

string ClientData::getLastName() const {
    return lastName;
}

void ClientData::setFirstName(string firstNameString) {
    int length = firstNameString.size();
    length = length < 10 ? length : 9;
    firstNameString.copy(firstName, length);
    firstName[length] = '\0';
}

string ClientData::getFirstName() const {
    return firstName;
}

void ClientData::setBalance(double balanceValue) {
    balance = balanceValue;
}

double ClientData::getBalance() const {
    return balance;
}


