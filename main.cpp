#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Game {
    string title;
    string genre;
    string platform;
    int price;
};

struct Baskets {
    string title; 
    int quantity;
};

void addGame(vector<Game>& games, vector<Baskets>& basket, string title, int quantity) {
    for (const auto& game : games) {
        if (game.title == title) {
            for (auto& item : basket) {
                if (item.title == title) {
                    item.quantity += quantity;
                    return;
                }
            }
            int totalCost = game.price * quantity;
            basket.push_back({title, quantity});
            cout << "Игра добавлена в корзину." << endl;
            cout << "Стоимость заказа: " << totalCost << endl;
            return;
        }
    }
    cout << "Игра не найдена." << endl;
}
int main() {
  vector<Game> games = {
    {"Red dead Redemption 2", "RPG", "PC", 2990},
    {"The Last Of Us 2", "Adventure", "PS4", 2490},
    {"GTA 5", "Adventure", "PC", 1490},
    {"Euro Truck Simulator 2", "Drive", "PC", 1149},
    {"Raft", "Survival", "PC", 390},
    {"Subnautica", "Survival", "PC", 890},
    {"BeamNG Drive", "Drive", "PC", 849},
    {"Garrys Mod", "", "PC", 749},
    {"CupHead", "adventure", "PC", 249},
    {"Phasmofobia", "Survival", "PC", 349},
    {"PayDay 2", "Adventure", "PC", 249},
    {"Portal 2", "Drive", "PC", 285},
    {"Car For Sale Simulator", "Simulator", "PC", 329},
    {"Hearts Of Iron 4", "Simulator", "PC", 1749},
    {"Mafia 2", "Adventure", "PC", 549},
    {"Assasins Creed 2", "Adventure", "PC", 1649},
    {"S.T.A.L.K.E.R", "Adventure", "PC", 849},
    {"The Witcher 3", "Adventure", "PC", 2990},
    {"BattleField 3", "MMO", "PC", 1590},
    {"Metro 2033", "Adventure", "PC", 1390},
    {"Mortal Kombat X", "fight", "PC", 1190},
    {"Left 4 Dead 2", "adventure", "PC", 290},
    {"Half Life 2", "Adventure", "PC", 190}
  };
  for (int i = 0; i < games.size(); i++) {
    cout << i + 1 << ". " << games[i].title << endl;
  }
    vector<Baskets> basket;

    string userTitle;
    int userQuantity;

    cout << "Введите название игры: ";
    cin >> userTitle;
    cout << "Введите количество: ";
    cin >> userQuantity;

    addGame(games, basket, userTitle, userQuantity);

    return 0;
}