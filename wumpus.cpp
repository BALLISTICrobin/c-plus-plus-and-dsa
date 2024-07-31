#include <iostream>
#include <cmath>
#include <sstream>
#include<fstream>
#include <time.h>

using namespace std;

#define GRIDSIZE 4
#define UP 0
#define DOWN 2
#define LEFT 3
#define RIGHT 1
#define MAX_SHOTS 3

string to1_string(int x)
{
    std::string out_string;
    std::stringstream ss;
    ss << x;
    return ss.str();
}

class Position
{

    int x, y;

public:
    Position(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Position() {}

    // Modify the following four so that the resulting position does not leave the grid
    void moveRight()
    {
        x++;
        if (x > 3)
        {
            x--;
        }
    }

    void moveLeft()
    {
        x--;
        if (x < 0)
        {
            x++;
        }
    }

    void moveUp()
    {
        y++;
        if (y > 3)
        {
            y--;
        }
    }

    void moveDown()
    {
        y--;
        if (y < 0)
        {
            y++;
        }
    }

    bool isAdjacent(Position p)
    {
        // implement the function
        double square_root = sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
        if (square_root == 1.000)
        {
            return true;
        }
        else
            return false;

           
    }

    bool isSamePoint(Position p)
    {
        // implement the function
        if (x == p.x && y == p.y)
            return true;
        else
            return false;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

class Wumpus
{

    bool killed;
    Position p;

public:
    Wumpus(int x, int y)
    {
        p = Position(x, y);
        killed = false;
    }

    Wumpus()
    {
        int a, b;
        srand(time(0));
        while (true)
        {
            a = rand() % 4;
            b = rand() % 4;
            if ((a == 0 && b != 0) || (b == 0 && a != 0) || (a != 0 && b != 0))
                break;
        }
        p = Position(a, b);
        //cout << p.getX() << "," << p.getY() << endl;
        killed = false;
    }

    void kill()
    {
        killed = true;
        cout << "8-X You shot me!! I'll take my revenge 3:-) " << endl;
    }

    Position getPosition()
    {
        return p;
    }

    bool ret_kill()
    {
        return killed;
    }
    friend class WumpusWorld;
};

class Player
{

    int direction;
    int total_shots;
    bool killed;
    Position p;

public:
    Player()
    {
        direction = 0;
        total_shots = 3;
        killed = false;
        p = Position(0, 0);
        // cout << p.getX() << "," << p.getY() << endl;
    }

    void turnLeft()
    {
        switch (direction)
        {
        case 0:
            direction = 3;
            break;

        case 1:
            direction = 0;
            break;

        case 2:
            direction = 1;
            break;

        case 3:
            direction = 2;
            break;

        default:
            break;
        }
    }

    void turnRight()
    {
        switch (direction)
        {
        case 0:
            direction = 1;
            break;

        case 1:
            direction = 2;
            break;

        case 2:
            direction = 3;
            break;

        case 3:
            direction = 0;
            break;

        default:
            break;
        }
    }

    void moveForward()
    {
        switch (direction)
        {
        case 0:
            p.moveUp();
            break;

        case 1:
            p.moveRight();
            break;

        case 2:
            p.moveDown();
            break;

        case 3:
            p.moveLeft();
            break;

        default:
            break;
        }
    }

    bool isAdjacent(Position pos)
    {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos)
    {
        return p.isSamePoint(pos);
    }

    void kill()
    {
        killed = true;
    }

    string getPositionInfo()
    {
        return "Player is now at " + to1_string(p.getX()) + ", " + to1_string(p.getY());
    }

    string getDirectionInfo()
    {
        string s;
        if (direction == UP)
            s = "up";
        if (direction == DOWN)
            s = "down";
        if (direction == LEFT)
            s = "left";
        if (direction == RIGHT)
            s = "right";
        return "Player is moving at direction: " + s;
    }
    friend class WumpusWorld;
};

class WumpusWorld
{

private:
    Player player;
    Wumpus wumpus;
    Position gold_position, pit_position;
    bool ended;

public:
    WumpusWorld()
    {

        srand(time(0));
        while (true)
        {
            gold_position = Position(rand() % 4, rand() % 4);
            if (gold_position.isSamePoint(wumpus.getPosition()) || player.isSamePoint(gold_position))
            {
                continue;
            }
            else
                break;
        }
        while (true)
        {
            pit_position = Position(rand() % 4, rand() % 4);
            if (pit_position.isSamePoint(wumpus.getPosition()) || pit_position.isSamePoint(gold_position) || player.isSamePoint(pit_position))
            {
                continue;
            }
            else
                break;
        }
        // cout << gold_position.getX() << "," << gold_position.getY() << endl;
        // cout << pit_position.getX() << "," << pit_position.getY() << endl;
        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y)
    {
        wumpus.p = Position(wumpus_x, wumpus_y);
        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y)
    {
        wumpus.p = Position(wumpus_x, wumpus_y);
        gold_position = Position(gold_x, gold_y);
        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y)
    {
        wumpus.p = Position(wumpus_x, wumpus_y);
        gold_position = Position(gold_x, gold_y);
        pit_position = Position(pit_x, pit_y);
        ended = false;
    }

    void moveForward()
    {
        player.moveForward();
        return showGameState();
    }

    void turnLeft()
    {
        player.turnLeft();
        return showGameState();
    }

    void turnRight()
    {
        player.turnRight();
        return showGameState();
    }

    void shoot()
    {
        if (player.total_shots > 0)
        {
            switch (player.direction)
            {
            case 0:
                player.total_shots--;
                if (player.p.getX() == wumpus.p.getX() && player.p.getY() < wumpus.p.getY())
                    wumpus.kill();
                else
                    cout << ":-P Haa! little coward u missed it. Now u show 101 excuses for missing target :-D";
                break;

            case 1:
                player.total_shots--;
                if (player.p.getY() == wumpus.p.getY() && player.p.getX() < wumpus.p.getX())
                    wumpus.kill();
                else
                    cout << ":-P Haa! little coward u missed it. Now u show 101 excuses for missing target :-D";
                break;

            case 2:
                player.total_shots--;
                if (player.p.getX() == wumpus.p.getX() && player.p.getY() > wumpus.p.getY())
                    wumpus.kill();
                else
                    cout << ":-P Haa! little coward u missed it. Now u show 101 excuses for missing target :-D";
                break;

            case 3:
                player.total_shots--;
                if (player.p.getY() == wumpus.p.getY() && player.p.getX() > wumpus.p.getX())
                    wumpus.kill();
                else
                    cout << ":-P Haa! little coward u missed it. Now u show 101 excuses for missing target :-D";
                break;

            default:
                break;
            }
        }
        else{
            cout << "Sorry,u have no more ammunition. ";
            cout<<"The warrior uses whatever is closest to hand." << endl;
        }   
    }

    void showGameState()
    {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;

        if (player.isAdjacent(wumpus.getPosition()) && wumpus.ret_kill() == false)
        {
            cout << "(>_<)Ugh!! STENCH!" << endl;
        }
        if (player.isAdjacent(pit_position))
        {
            cout << ":-o Shhh! BREEZE!" << endl;
        }

        if (player.isSamePoint(wumpus.getPosition()) && wumpus.ret_kill() == false)
        {
            cout << ":( Yummy!You're so delicious and juicy.Player is killed by the monster!" << endl;
            player.kill();
            cout << ":'( Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(pit_position))
        {
            cout << ":-( Player is trapped in the pit forever!I want you to listen very carefully"; 
            cout<<". Before this nights over, I will kill you," << endl;
            player.kill();
            cout << ":'( Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(gold_position))
        {
            cout << ":-) Got the gold!" << endl;
            cout << "(=^_^=) Game ended, you won!" << endl;
            ended = true;
        }
    }

    bool isOver()
    {
        return ended;
    }
};

int main()
{
    int wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y;
    // // take the six integers input from file
    ifstream in("wumpusfile.txt");
    in>>wumpus_x>>wumpus_y>>gold_x>>gold_y>>pit_x>>pit_y;
    WumpusWorld w(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);
    int c;
    //WumpusWorld w;
    w.showGameState();
    while (!w.isOver())
    {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shoot" << endl;
        cin >> c;
        if (c == 1)
        {
            w.moveForward();
        }
        else if (c == 2)
        {
            w.turnLeft();
        }
        else if (c == 3)
        {
            w.turnRight();
        }
        else if (c == 4)
        {
            w.shoot();
            w.showGameState();
        }
    }
    return 0;
}