#ifndef TILES_H_INCLUDED
#define TILES_H_INCLUDED

/**
 * A tile in a tile map.
 **/
struct Tile {
    unsigned short type;
    unsigned short dataLength;
    char* data;
};

/**
 * An n-dimensional tile map.
 **/
struct Tilemap {
    unsigned short dims;
    unsigned long long flatSize;
    unsigned long long* shape;
    Tile* data;
};

Tilemap* allocTilemap(unsigned short dims, unsigned long long* shape);
void deallocTilemap(Tilemap* TM);

#endif // TILES_H_INCLUDED
