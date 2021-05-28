#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;
struct Card {
    string suit;
    string num;
    Card() {};
    Card(string a, string b ):suit(a),num(b) {}
};
void fill_deck_of_cards(Card *deck_of_cards,string *just_suit,string *just_num, bool *deck_empty)
{
    int index_deck = 0;
    for (int y=0; y<4; y++) {
        for (int x=0; x<9; x++) {
            deck_of_cards[index_deck] = Card(just_suit[y], just_num[x]);
            index_deck++;
        }
    }
    *deck_empty = false;

}
void print_deck_of_cards(Card* deck_of_cards, bool deck_empty)
{

    if (deck_empty == true) {
        cout<<"Колода пуста"<<endl;
    } else {
        cout<<"--Колода-карт--"<<endl;
        for (int i=0; i<36; i++) {
            cout<<i+1<<") "<<deck_of_cards[i].suit+deck_of_cards[i].num<<endl;
        }
        cout<<"---------------"<<endl;
    }
}
void find_queen_of_spades(Card* deck_of_cards)
{
    bool queen = false;
    for (int i=0; i<36; i++) {
        if ((deck_of_cards[i].suit == "♠") && (deck_of_cards[i].num == "Q")) {
            cout<<"Она находится на "<< i + 1<<" позиции."<<endl;
            queen = true;
        }
    }
    if (!queen) cout<<"Дамы пик тут нет."<<endl;
}
void find_ace(Card* deck_of_cards)
{

    bool ace = false;
    for (int i=0; i<36; i++) {
        if (deck_of_cards[i].num == "T") {
            cout<<"Нашёлся туз:"<<deck_of_cards[i].suit+deck_of_cards[i].num<<". На "<< i + 1 <<" позиции."<<endl;
            ace = true;
        }
    }
    if (!ace) cout<<"Тузов в колоде не наблюдается."<<endl;
}
void shuffle_deck(Card* deck_of_cards, bool *deck_empty)
{
    srand(time(0));
    random_shuffle(deck_of_cards, deck_of_cards+36);
}

void find_suit(Card* deck_of_cards)
{
    cout<<"Рядом стоящие карты с одинаковой мастью:"<<endl;
    for (int i=0; i<35; i++) {
        if (deck_of_cards[i].suit == deck_of_cards[i+1].suit) {
            cout<<deck_of_cards[i].suit+deck_of_cards[i].num<< " : "<<deck_of_cards[i+1].suit+deck_of_cards[i+1].num<<endl;
        }
    }
    cout<<"--------------"<<endl;
}
void find_num(Card* deck_of_cards)
{
    cout<<"Рядом стоящие карты с одинаковым номиналом:"<<endl;
    for (int i=0; i<35; i++) {
        if (deck_of_cards[i].num == deck_of_cards[i+1].num) {
            cout<<deck_of_cards[i].suit+deck_of_cards[i].num<< " : "<<deck_of_cards[i+1].suit+deck_of_cards[i+1].num<<endl;
        }
    }
    cout<<"--------------"<<endl;
}

int main(int argc, char **argv)
{
    string just_suit[4] = {"♦","♥","♠","♣"};
    string just_num[9] = {"T","K","Q","J","10","9","8","7","6"};
    bool deck_empty = true;
    Card deck_of_cards[36] = {};
    unsigned n;
    do {
        cout<<"1 - заполнить\t2 - перемешать\t3 - вывести,\n4 - найти по масти\t5 - найти по номиналу\n6 - найти тузы\t7 найти даму пик\t8 - выйти"<<endl;
        cin>>n;
        if (n == 1) {
            fill_deck_of_cards(deck_of_cards, just_suit, just_num, &deck_empty);
        }
        if (n == 2) {
            shuffle_deck(deck_of_cards,&deck_empty );
        }
        if (n == 3) {
            print_deck_of_cards(deck_of_cards, deck_empty);
        }
        if (n == 4) {
            find_suit(deck_of_cards);
        }
        if (n == 5) {
            find_num(deck_of_cards);
        }
        if (n == 6) {
            find_ace(deck_of_cards);
        }
        if (n == 7) {
            find_queen_of_spades(deck_of_cards);
        }
    } while(n!=8);
    return 0;
}