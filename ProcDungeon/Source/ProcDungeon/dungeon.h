#ifndef DUNGEON_H
#define DUNGEON_H
///////////////////
#include <vector>
#include <string>
#include <random> //allows us to use random generation!!

/*
enum TileType{
    WALL = 1,
    FLOOR = 0,
};
*/
/*// Dungeon.h

#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>
#include <random>


// Dungeon generator
class Dungeon {
public:
    Dungeon(int width, int height, unsigned seed = 0);

    void generate();      // main generation pipeline
    void printAscii() const; // ASCII preview (for debugging)

private:
    int width, height;
    std::vector<Cell> grid;
/NOOO
};

#endif
*/

struct DungeonRoom {
    int x;
    int y; // xy for position
    int width; // width of the room
    int height; // height of the room

    int roomCenterX() const {
        return x + (width / 2);
    }
    int roomCenterY() const {
        return y + (height / 2);
    }
};

// define the dungeon class
class Dungeon {
public:
    Dungeon(int width, int height, int maxRooms, int roomMinSize, int roomMaxSize);
    void generateDungeon(); // func generate the dungeon
    void printDungeon(); // func to print the dungeon
    const std::vector<std::vector<int>>& getGrid() const;

    bool edgeWall(int x, int y) const;
    //found example that used this method migh help migh be USELESS
    std::pair<int,int> getstart() const;
    std::pair<int,int> getexit() const;

private:
    int width;
    int height;
    int maxRooms; // max number of rooms
    int roomMinSize; // min size of the room
    int roomMaxSize; // max size of the room

    std::vector<std::vector<int>> grid;
    std::vector<DungeonRoom> rooms;
    int roomCount = 0;

    // start/exit tile coordinates (x, y)
    std::pair<int,int> startTile{1,1};
    std::pair<int,int> exitTile{1,1};

    // FUNCTIONS IN CPP
    void createRoom(DungeonRoom room);
    int randomRoomValues(int range_a, int range_b);
    bool overlaps(DungeonRoom room);
    void corridor(DungeonRoom room_a, DungeonRoom room_b);
    void createhorizontal(int x1, int x2, int y);
    void createvertical(int y1, int y2, int x);
};
