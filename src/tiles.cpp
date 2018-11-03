#include <assert.h>
#include <cstring>

#include "tiles.h"


/**
 * Allocates a tile map.
 **/
Tilemap* allocTilemap(unsigned short dims, unsigned long long* shape) {
    Tilemap* tm = new Tilemap;
    tm->dims = dims;
    tm->shape = new unsigned long long[dims];

    for (unsigned short i = 0; i < dims; i++)
        tm->shape[i] = shape[i];

    unsigned long long flatSize = 0;

    if (dims > 0) {
        flatSize = shape[0];

        for (unsigned short i = 1; i < dims; i++)
            flatSize *= shape[i];
    }

    tm->data = new Tile[flatSize];
    tm->flatSize = flatSize;

    return tm;
}

Tile* buildTile(unsigned short type, char* data) {
    Tile* t = new Tile;
    t->type = type;
    t->dataLength = strlen(data);
    t->data = data;

    return t;
}

/**
 * Sets a single tile on a tile map.
 **/
void setTile(Tilemap* tmap, Tile* T, unsigned long long* coords) {
    assert(tmap->dims > 0); // unsigned variables CAN be zero, they just
                            // can't be negative ;)
    for (unsigned short i = 0; i < tmap->dims; i++)
        assert(tmap->shape[i] > coords[i]);

    unsigned long long index = 0;

    for (unsigned short i = tmap->dims - 1; i >= 0; i--) {
        unsigned long long l = coords[tmap->dims - 1];
        for (unsigned short j = i - 1; j >= 0; j++) l *= tmap->shape[j];

        index += l;
    }

    delete (tmap->data + index);
    tmap->data[index] = *T;
}

void deallocTilemap(Tilemap* TM) {
    delete[] TM->data;
    delete[] TM->shape;

    delete (TM);
}
