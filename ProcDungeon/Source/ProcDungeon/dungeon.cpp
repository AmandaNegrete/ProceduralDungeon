
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
                DungeonRoom closestRoom = rooms[0];
                int closestDist = INT_MAX;

                for (const auto& r : rooms)
                {
                    int dx = (r.x + r.width / 2) - (newRoom.x + newRoom.width / 2);
                    int dy = (r.y + r.height / 2) - (newRoom.y + newRoom.height / 2);
                    int dist = dx * dx + dy * dy;

                    if (dist < closestDist)
                    {
                        closestDist = dist;
                        closestRoom = r;
                    }
                }

                corridor(closestRoom, newRoom);
            }
            rooms.push_back(newRoom);
        }
        attempts_before_infinite++;
    }

    // Add extra random connections between rooms to increase maze complexity
    const int extraConnections = max(0, static_cast<int>(rooms.size()) / 3);
    for (int i = 0; i < extraConnections; ++i) {
        int a = rand() % rooms.size();
        int b = rand() % rooms.size();
        if (a != b) corridor(rooms[a], rooms[b]);
    }

    // Choose start and exit rooms randomly (distinct) if possible
    if (rooms.size() >= 2) {
        int startIndex = rand() % rooms.size();
        int exitIndex = rand() % rooms.size();
        while (exitIndex == startIndex) exitIndex = rand() % rooms.size();
        startTile = { rooms[startIndex].roomCenterX(), rooms[startIndex].roomCenterY() };
        exitTile  = { rooms[exitIndex].roomCenterX(),  rooms[exitIndex].roomCenterY()  };
    } else if (rooms.size() == 1) {
        startTile = exitTile = { rooms.front().roomCenterX(), rooms.front().roomCenterY() };
    } else {
        // fallback corners
        startTile = {1,1};
        exitTile = { max(1, width - 2), max(1, height - 2) };
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


bool Dungeon::overlaps(     DungeonRoom room) {
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
    // jitter centers slightly for variety
    int room_ax = room_a.roomCenterX() + (rand() % 3 - 1); // -1..1
    int room_ay = room_a.roomCenterY() + (rand() % 3 - 1);
    int room_bx = room_b.roomCenterX() + (rand() % 3 - 1);
    int room_by = room_b.roomCenterY() + (rand() % 3 - 1);

    if (rand() % 2 == 0) {
        createhorizontal(room_ax, room_bx, room_ay);
        createvertical(room_ay, room_by, room_bx);
    } else {
        createvertical(room_ay, room_by, room_ax);
        createhorizontal(room_ax, room_bx, room_by);
    }
}

int Dungeon::randomRoomValues(int a, int b) {
    return a + (rand() % (b - a + 1));
}


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

const std::vector<std::vector<int>>& Dungeon::getGrid() const {
    return grid;
}

std::pair<int, int> Dungeon::getstart() const {
    return startTile;
}

std::pair<int, int> Dungeon::getexit() const {
    return exitTile;

}

bool Dungeon::edgeWall(int x, int y) const {
  if 
      //need to calculate the space between
      //TODO

    return false;
}