#include<iostream>
#include"task4.h"
#include<windows.h>
#include<vector>
#include<set>
#include"myLib.h"
#include"task4.1.h"

using namespace std;
using namespace myLib;



Rank operator++(Rank& den) { return den = (Rank)(std::underlying_type<Rank>::type(den) + 1); };
Rank operator*(Rank den) { return den; };
Rank begin(Rank den) { return Rank::first; };
Rank end(Rank den)
{
	Rank de = Rank::last;
	return ++de;
};

Suit operator++(Suit& suit) { return suit = (Suit)(std::underlying_type<Suit>::type(suit) + 1); };
Suit operator*(Suit suit) { return suit; };
Suit begin(Suit suit) { return Suit::first; };
Suit end(Suit suit)
{
	Suit su = Suit::last;
	return ++su;
};


Card::Card(Rank r, Suit s, bool ifu) : suit(s), rank(r), isFaceUp(ifu), isStayedInTheDeck{ true }
{};

void Card::SetValue(Rank den, Suit suit)
{
	rank = den;
	this->suit = suit;
};

uint16_t Card::GetValue() const
{
	uint16_t val = 0;
	if (isFaceUp)
	{
		val = std::underlying_type<Rank>::type(rank);
		if (val > 10) val = 10;
	}
	return val;
};

Deck::Deck()
{
	for (const auto& i : Suit())
	{
		for (const auto& j : Rank())
		{
			cards[(int)i - 1][(int)j - 1].SetValue(j, i);
		}
	}
}

Game::Game(const std::vector<std::string>& names)
{
}

void Game::Play()
{
}

Hand::Hand()
{
	cards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	cards.push_back(pCard);
}

void Hand::Clear()
{
	for (auto cr : cards)
	{
		delete cr;
	}
	cards.clear();
}

uint16_t Hand::GetTotal() const
{
	
	if (cards.empty())
	{
		return 0;
	}
	
	if (cards[0]->GetValue() == 0)
	{
		return 0;
	}
	
	uint16_t total = 0;
	for (auto cr : cards)
	{
		total += cr->GetValue();
	}
	
	bool containsAce = false;
	for (auto cr : cards)
	{
		if (cr->GetValue() == static_cast<uint16_t>(Rank::ACE)) containsAce = true;
	}
	
	if (containsAce && total <= 11)
	{
		
		total += 10;
	}
	return total;
}

GenericPlayer::GenericPlayer(const std::string& name) : name(name)
{}
bool GenericPlayer::IsBoosted() const
{
	return (GetTotal() > 21);
}
void GenericPlayer::Bust() const
{
	std::cout << name << " перебор" << std::endl;
}

bool House::IsHitting() const
{
	return false;
}

int main() 
{
	
	setlocale(LC_ALL, "RU");

	cout << "\t\tСыграем в Blackjack!\n\n" << endl << endl;
	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "На сколько игроков раздаем? (1 - 7): ";
		numPlayers = getUserInput<uint16_t>();
	}
	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Введите имя " << i + 1 << " игрока: ";
		name = getUserInputTxt();
		names.push_back(name);
	}
	cout << endl;
	// игровой цикл
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		cout << "\nХотите сыграть заново? (Y/N): ";
		cin >> again;
	}

}