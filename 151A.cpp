#include <algorithm>
#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int person, bottle, litter, lime, limecut, salt, perdrink, persalt;
    std::cin >> person >> bottle >> litter >> lime >> limecut >> salt >> perdrink >> persalt;
    int drinkserving = (bottle*litter)/perdrink;
    int limeserving = lime*limecut;
    int saltserving = salt/persalt;
    int serving = std::min(drinkserving, std::min(limeserving, saltserving));
    std::cout << serving/person;
    return 0;
}