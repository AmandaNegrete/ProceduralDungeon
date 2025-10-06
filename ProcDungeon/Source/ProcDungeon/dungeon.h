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

const int WALL_TILE = 1;
const int FLOOR_TILE = 0;

struct DungeonRoom{
    int x;
    int y; //xy for position!!
    int width; //width of the room 
    int height; //height of the room 

    int roomCenterCoordinateX() {
        int centerx = (x + (width / 2));
        return centerx;
    }
    int roomCenterCoordinateY() {
        int centery = (y + (height / 2));
        return centery;
    }
};

//define the dungeon class
class Dungeon{
    public:
        Dungeon(int width, int height, int maxRooms, int roomMinSize, int roomMaxSize);
        void generateDungeon(); //func generate the dungeon
        void printDungeon(); //func to print the dungeon
    private:
        int width; 
        int height; 
        int maxRooms; //max number of rooms
        int roomMinSize; //min size of the room
        int roomMaxSize; //max size of the room
        //int grid[40][50]; // 40 rows 50 columns
        std::vector<std::vector<int>> grid;
        //DungeonRoom* rooms = new DungeonRoom[maxRooms];  // allocate space for list of room
        std::vector<DungeonRoom> rooms; 
        int roomCount = 0;   
        
        //FUNCTIONS IN CPP
        //"make the room"
        void createRoom(DungeonRoom room);
        //helps for randomness
        int randomRoomValues(int range_a, int range_b);
        //check if rooms overlap
        //int check_values(int value, int min, int max);
        bool overlaps(DungeonRoom room);
        void corridor(DungeonRoom room_a, DungeonRoom room_b);
        //side to side helper
        void createhorizontal(int x1, int x2, int y);
        //up and down helper
        void createvertical(int y1, int y2, int x);
        //double dist(DungeonRoom a, DungeonRoom b);
};             // keep track manually


#endif