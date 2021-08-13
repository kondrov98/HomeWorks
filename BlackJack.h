#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

namespace BlackJack
{
    
    //namespace
    using namespace std;

    //Type

	enum class  s { Hearts, Tambourin, Clubs, Peak };
	enum class m { A = 1, two, tree, four, five, six, seven, eight, nine, ten, Valet, Quin, King };


    //class

   
    class Card
    {


    private:
        s suit;
        m meaning;
        bool position;

    public:
        Card(s c_suit, m c_meaning, bool c_position) : suit(c_suit), meaning(c_meaning), position(c_position)
        {

        }

        void Flip()
        {
                position = !position;
        }

        m GetValue() const
        {
            if (meaning == m::Valet)
                return m::ten;
            if (meaning == m::Quin)
                return m::ten;
            if (meaning == m::King)
                return m::ten;
            return meaning;
        }

        friend ostream& operator<<(ostream& out,Card card);
    };


   class Hand
    {
    protected:
        vector <Card*> cards;
    public:

        Hand()
        {
            cards.reserve(7);
        }

        ~Hand()
        {
            Clear();
        }

        void Add(Card* card_m)
        {
            cards.push_back(card_m);
        }
        void Clear()
        {
            vector<Card*>::iterator iter = cards.begin();
            for (iter = cards.begin(); iter != cards.end(); ++iter)
            {
                delete* iter;
                *iter = 0;
            }

            cards.clear();
        }
        short GetValue() const
        {
            short summ = 0;
            for (short i = 0; i < cards.size(); i++)
            {
                if (cards[i]->GetValue() == m::A && summ < 11)
                    summ += 11;
                else
                    if(cards[i]->GetValue() == m::Valet|| cards[i]->GetValue() == m::Quin || cards[i]->GetValue() == m::King)
                        summ += 10;
                    else
                        summ += static_cast<short>(cards[i]->GetValue());
            }
            return summ;
        }

    };

    class GenericPlayer: public Hand
    {
    protected:
        string name;
    public:
        virtual bool IsHitting()
        {
            if (GetValue()<=21)
            {
                cout << "Message for " << name << ": you can take a card!\n";
                return true;
            }
            else
                return false;
        }

        bool IsBoosted()
        {

            if (GetValue() > 21)
                return true;
            else
                return false;
        }

        void Bust()
        {
            cout << "The player " << name << " has too many cards.\n";
        }
        friend ostream& operator<<(ostream& out, GenericPlayer GenericPlayer);
    };

    class Player : public GenericPlayer
    {
        private:

        public:

            Player(const string& name1="") 
            {
                name = name1;
            }

            virtual ~Player()
            {

            }

            bool IsHitting() const
            {         
                    char a;
                    cout << "Do you need another card?\n ";
                    while (true)
                    {
                        cout << "Y / N:\n";
                        cin >> a;
                        if (a == 'Y')
                            return true;
                        else
                            if (a == 'N')
                                return false;
                            else
                            {
                                while (cin.get()!='\n')
                                    cin.clear();
                                cerr << "Incorrect input!\n";
                            }
                    }

            }

            void Win() const
            {
                cout << "The player: " << name << " won!\n";
            }

            void Lose() const
            {
                cout << "The player: " << name << " lose!\n";
            }

            void Push() const
            {
                cout << "The player: " << name << " drew!\n";
            }
    };

    class House: public GenericPlayer
    {
    private:

    public:
        virtual bool IsHitting() const
        {
            if (GetValue() <= 16)
            {
                cout << "The dealer: " << name << " can take a card!\n";
                return true;
            }
            else
                return false;

        }

        void FlipFirstCard()
        {
            cards[0]->Flip();
        }
    };
    
    class Deck :public Hand
    {
    private:
        
    public:
        void Populate()
        {
            Clear();
            for (short si = static_cast<short>(s::Hearts); si <= static_cast<short>(s::Peak); ++si)
            {
                for (short mi = static_cast<short>(m::A); mi <= static_cast<short>(m::King); ++mi)
                {
                    Add(new Card(static_cast<s>(si), static_cast<m>(mi), false));
                }
            }


        }

        void Shuffle()
        {
            random_shuffle(cards.begin(), cards.end());
        }

        void Deal(Hand& aHand)
        {
            if (!cards.empty())
            {
                aHand.Add(cards.back());
                cards.pop_back();
            }
            else
            {
                cout << "Out of cards. Unable to deal.";
            }

        }

        void AdditionalCards(GenericPlayer& aGenericPlayer)
        {
            cout << endl;
            // продолжает раздавать карты до тех пор, пока у игрока не случается
            // перебор или пока он хочет взять еще одну карту
            while (!(aGenericPlayer.IsBoosted()) && aGenericPlayer.IsHitting())
            {
                Deal(aGenericPlayer);
                cout << aGenericPlayer << endl;

                if (aGenericPlayer.IsBoosted())
                {
                    aGenericPlayer.Bust();
                }
            }

        }

        Deck()
        {
            cards.reserve(52);
            Populate();
        }
    };

    class Game
    {
    private:
        Deck m_Deck;
        House m_House;
        vector<Player> m_Players;

    public:
        Game(const vector<string>& names)
        {
            // создает вектор игроков из вектора с именами
            vector<string>::const_iterator pName;
            for (pName = names.begin(); pName != names.end(); ++pName)
            {
                m_Players.push_back(Player(*pName));
            }

            // запускает генератор случайных чисел
            srand(static_cast<unsigned int>(time(0)));
            m_Deck.Populate();
            m_Deck.Shuffle();
        }

        ~Game()
        {

        }

        // проводит игру в Blackjack
        void Play()
        {
            {
                // раздает каждому по две стартовые карты
                vector<Player>::iterator pPlayer;
                for (int i = 0; i < 2; ++i)
                {
                    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
                    {
                        m_Deck.Deal(*pPlayer);
                    }
                    m_Deck.Deal(m_House);
                }

                // прячет первую карту дилера
                m_House.FlipFirstCard();

                // открывает руки всех игроков
                for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
                {
                    cout << *pPlayer << endl;
                }
                cout << m_House << endl;

                // раздает игрокам дополнительные карты
                for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
                {
                    m_Deck.AdditionalCards(*pPlayer);
                }

                // показывает первую карту дилера
                m_House.FlipFirstCard();
                cout << endl << m_House;

                // раздает дилеру дополнительные карты
                m_Deck.AdditionalCards(m_House);

                if (m_House.IsBoosted())
                {
                    // все, кто остался в игре, побеждают
                    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
                    {
                        if (!(pPlayer->IsBoosted()))
                        {
                            pPlayer->Win();
                        }
                    }
                }
                else
                {
                    // сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
                    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
                        ++pPlayer)
                    {
                        if (!(pPlayer->IsBoosted()))
                        {
                            if (pPlayer->GetValue() > m_House.GetValue())
                            {
                                pPlayer->Win();
                            }
                            else if (pPlayer->GetValue() < m_House.GetValue())
                            {
                                pPlayer->Lose();
                            }
                            else
                            {
                                pPlayer->Push();
                            }
                        }
                    }

                }

                // очищает руки всех игроков
                for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
                {
                    pPlayer->Clear();
                }
                m_House.Clear();
            }
        }

   
    };


    


    //Friend functions

    ostream& operator<<(ostream& out, Card card)
    {
        if (!card.position)
            out << "XX\n";
        else
        {
            switch (card.suit) 
            {
            case s::Hearts: out << "Hearts\n";
            case s::Tambourin: out << "Tambourin\n";
            case s::Clubs: out << "Clubs\n";
            case s::Peak: out << "Peak\n";
            }
            
            switch (card.meaning)
            {
            case m::A: out << "A\n";
            case m::two: out << "2\n";
            case m::tree: out << "3\n";
            case m::four: out << "4\n";
            case m::five: out << "5\n";
            case m::six: out << "6\n";
            case m::seven: out << "7\n";
            case m::eight: out << "8\n";
            case m::nine: out << "9\n";
            case m::ten: out << "10\n";
            case m::Valet: out << "Valet\n";
            case m::Quin: out << "Quin\n";
            case m::King: out << "King\n";
            }

            
        }
        return out;
    }

    ostream& operator<<(ostream& out, GenericPlayer GenericPlayer)
    {
        out << "Name: " << GenericPlayer.name << "\n";
        out << "Cards: ";
        for (int i = 0; i < GenericPlayer.cards.size(); i++)
        {
            switch (GenericPlayer.cards[i]->GetValue())
            {
            case m::A: out << "A ";
            case m::two: out << "2 ";
            case m::tree: out << "3 ";
            case m::four: out << "4 ";
            case m::five: out << "5 ";
            case m::six: out << "6 ";
            case m::seven: out << "7 ";
            case m::eight: out << "8 ";
            case m::nine: out << "9 ";
            case m::ten: out << "10 ";
            case m::Valet: out << "Valet ";
            case m::Quin: out << "Quin ";
            case m::King: out << "King ";
            }
        }
        out << "\nNumber of points: " << GenericPlayer.GetValue() << "\n";
        
    }


}

