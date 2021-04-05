#include <iostream>
#include <cstring>

const unsigned NAME_SIZE        = 129;
const unsigned MAX_ACCOUNT_SIZE = 1024;
const double PERCENT_OF_INCOME  = 0.25;

enum Status{blocked, active};

class Credit{
private:
    unsigned withdrawn;
    unsigned paid;
    unsigned monthlyPayment;

public:
    Credit() {
        withdrawn      = 0;
        paid           = 0;
        monthlyPayment = 0;
    }

    Credit(unsigned withdrawn, unsigned paid, unsigned monthlyPayment) {
        this->withdrawn      = withdrawn;
        this->paid           = paid;
        this->monthlyPayment = monthlyPayment;
    }

    void print() const{
        std::cout << "Credit: "          << std::endl 
                  << "Withdrawn: "       << withdrawn      << " "
                  << "Paid: "            << paid           << " "
                  << "Monthly Payment: " << monthlyPayment << std::endl;
    }

    unsigned getWithdrawn() const{
        return withdrawn;
    }

    unsigned getPaid() const{
        return paid;
    }

    void setWithdrawn(unsigned withdrawn) {
        this->withdrawn = withdrawn;
    }

    void setPaid(unsigned paid) {
        this->paid = paid;
    }

    void setMonthlyPayment(unsigned monthlyPayment) {
        this->monthlyPayment = monthlyPayment;
    }
};

class BankAccount{
private:
    char name[NAME_SIZE];
    unsigned age;
    Status status;
    unsigned amount;
    unsigned income;
    Credit credit;
    unsigned id;

public:
    BankAccount() {
       name[0] = '\0';
       age     = 18;
       status  = active;
       amount  = 0;
       income  = 0;
       id      = 0;
    }

    BankAccount(const char* name, unsigned age, unsigned amount, unsigned income) {
        strcpy(this->name, name);

        if(age < 18)
            this->status = blocked;
        else    
            this->status = active;
            
        this->age    = age;
        this->amount = amount;
        this->income = income;
        this->id     = 0;
    }

    const char* getName() const{
        return name;
    }

    unsigned getAge() const{
        return age;
    }

    Status getStatus() const{
        return status;
    }

    unsigned getAmount() const{
        return amount;
    } 

    Credit getCredit() const{
        return credit;
    }

    unsigned getId() const{
        return id;
    }

    void setName(const char* name) {
        strcpy(this->name, name);
    }

    void setAge(unsigned age) {

        if(age < 18)
            setStatus(blocked);

        this->age = age;
    }

    void setStatus(Status status) {
        this->status = status;
    }

    void setId(unsigned id) {
        this->id = id;
    }

    void deposit(unsigned sum) {
        amount += sum;
    }

    bool withdraw(unsigned sum) {

        if(sum > amount)
            return 0;
        
        amount -= sum;
        return 1;
    }

    void takeCredit(unsigned withdrawn, unsigned paid, unsigned monthlyPayment) {
        credit.setWithdrawn(withdrawn);
        credit.setPaid(paid);
        credit.setMonthlyPayment(monthlyPayment);
    }

    void print() const{
        std::cout << "Name: "   << name   << std::endl
                  << "Age: "    << age    << std::endl
                  << "Amount: " << amount << std::endl
                  << "Income: " << income << std::endl
                  << "ID: "     << id     << std::endl;

        std::cout << "Status: ";

        if(status == active)
            std::cout << "active";
        else 
           std::cout << "blocked";

        std::cout << std::endl;

        credit.print();
    }
};

class Bank{
private:
    BankAccount accounts[MAX_ACCOUNT_SIZE];
    unsigned count;
    unsigned bankAmount;
    //new
    unsigned accountsAdded;

public:
    Bank() {
        count         = 0;
        bankAmount    = 0;
        accountsAdded = 0;
    }

    Bank(unsigned bankAmount) {
        this->count          = 0;
        this->bankAmount     = bankAmount;
        this-> accountsAdded = 0;
    }

    bool addAccount(const BankAccount& account) {

        if(count == MAX_ACCOUNT_SIZE)
            return 0;

        accounts[count] = account;
        accounts[count].setId(accountsAdded);
        accountsAdded++;

        if(account.getAge() < 18)
            accounts[count].setStatus(blocked);

        count++;
        return 1;
    }

    //new
    bool deleteAccount(unsigned id) {

        for(int i = 0; i < count; i++) {
            if(accounts[i].getId() == id) {
                std::swap(accounts[i], accounts[count - 1]);
                count--;
                return 1;
            }

            return 0;
        }
    }

    void blockUnusedAccounts() {

        for(int i = 0; i < count; i++) {
            if(accounts[i].getAmount() == 0)
                accounts[i].setStatus(blocked);
        }
    }

    void printAccounts() const{

        for(int i = 0; i < count; i++) {
            accounts[i].print();
        }
    }

    bool check(unsigned id) {

        for(int i = 0; i < count; i++){
            if(accounts[i].getId() == id) {

                unsigned withdrawn = accounts[i].getCredit().getWithdrawn();
                unsigned paid      = accounts[i].getCredit().getPaid();

                return (accounts[i].getStatus() == active && (withdrawn == 0 || withdrawn == paid));
            }
        }
    }

    bool takeCredit(unsigned id, unsigned amount) {

        if(!check(id))
            return false;
        
        if(amount <= bankAmount) {
            for(int i = 0; i < count; i++) {
                if(accounts[i].getId() == id) {
                    accounts[i].takeCredit(amount, 0, amount * PERCENT_OF_INCOME);
                    return true;
                }
            }
        }
    }
    
};


int main() {

    return 0;
}