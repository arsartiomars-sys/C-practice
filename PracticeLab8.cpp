#include <iostream>

struct Prices {
    int drink;
    int first;
    int second;
};

struct Choices { // (Client)
    int drink;
    int first;
    int second;
};

int customerTotal(Prices prices, Choices choices)
{
    return choices.drink * prices.drink + choices.first * prices.first + choices.second * prices.second;
}

struct ClientName {
    int index;
};

std::ostream& operator<<(std::ostream& s, ClientName name) {
    std::cout << "Client " << name.index;
    return s;
}

void PriceInfo(Prices* prices) {

    std::cout << "Your price for Drink: ";
    std::cin >> prices->drink;
    std::cout << "Your price for First: ";
    std::cin >> prices->first;
    std::cout << "Your price for Second: ";
    std::cin >> prices->second;
}

void ClientChoiseInfo(Choices* choise, ClientName name) {
    std::cout << name << " drink: ";
    std::cin >> choise->drink;

    std::cout << name << " first: ";
    std::cin >> choise->first;

    std::cout << name << " second: ";
    std::cin >> choise->second;
}

void FullClientOperation(Prices pr, int* x)
{
    Choices client{};
    ClientName name{ *x };
    ClientChoiseInfo(&client, name);
    std::cout << std::endl;
    int total = customerTotal(pr, client);
    std::cout << name << " total: " << total << std::endl;
    (*x) += 1;
}

int main()
{
    int i = 0;
    Prices prices{};
    PriceInfo(&prices);
    std::cout << std::endl;

    FullClientOperation(prices, &i);
    FullClientOperation(prices, &i);

    //{
    //    Choices client{ 0,0,0 };
    //    ClientChoiseInfo(&client);
    //    std::cout << std::endl;
    //    int total = customerTotal(prices, client);
    //    std::cout << "Client 1 total: " << total << std::endl;
    //}
    //{
    //    Choices client{ 0,0,0 };
    //    ClientChoiseInfo(&client);
    //    std::cout << std::endl;
    //    int total = customerTotal(prices, client);
    //    std::cout << "Client 2 total: " << total << std::endl;
    //}

}