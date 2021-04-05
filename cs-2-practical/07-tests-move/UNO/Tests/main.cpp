#define CATCH_CONFIG_MAIN

#include "catch2.h"
#include "Game.h"


TEST_CASE("Normal and Special Card tests") {
    srand(time(0));
    Card card(COLOR::GREEN, 7);
    REQUIRE(card.getColor() == COLOR::GREEN);
    REQUIRE(card.getNumber() == 7);
    card.changeColor(COLBLUE);
    REQUIRE(card.getColor() == COLOR::BLUE);
    card.generateRandom(); // Generating normal card
    REQUIRE(card.getNumber() > 0);
    REQUIRE(card.getNumber()<10);
    REQUIRE(card.getColor() != COLOR::UNKNOWN);
    card.generateRandomSpecial(); // generating special card
    REQUIRE(card.getNumber()>9);
    REQUIRE(card.getNumber()<14);
    REQUIRE(card.getColor() != COLOR::UNKNOWN);
    Card card1(card.getColor(), card.getNumber());
    REQUIRE(card == card1);
    card1.generateRandom();//generating non special card
    REQUIRE(card != card1);
}

TEST_CASE("Deck tests") {
    srand(time(0));
    Deck deck(20);
    REQUIRE(deck.getSize()==20);
    REQUIRE(deck.getTopCard().getNumber()<10);
    deck.shuffleDeck();
    REQUIRE(deck.getCurDeckSize()==20);
    Card card = deck.getTopCardAndRemoveIt();
    REQUIRE(deck.getCurDeckSize()==19);
    Card card1 = deck.getTopCard();
    REQUIRE(card1==deck.getTopCardAndRemoveIt());
    Deck deck1(2);
    deck1.getTopCardAndRemoveIt();deck1.getTopCardAndRemoveIt();
    REQUIRE(deck1.getCurDeckSize()==0);
    REQUIRE_THROWS_AS(deck1.getTopCardAndRemoveIt(),std::range_error);
}

TEST_CASE("Player tests") {
    Player player(8);
    REQUIRE(player.getHandSize()==8);
    player.removeCard(player.getCard(0));
    REQUIRE(player.getHandSize()==7);
    Deck deck(10);
    player.drawCard(deck);
    REQUIRE(player.getCard(7).getNumber()>0);
    REQUIRE(player.getCard(7).getColor()!=COLOR::UNKNOWN);
    REQUIRE(deck.getCurDeckSize()==9);
    REQUIRE(player.getHandSize()==8);
    player.drawCard(deck);player.drawCard(deck);
    REQUIRE(player.getHandSize()==10);
    player.drawCard(deck);
    REQUIRE(player.getHandSize()==10);
}

TEST_CASE("Game tests") {
    Game g(3,30);
    REQUIRE(g.getPlayer(0).getHandSize()==4);
    SECTION("Getting invalid player") {
        REQUIRE_THROWS_AS(g.getPlayer(3), std::range_error);
        REQUIRE_THROWS(g.getPlayer(5));
    }
    //g.play();
}