#include<iostream>

struct Fish {
  int fishNonCooked;
  int fishCookedTimes;
  int fishCooked;
};

void FireTimes(Fish* fish, const int FireForce) 
{
  fish->fishCookedTimes = (int)(fish->fishNonCooked / FireForce);
  fish->fishCooked = fish->fishCookedTimes * FireForce;

  std::cout << "Cooked fish Times: " << fish->fishCookedTimes << std::endl;
  std::cout << "Cooked fish: " << fish->fishCooked << std::endl;
}

int main() {
  
  Fish fishnc{};
  int FireForce = 5;

  std::cout << "Enter the number of non-cooked fish: ";
  std::cin >> fishnc.fishNonCooked;

  FireTimes(&fishnc,FireForce);

}