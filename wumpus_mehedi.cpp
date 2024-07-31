#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

#define GRIDSIZE 4
#define UP 0
#define DOWN 2
#define LEFT 3
#define RIGHT 1
#define MAX_SHOTS 3

// the function name is changed from 'to_string' to 'to_str' to avoid collision.
string to_str(int x) {
    std::string out_string;
    std::stringstream ss;
    ss << x;
    return ss.str();
}

class Position {

    int x, y;

public:
    Position(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Position() {}

    // Modify the following four so that the resulting position does not leave the grid
    void moveRight() {
        if (x < GRIDSIZE - 1) {
            x++;
        }
    }

    void moveLeft() {
        if (x > 0) {
            x--;
        }
    }

    void moveUp() {
        if (y < GRIDSIZE - 1) {
            y++;
        }
    }

    void moveDown() {
        if (y > 0) {
            y--;
        }
    }

    bool isAdjacent(Position p) {
        // implement the function
        if ((abs(x - p.x) + abs(y - p.y)) == 1)
            return true;
        return false;
    }

    bool isSamePoint(Position p) {
        if (x == p.x && y == p.y)
            return true;
        return false;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

class Wumpus {

    bool killed;
    Position p;

public:
    Wumpus(int x, int y) {
        p = Position(x, y);
        killed = false;
    }

    Wumpus() {
        // assign the postion randomly.
        int pos_x = rand() % 4;
        int pos_y = rand() % 4;
        p = Position(pos_x, pos_y);
        killed = false;
    }

    void kill() {
        killed = true;
    }

    Position getPosition() {
        return p;
    }

    bool wumpusIsAlive() {
        return !killed;
    }
};

class Pit {
    Position p;

public:
    Pit(int x, int y) {
        p = Position(x, y);
    }

    Pit() {
        int pos_x = rand() % 4;
        int pos_y = rand() % 4;
        p = Position(pos_x, pos_y);
    }

    Position getPosition() {
        return p;
    }
};

class Player {

    int direction;
    int total_shots;
    bool killed;
    Position p;

public:
    Player() {
        //...
        direction = UP;
        total_shots = MAX_SHOTS;
        killed = false;
        p = Position(0, 0);
    }

    void turnLeft() {
        //...
        if (direction == UP)
            direction = LEFT;
        else if (direction == RIGHT)
            direction = UP;
        else if (direction == DOWN)
            direction = RIGHT;
        else if (direction == LEFT)
            direction = DOWN;
    }

    void turnRight() {
        //...
        if (direction == UP)
            direction = RIGHT;
        else if (direction == RIGHT)
            direction = DOWN;
        else if (direction == DOWN)
            direction = LEFT;
        else if (direction == LEFT)
            direction = UP;
    }

    void moveForward() {
        //...
        if (direction == UP)
            p.moveUp();
        else if (direction == RIGHT)
            p.moveRight();
        else if (direction == DOWN)
            p.moveDown();
        else if (direction == LEFT)
            p.moveLeft();
    }

    bool isAdjacent(Position pos) {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos) {
        return p.isSamePoint(pos);
    }

    void kill() {
        killed = true;
    }

    string getPositionInfo() {
        return "Player is now at " + to_str(p.getX()) + ", " + to_str(p.getY());
    }

    string getDirectionInfo() {
        string s;
        if (direction == UP)
            s = "up \U00002B06";
        if (direction == DOWN)
            s = "down \U00002B07";
        if (direction == LEFT)
            s = "left \U00002B05";
        if (direction == RIGHT)
            s = "right \U000027A1";
        return "Player is moving at direction: " + s;
    }

    string getAmmoInfo() {
        string str;
        if (total_shots == 0) {
            str = "Shots left: " + to_str(total_shots) + " \U00002757";
        } else {
            str = "Shots left: " + to_str(total_shots);
        }
        return str;
    }

    int getTotalShots() {
        return total_shots;
    }

    void reduceShots() {
        total_shots--;
    }

    Position getPosition() {
        return p;
    }

    int getDirection() {
        return direction;
    }
};

class WumpusWorld {

private:
    Player player;
    Wumpus wumpus;
    Pit pit;
    Position gold_position;
    bool ended;

    int generateRandomX() {
        return rand() % 4;
    }

    int generateRandomY(int x = -1) {
        // if X is 0, generate from 1 to 3
        if (x == 0) {
            int y = rand() % 4;
            while (y == 0) {
                y = rand() % 4;
            }
            return y;
        }

        return rand() % 4;
    }

public:
    WumpusWorld() {
        player = Player();

        int pos_x = generateRandomX();
        int pos_y = generateRandomY(pos_x);
        wumpus = Wumpus(pos_x, pos_y);

        pos_x = generateRandomX();
        pos_y = generateRandomY(pos_x);
        pit = Pit(pos_x, pos_y);

        pos_x = generateRandomX();
        pos_y = generateRandomY(pos_x);
        gold_position = Position(pos_x, pos_y);

        while (pit.getPosition().getX() == gold_position.getX() && pit.getPosition().getY() == gold_position.getY()) {
            pos_x = generateRandomX();
            pos_y = generateRandomY(pos_x);
            pit = Pit(pos_x, pos_y);

            pos_x = generateRandomX();
            pos_y = generateRandomY(pos_x);
            gold_position = Position(pos_x, pos_y);
        }

        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y) {
        player = Player();

        wumpus = Wumpus(wumpus_x, wumpus_y);

        int pos_x = generateRandomX();
        int pos_y = generateRandomY(pos_x);
        pit = Pit(pos_x, pos_y);

        pos_x = generateRandomX();
        pos_y = generateRandomY(pos_x);
        gold_position = Position(pos_x, pos_y);

        while (pit.getPosition().getX() == gold_position.getX() && pit.getPosition().getY() == gold_position.getY()) {
            pos_x = generateRandomX();
            pos_y = generateRandomY(pos_x);
            pit = Pit(pos_x, pos_y);

            pos_x = generateRandomX();
            pos_y = generateRandomY(pos_x);
            gold_position = Position(pos_x, pos_y);
        }

        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y) {
        player = Player();

        int pos_x = generateRandomX();
        int pos_y = generateRandomY(pos_x);
        pit = Pit(pos_x, pos_y);

        wumpus = Wumpus(wumpus_x, wumpus_y);
        gold_position = Position(gold_x, gold_y);

        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y) {
        player = Player();

        wumpus = Wumpus(wumpus_x, wumpus_y);
        pit = Pit(pit_x, pit_y);
        gold_position = Position(gold_x, gold_y);

        ended = false;
    }

    void moveForward() {
        player.moveForward();
        return showGameState();
    }

    void turnLeft() {
        player.turnLeft();
        return showGameState();
    }

    void turnRight() {
        player.turnRight();
        return showGameState();
    }

    void shoot() {
        // If there is no ammo, return
        if (player.getTotalShots() <= 0) {
            cout << "You're out of ammo! Run for your life! \U0001F631 \U0001F631" << endl;
            return;
        }

        player.reduceShots();

        if (!wumpus.wumpusIsAlive()) {
            // there is nobody to shoot
            cout << "The Wumpus is already dead. \U0001F480" << endl;
            return;
        }

        int player_x = player.getPosition().getX();
        int player_y = player.getPosition().getY();

        int wumpus_x = wumpus.getPosition().getX();
        int wumpus_y = wumpus.getPosition().getY();

        if (player_x != wumpus_x && player_y != wumpus_y) {
            // the wumpus is not in the line of sight of the player
            cout << "Oops! Missed! The Wumpus is out of sight! \U0000274C" << endl;
            return;
        }

        if (player_x == wumpus_x) {
            if (player.getDirection() == UP && player_y < wumpus_y) {
                // target hit!
                cout << "Headshot! Wumpus killed! \U0001F3AF" << endl;
                wumpus.kill();
                return;
            } else if (player.getDirection() == DOWN && player_y > wumpus_y) {
                // target hit!
                cout << "Headshot! Wumpus killed! \U0001F3AF" << endl;
                wumpus.kill();
                return;
            } else {
                // target behind.
                cout << "Target is behind you! Move around! \U0000274C" << endl;
                return;
            }
        }

        if (player_y == wumpus_y) {
            if (player.getDirection() == RIGHT && player_x < wumpus_x) {
                // target hit!
                cout << "Headshot! Wumpus killed! \U0001F3AF" << endl;
                wumpus.kill();
                return;
            } else if (player.getDirection() == LEFT && player_x > wumpus_x) {
                // target hit!
                cout << "Headshot! Wumpus killed! \U0001F3AF" << endl;
                wumpus.kill();
                return;
            } else {
                // target behind.
                cout << "Target is behind you! Move around! \U0000274C" << endl;
                return;
            }
        }
    }

    void showGameState() {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;
        cout << player.getAmmoInfo() << endl;

        if (player.isSamePoint(gold_position)) {
            cout << "Got the gold! \U0001F3C6 \U0001F3C6 \U0001F3C6" << endl;
            cout << "You Won! \U0001F389 \U0001F389 \U0001F389" << endl;
            ended = true;
            return;
        }

        if (player.isAdjacent(pit.getPosition())) {
            cout << "Feeling a breeze?! \U0001F32A \U0001F32A" << endl;
        }

        if (player.isSamePoint(pit.getPosition())) {
            cout << "You fell in the pit! Rot in there! \U0001F480" << endl;
            player.kill();
            cout << "Game Over! \U0001F62D" << endl;
            ended = true;
        }

        if (player.isAdjacent(wumpus.getPosition()) && wumpus.wumpusIsAlive()) {
            cout << "stench!\U00002757\U00002757" << endl;
        }

        if (player.isSamePoint(wumpus.getPosition()) && wumpus.wumpusIsAlive()) {
            cout << "You have been killed! \U0001F480" << endl;
            player.kill();
            cout << "Game over! \U0001F62D" << endl;
            ended = true;
        }
    }

    bool isOver() {
        return ended;
    }

    // For manual testing purposes
    void showSecretData() {
        cout << "Wumpus postion: " << wumpus.getPosition().getX() << " " << wumpus.getPosition().getY() << endl;
        cout << "Pit postion: " << pit.getPosition().getX() << " " << pit.getPosition().getY() << endl;
        cout << "Gold position: " << gold_position.getX() << " " << gold_position.getY() << endl;
    }
};

int main() {
    // to increase the randomness.
    srand(time(nullptr));

    int c, wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y;
    // cin >> wumpus_x >> wumpus_y >> gold_x >> gold_y >> pit_x >> pit_y;

    // take the six integers input from file

    // setting this to true to get random values each time
    bool inputFailedToOpen = true;
    ifstream inputFile("input.txt"); // Open the input file

    if (inputFile.is_open()) {
        inputFile >> wumpus_x >> wumpus_y >> gold_x >> gold_y >> pit_x >> pit_y;

        inputFile.close();

    } else {
        cout << "Failed to open input file!!" << endl;
        inputFailedToOpen = true;
    }

    WumpusWorld w;
    if (inputFailedToOpen) {
        w = WumpusWorld();
    } else {
        w = WumpusWorld(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);
    }

    w.showGameState();

    // for manual testing purposes
    // w.showSecretData();

    while (!w.isOver()) {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shoot" << endl;
        cin >> c;
        if (c == 1) {
            w.moveForward();
        } else if (c == 2) {
            w.turnLeft();
        } else if (c == 3) {
            w.turnRight();
        } else if (c == 4) {
            w.shoot();
        }
    }
    return 0;
}