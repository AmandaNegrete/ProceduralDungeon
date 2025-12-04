
#include "dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//Purpose: Constructor to initialize dungeon parameters and grid
Dungeon::Dungeon(int width_, int height_, int maxRooms_, int minSize_, int maxSize_, int thickness) {
    width = width_;
    height = height_;
    maxRooms = maxRooms_;
    roomMinSize = minSize_;
    roomMaxSize = maxSize_;
    thickness_path = thickness;
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
    //more than one room 
    if (rooms.size() >= 2) {
        //random start and room 
        int startIndex = rand() % rooms.size();
        int exitIndex = rand() % rooms.size();
        while (exitIndex == startIndex) {
            exitIndex = rand() % rooms.size();
        }
        startTile = { rooms[startIndex].roomCenterX(), rooms[startIndex].roomCenterY() };
        exitTile  = { rooms[exitIndex].roomCenterX(),  rooms[exitIndex].roomCenterY()  };
    } else if (rooms.size() == 1) {
        startTile = exitTile = { rooms.front().roomCenterX(), rooms.front().roomCenterY() };
    } else {
        //in theory the top left corner
        startTile = {1,1};
        //bottom right
        exitTile = { max(1, width - 2), max(1, height - 2) };
    }


}


void Dungeon::createRoom(DungeonRoom room) {
    for (int y = room.y; y < room.y + room.height && y < height; y++) {
        for (int x = room.x; x < room.x + room.width && x < width; x++) {
            grid[y][x] = FLOOR_TILE;
        }
    }
}


bool Dungeon::overlaps( DungeonRoom room) {
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

void Dungeon::corridor(DungeonRoom a, DungeonRoom b) {
    int ax = a.roomCenterX();
    int ay = a.roomCenterY();
    int bx = b.roomCenterX();
    int by = b.roomCenterY();
/*
    int midX = (ax + bx) / 2;
    int midY = (ay + by) / 2;

    createhorizontal(ax, midX, ay);
    createvertical(ay, midY, midX);
    createhorizontal(midX, bx, by);

*/
    //random val is even, continous do horizontal before vertical 
    if (rand() % 2 == 0) {
        createhorizontal(ax, bx, ay);
        createvertical(ay, by, bx);
    }
    else {
        createvertical(ay, by, bx);
        createhorizontal(ax, bx, ay);
    }
}


int Dungeon::randomRoomValues(int a, int b) {
    return a + (rand() % (b - a + 1));
}

//examples from other
void Dungeon::createhorizontal(int x1, int x2, int y) {
    if (x2 < x1) swap(x1, x2);
    //offset the thickness to fill 
    int halfThickness = thickness_path / 2;
    for (int offset = -halfThickness; offset <= halfThickness; offset++)
    {
        int newY = y + offset;

        //skip oer the a
        if (newY < 0 || newY >= height)
            continue;

        //x range on floor 
        for (int x = x1; x <= x2; x++)
        {
            if (x < 0 || x >= width)
                continue;

            grid[newY][x] = FLOOR_TILE;
        }
    }
}


//examples from other
void Dungeon::createvertical(int y1, int y2, int x) {
    if (y2 < y1) swap(y1, y2);
    // How many tiles to expand left and right for thickness
    int halfThickness = thickness_path / 2;
    for (int offset = -halfThickness; offset <= halfThickness; offset++){   
        int newX = x + offset;
        if (newX < 0 || newX >= width) continue;

        for (int y = y1; y <= y2; y++)
        {
            if (y < 0 || y >= height)
                continue;
            grid[y][newX] = FLOOR_TILE;
        }
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

//i want to return the middle of floor and wall 
bool Dungeon::edgeWall(int x, int y) const {
    //need to calculate the space between
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return false;
    }

    //only walls for this 
    if (grid[y][x] != WALL_TILE) {
        return false;
    }
    //now top bottom left and right checking 
    //subtract x val by one to look at the col to the LEFT of the x marker 
    if (x > 0 && grid[y][x - 1] == FLOOR_TILE) {
        return true;
    }
    //same for the right- add one 
    if (x < width - 1 && grid[y][x + 1] == FLOOR_TILE) {
        return true;
    }
    if (y > 0 && grid[y - 1][x] == FLOOR_TILE) {
        return true;
    }
    if (y < height - 1 && grid[y + 1][x] == FLOOR_TILE) {
        return true;
    }
    //nothing found
    return false;

}
//for wall point so that it doesnt get placed outside!s
FVector Dungeon::WallPositionSet(int x, int y) const
{
    //checking grid neighbors to find floor neighbiors
    //first to left 
    if (x > 0 && grid[y][x - 1] == FLOOR_TILE)
        return FVector(-1, 0, 0);
    //right 
    if (x < width - 1 && grid[y][x + 1] == FLOOR_TILE)
        return FVector(1, 0, 0);
    //above
    if (y > 0 && grid[y - 1][x] == FLOOR_TILE)
        return FVector(0, -1, 0);
    //below
    if (y < height - 1 && grid[y + 1][x] == FLOOR_TILE)
        return FVector(0, 1, 0);

    //else default for the placement given below
    return FVector(1, 0, 0);
}
//https://forums.unrealengine.com/t/how-to-create-a-pointlight-at-runtime-use-c/373942?utm_source=chatgpt.com
TArray<FIntPoint> Dungeon::Wall_Torch_Positions(const DungeonRoom& Room) const {
    TArray<FIntPoint> WallPos;
    for (int x = Room.x; x < Room.x + Room.width; ++x) {
        WallPos.Add(FIntPoint(x, Room.y));
        //avoiding not being in the room 
        WallPos.Add(FIntPoint(x, Room.y + Room.height - 1));
    }
    for (int y = Room.y; y < Room.y + Room.height; ++y) {
        WallPos.Add(FIntPoint(Room.x, y));
        //avoiding not being in the room 
        WallPos.Add(FIntPoint(Room.x + Room.width - 1, y));
    }
    return WallPos;
}

TArray<FIntPoint> Dungeon::Wall_LightPoint_Positions(const DungeonRoom& Room) const {
    TArray<FIntPoint> WallPos;
    for (int x = Room.x; x < Room.x + Room.width; ++x) {
        WallPos.Add(FIntPoint(x, Room.y));
        //avoiding not being in the room 
        WallPos.Add(FIntPoint(x, Room.y + Room.height - 1));
    }
    for (int y = Room.y; y < Room.y + Room.height; ++y) {
        WallPos.Add(FIntPoint(Room.x, y));
        //avoiding not being in the room 
        WallPos.Add(FIntPoint(Room.x + Room.width - 1, y));
    }
    return WallPos;
}


TArray<FIntPoint> Dungeon::Wall_Torch_Position_Mesh(const DungeonRoom& Room) const {
    TArray<FIntPoint> WallPos1;
    for (int x = Room.x; x < Room.x + Room.width; ++x) {
        // Check top boundary
        if (edgeWall(x, Room.y)) {
            WallPos1.Add(FIntPoint(x, Room.y));
        }
        // Check bottom boundary
        if (edgeWall(x, Room.y + Room.height - 1)) {
            WallPos1.Add(FIntPoint(x, Room.y + Room.height - 1));
        }
    }
    for (int y = Room.y; y < Room.y + Room.height; ++y) {
        // Check left boundary
        if (edgeWall(Room.x, y)) {
            WallPos1.Add(FIntPoint(Room.x, y));
        }
        // Check right boundary
        if (edgeWall(Room.x + Room.width - 1, y)) {
            WallPos1.Add(FIntPoint(Room.x + Room.width - 1, y));
        }
    }

    return WallPos1;
}
