#include "LimitedDeck.hpp"
#include "MapGeneratorV1.hpp"
#include "Player.hpp"
#include "Points.hpp"
#include <cstdint>
#include <iostream>

int main()
{
    /*
    Fight fight;
    */
    Player p1(100, 100, 10, 5, 5);

    auto mapa = MapGeneratorV1::generate(10, 10);
    mapa.updateVisilibity(Position(1, 1));
    std::cout << mapa.getMapToPrint(Position(1, 1));
    std::cout << "Kaczka!" << std::endl;
    return 0;
}
