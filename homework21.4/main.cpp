#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>

constexpr int gBgSize = 40;
constexpr char* filename = "C:\\skillbox\\profession-c-plus-plus\\homework21.4\\savings.bin";

    enum Way
    {
        WAY_TOP,
        WAY_BOTTOM,
        WAY_LEFT,
        WAY_RIGHT,
        WAY_VARIABLES
    };

    struct Pos
    {
        int y = 0;
        int x = 0;
    };

    struct Character
    {
        bool alive       = true;
        std::string name = "unknown";
        int health       = 0;
        int armor        = 0;
        int damage       = 0;
        Pos position;
    };

    void save(std::vector<Character>& players)
    {
        std::ofstream file(filename, std::ios::binary);
        for (const Character& ch : players)
        {
            int len = ch.name.length();
            file.write((char*)&len, sizeof(len));
            file.write(ch.name.c_str(), len);
            file.write((char*)&ch.alive, sizeof(ch.alive));
            file.write((char*)&ch.health, sizeof(ch.health));
            file.write((char*)&ch.armor, sizeof(ch.armor));
            file.write((char*)&ch.damage, sizeof(ch.damage));
            file.write((char*)&ch.position.x, sizeof(ch.position.x));
            file.write((char*)&ch.position.y, sizeof(ch.position.y));
        }
        file.close();
        std::cout << " Игра была сохранена." << std::endl << std::endl;
    }

    void load(std::vector<Character>& players)
    {
        std::ifstream file(filename, std::ios::binary);
        if (file.is_open())
        {
            std::vector<Character>().swap(players);
            Character ch;
            int len;
            while (file.read((char*)&len, sizeof(len)))
            {
                ch.name.resize(len);
                file.read((char*)ch.name.c_str(), len);
                file.read((char*)&ch.alive, sizeof(ch.alive));
                file.read((char*)&ch.health, sizeof(ch.health));
                file.read((char*)&ch.armor, sizeof(ch.armor));
                file.read((char*)&ch.damage, sizeof(ch.damage));
                file.read((char*)&ch.position.x, sizeof(ch.position.x));
                file.read((char*)&ch.position.y, sizeof(ch.position.y));
                players.push_back(ch);
            }
            file.close();
            std::cout << " Игра была загружена." << std::endl << std::endl;
        }
        else std::cout << " Игра не загружалась." << std::endl;
    }

    void moveTurnBack (Character& character, int way)
    {
        switch (way)
        {
            case WAY_TOP:    ++character.position.y; break;
            case WAY_BOTTOM: --character.position.y; break;
            case WAY_LEFT:   ++character.position.x; break;
            case WAY_RIGHT:  --character.position.x; break;
        }
    }

    bool isCorrectMove (Character& character, int move)
    {
        switch (move)
        {
            case WAY_TOP:    --character.position.y; break;
            case WAY_BOTTOM: ++character.position.y; break;
            case WAY_LEFT:   --character.position.x; break;
            case WAY_RIGHT:  ++character.position.x; break;
        }

        if (character.position.x < 0 || character.position.x >= gBgSize)
        {
            character.position.x += (move == WAY_LEFT) ? 1 : -1;
            return false;
        }
        if (character.position.y < 0 || character.position.y >= gBgSize)
        {
            character.position.y += (move == WAY_TOP)  ? 1 : -1;
            return false;
        }
        return true;
    }

    bool isAttack (Character& characterAttack, Character& characterDefence)
    {
        return (characterDefence.alive &&
                characterAttack.position.x == characterDefence.position.x &&
                characterAttack.position.y == characterDefence.position.y);
    }

    void dealDamage(Character& characterAttack, Character& characterDefence)
    {
        characterDefence.armor -= characterAttack.damage;
        if (characterDefence.armor < 0)
        {
            characterDefence.health += characterDefence.armor;
            characterDefence.armor = 0;
        }
        if (characterDefence.health <= 0)
        {
            characterDefence.health = 0;
            characterDefence.alive = false;
        }
    }

    int enterNumber () {
        bool err = false;
        std::string tmp;
        std::cin >> tmp;
        int number = 0;
        for (int i = 0; i < tmp.length(); ++i)
            if (!isdigit (tmp[i])) err = true;
            if (!err) {
                number = std::stoi(tmp);
            } else {
                std::cout << " Некорректный ввод данных. Попробуйте снова." << std::endl;
                return -1;
            }
        return number;
    }

    Character generateCharacter (int enemyNumber,
                                 const int minHP,    const int maxHP,
                                 const int minArmor, const int maxArmor,
                                 const int minDmg,   const int maxDmg)
    {
        Character character;
        character.name       = "Enemy #" + std::to_string (enemyNumber);
        character.health     = rand() % (maxHP - minHP) + minHP;
        character.armor      = rand() % (maxArmor - minArmor) + minArmor;
        character.damage     = rand() % (maxDmg - minDmg) + minDmg;
        character.position.x = rand() % gBgSize;
        character.position.y = rand() % gBgSize;
        return character;
    }

    void printBattleGround (char(*bg)[gBgSize], std::vector <Character> &players)
    {
        for (int i = 0; i < gBgSize; ++i)
        {
            for (int j = 0; j < gBgSize; ++j) bg[i][j] = '.';
        }
        for (int i = 0; i < players.size(); ++i)
        {
            if (players[i].alive)
            {
                int x = players[i].position.x;
                int y = players[i].position.y;
                bg[y][x] = ((i == 0) ? 'P' : 'E');
            }
        }
        for (int i = 0; i < gBgSize; ++i)
        {
            for (int j = 0; j < gBgSize; ++j) std::cout << bg[i][j] << ' ';
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
    }

    void health_status(std::vector <Character> &players) {
        std::cout << " Состояние здоровья и координаты персонажей:" << std::endl;
        for (int i = 0; i < players.size(); i++) {
            std::cout << "name = " << players[i].name << "\t\t";
            std::cout << "alive = " << players[i].alive << "\t";
            std::cout << "health = " << players[i].health << "\t";
            std::cout << "armor = " << players[i].armor << "\t";
            std::cout << "damage = " << players[i].damage << "\t";
            std::cout << "x = " << players[i].position.x << "\t";
            std::cout << "y = " << players[i].position.y << std::endl;
        }
        std::cout << std::endl;
        return;
    }

    int main()
    {
        system("chcp 65001");
        std::cout << " Реализация ролевой пошаговой игры." << std::endl;
        std::srand(std::time(0));
        char battleGround[gBgSize][gBgSize];
        const int minHealth = 50;
        const int maxHealth = 150;
        const int minArmor = 0;
        const int maxArmor = 50;
        const int minDamage = 15;
        const int maxDamage = 30;
        int tmp;
        std::cout << " Введите имя вашего персонажа: ";
        Character player;
        std::getline(std::cin, player.name);
        std::cout << " Введите максимальное здоровье вашего персонажа (от " << minHealth << " до " << maxHealth << "): ";
        do tmp = enterNumber();
        while (tmp < minHealth || tmp > maxHealth);
        player.health = tmp;
        std::cout << " Введите максимальную броню вашего персонажа (от " << minArmor << " до " << maxArmor << "): ";
        do tmp = enterNumber();
        while (tmp < minArmor || tmp > maxArmor);
        player.armor = tmp;
        std::cout << " Введите урон вашего персонажа (от " << minDamage << " до " << maxDamage << "): ";
        do tmp = enterNumber();
        while (tmp < minDamage || tmp > maxDamage);
        player.damage = tmp;
        player.position.x = rand() % gBgSize;
        player.position.y = rand() % gBgSize;
        std::vector <Character> players;
        players.push_back(player);
        for (int i = 1; i <= 5; ++i)
            players.push_back(generateCharacter(i, minHealth, maxHealth, minArmor, maxArmor, minDamage, maxDamage));
        bool match = true;
        while (match)
        {
            match = false;
            for (int i = 0; i < (players.size() - 1); ++i)
            {
                if ((players[i].position.x == players[i + 1].position.x) &&
                    (players[i].position.y == players[i + 1].position.y))
                {
                    players[i].position.x = rand() % gBgSize;
                    players[i].position.y = rand() % gBgSize;
                    match = true;
                }
            }
        }
        bool playerAlive = true;
        bool enemysAlive = true;
        while (playerAlive && enemysAlive)
        {
            printBattleGround(battleGround, players);
            health_status(players);
            std::cout << std::endl;
            std::string moveVariables[] = {"top", "bottom", "left", "right"};
            std::string command[] = {"save", "load"};
            std::cout << " Введите направление передвижения /";
            for (std::string mv: moveVariables) std::cout << mv << "/";
            std::cout << ":" << std::endl;
            std::cout << " или команду /";
            for (std::string c: command) std::cout << c << "/";
            std::cout << ":" << std::endl;
            std::string action = "";
            int way;
            bool matchMove = false;
            bool matchCommand = false;
            while (!matchMove && !matchCommand)
            {
                std::getline(std::cin, action);
                for (int i = 0; i < action.length(); ++i)
                    action[i] = std::tolower(action[i]);
                int size = sizeof(command) / sizeof(command[0]);
                for (int i = 0; !matchCommand && i < size; ++i)
                    if (action == command[i])
                    {
                        matchCommand = true;
                        (i == 0) ? save(players) : load(players);
                    }
                size = sizeof(moveVariables) / sizeof(moveVariables[0]);
                for (int i = 0; !matchCommand && !matchMove && i < size; ++i)
                    if (action == moveVariables[i])
                    {
                        matchMove = true;
                        way = i;
                    }
            }
            if (matchMove)
            {
                if (isCorrectMove(players[0], way))
                {
                    for (int i = 1; i < players.size(); ++i)
                        if (isAttack(players[0], players[i]))
                        {
                            dealDamage(players[0], players[i]);
                            moveTurnBack(players[0], way);
                        }
                }
                for (int i = 1; i < players.size(); ++i)
                {
                    if (players[i].alive)
                    {
                        way = rand() % WAY_VARIABLES;
                        if (isCorrectMove(players[i], way))
                        {
                            if (isAttack(players[i], players[0]))
                            {
                                dealDamage(players[i], players[0]);
                                moveTurnBack(players[i], way);
                            }
                            for (int j = 1; j < players.size(); ++j)
                                if ((j != i) && isAttack(players[i], players[j]))
                                    moveTurnBack(players[i], way);
                        }
                    }
                }
                playerAlive = players[0].alive;
                enemysAlive = false;
                for (int i = 1; (i < players.size()) && !enemysAlive; ++i)
                    if (players[i].alive)
                        enemysAlive = true;
            }
        }
        printBattleGround (battleGround, players);
        health_status(players);
        std::cout << players[0].name << (playerAlive ? " победил." : " проиграл.") << std::endl << std::endl;
    }