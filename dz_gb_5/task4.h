﻿#pragma once
#include <type_traits>
#include<string>
#include<vector>
//#include<stdint.h>

class GenericPlayer;

//Колода

enum class Rank
{

	ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING,
	first = ACE,
	last = KING
};

enum class Suit
{
	CLUBS = 1,	//♣️
	DIAMONDS,	//♦️
	HEARTS,		//♥️
	SPADES,		//♠️
	first = CLUBS,
	last = SPADES
};

class Card
{
public:
	Card(Rank r = Rank::ACE, Suit s = Suit::SPADES, bool ifu = true);

	void SetValue(Rank den, Suit suit);

	Rank GetRank() { return rank; };
	Suit GetSuit() { return suit; };
	void Flip() { isFaceUp = !isFaceUp; };
	uint16_t GetValue() const;

private:
	Rank rank;
	Suit suit;
	bool isFaceUp;
	bool isStayedInTheDeck;

};

class Hand
{
public:
	Hand();
	virtual ~Hand();

	void Add(Card* pCard);		//Добавляет карту в руку. Добавляет указатель на объект типа Сard в вектор cards
	void Clear();				//Очищает руку от карт. Удаляет все указатели из вектора cards, устраняя все связанные с ними объекты в куче
	uint16_t GetTotal() const;	//Возвращает сумму очков карт руки, присваивая тузу значение 1 или 11 в зависимости от ситуации

private:
	std::vector<Card*> cards;
};

class Deck : public Hand
{
public:
	Deck();

	void Populate();		//Создние колоды
	void Shuffle();			//Тасовка карт
	void Deal(Hand& aHand); //Раздача карт
	void AddltionalCards(GenericPlayer& aGenerlcPlayer); //Раздача дополнительных карт

	Card GetCard(uint16_t number);
	bool CheckIsStayedCard(uint16_t number);

private:
	uint16_t numberOfCards = (int)Suit::last * (int)Rank::last;
	Card cards[(int)Suit::last][(int)Rank::last]{};
};



enum class Chip
{
	White = 1,
	Red = 5,
	Blue = 10,
	Green = 25,
	Black = 100,
	Magenta = 500,
	Orange = 1000,

	count = 7
};

class ChipsOnHand
{
public:

private:
	Chip chips[(int)Chip::count]{};
};



class GenericPlayer : public Hand
{
public:
	GenericPlayer(const std::string& name = "");
	virtual ~GenericPlayer() = default;

	// показывает, хочет ли игрок продолжать брать карты
	virtual bool IsHitting() const = 0;
	// возвращает значение, если у игрока перебор
	bool IsBoosted() const;
	// объявляет, что игрок имеет перебор
	void Bust() const;

private:
	std::string name;

};

class Player : public GenericPlayer
{
public:
	virtual bool IsHitting() const override;
	void Win() const;
	void Lose() const;
	void Push() const;
private:

};

class House : public GenericPlayer
{
public:
	virtual bool IsHitting() const override;
	void FlipFirstCard();
private:


};


class GameEntity
{
public:

private:
	std::string name;
	//int64_t 
};



class Game
{
public:
	Game(const std::vector<std::string>& names);
	void Play();

private:
	Deck deck;
	House house;
	std::vector<Player> players;
};

