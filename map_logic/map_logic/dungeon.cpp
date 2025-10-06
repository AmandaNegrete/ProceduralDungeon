#include "dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//Purpose: Constructor to initialize dungeon parameters and grid
Dungeon::Dungeon(int width_, int height_, int maxRooms_, int minSize_, int maxSize_) {
    width = width_;
    height = height_;
    maxRooms = maxRooms_;
    roomMinSize = minSize_;
    roomMaxSize = maxSize_;

    // Initialize grid using .resize in cstdlib!!!
    grid.resize(height);
    for (int i = 0; i < height; i++) {
        grid[i].resize(width, WALL_TILE);
    }
    // Seed random number generator
    srand((unsigned)time(0));
}

//Purpose: Generate the dungeon layout using rooms and corridors
//uses room.size to asist while looping through rooms vector
void Dungeon::generateDungeon() {
    int attempts_before_infinite = 0;
    //method found online to prevent infinite loop: https://github.com/kentril0/ProceduralTerrain
    while (rooms.size() < static_cast<size_t>(maxRooms) && attempts_before_infinite < maxRooms * 10) {

        int fix_width =  width - 2;
        int fix_height = height - 2;
        // Random room size
        int roomwidth = randomRoomValues(roomMinSize, min(roomMaxSize, fix_width));
        int roomheight = randomRoomValues(roomMinSize, min(roomMaxSize, fix_height));
        // Random room position
        int room_x = randomRoomValues(1, width - roomwidth - 1);
        int room_y = randomRoomValues(1, height - roomheight - 1);

        DungeonRoom newRoom = {room_x, room_y, roomwidth, roomheight};

        // Check overlaps
        if (!overlaps(newRoom)) {
            createRoom(newRoom);
            // Connect with the beforeroom
            if (!rooms.empty()) {
                corridor(rooms.back(), newRoom);
            }
            rooms.push_back(newRoom);
        }
        attempts_before_infinite++;
    }
}

void Dungeon::printDungeon() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == WALL_TILE)
                cout << "◼";
            else
                cout << "☐";
        }
        cout << "\n";
    }
}

void Dungeon::createRoom(DungeonRoom room) {
    for (int y = room.y; y < room.y + room.height && y < height; y++) {
        for (int x = room.x; x < room.x + room.width && x < width; x++) {
            grid[y][x] = FLOOR_TILE;
        }
    }
}

int Dungeon::randomRoomValues(int range_a, int range_b) {
    if (range_b < range_a) range_b = range_a;
    return range_a + rand() % (range_b - range_a + 1);
}

/*
bool Dungeon::overlaps(DungeonRoom room) {
    for (size_t i = 0; i < rooms.size(); i++) {
        DungeonRoom other = rooms[i];
        if (room.x < other.x + other.width + 1 &&
            room.x + room.width + 1 > other.x &&
            room.y < other.y + other.height + 1 &&
            room.y + room.height + 1 > other.y) {
            return true;
        }
    }
    return false;

*/
bool Dungeon::overlaps(DungeonRoom room) {
    for (size_t i = 0; i < rooms.size(); i++) {
        DungeonRoom other = rooms[i];
        if (room.x < other.x + other.width + 1 &&
            room.x + room.width + 1 > other.x &&
            room.y < other.y + other.height + 1 &&
            room.y + room.height + 1 > other.y) {
            return true;
        }
    }
    return false;
}

void Dungeon::corridor(DungeonRoom room_a, DungeonRoom room_b) {
    int room_ax = room_a.roomCenterX();
    int room_ay = room_a.roomCenterY();
    int room_bx = room_b.roomCenterX();
    int room_by = room_b.roomCenterY();

    /*if (rand() % 3 == 0) {
        createhorizontal(a, bx, ay);
        createvertical(ay, by, bx);
    } else {
        createvertical(ay, by, ax);
        createhorizontal(ax, bx, by);
    }
    }
    */
    if (rand() % 2 == 0) {
        createhorizontal(room_ax, room_bx, room_ay);
        createvertical(room_ay, room_by, room_bx);
    } else {
        createvertical(room_ay, room_by, room_ax);
        createhorizontal(room_ax, room_bx, room_by);
    }
}


//FUNCTIONS THAT I ADAPTED FROM https://github.com/kentril0/ProceduralTerrain
void Dungeon::createhorizontal(int x1, int x2, int y) {
    if (x2 < x1) swap(x1, x2);
    if (y < 0 || y >= height) return;
    for (int x = max(0, x1); x <= min(x2, width - 1); x++) {
        grid[y][x] = FLOOR_TILE;
    }
}

void Dungeon::createvertical(int y1, int y2, int x) {
    if (y2 < y1) swap(y1, y2);
    if (x < 0 || x >= width) return;
    for (int y = max(0, y1); y <= min(y2, height - 1); y++) {
        grid[y][x] = FLOOR_TILE;
    }
}
