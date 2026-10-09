#include <iostream>

struct PiggyBank
{
    int rubles;
    int coins;
};

struct AddMoney
{
    int rubles;
    int coins;
};

void add_money(PiggyBank* bank, AddMoney deposit)
{
    int totalCoins{ bank->coins + deposit.coins };
    bank->rubles += deposit.rubles + totalCoins / 100;
    bank->coins = totalCoins % 100;
}

int main()
{
    PiggyBank bank{};
    AddMoney deposit{};

    std::cout << "How much is in the piggy bank (rubles | coins): ";
    std::cin >> bank.rubles >> bank.coins;

    std::cout << "How much to add (rubles | coins): ";
    std::cin >> deposit.rubles >> deposit.coins;

    add_money(&bank, deposit);

    std::cout << "In the piggy bank:" << bank.rubles << " rubles and " << bank.coins << " kopecks" << std::endl;
}
