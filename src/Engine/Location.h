#ifndef FALLTERGEIST_LOCATION_H
#define FALLTERGEIST_LOCATION_H

#include "../../lib/libfalltergeist/libfalltergeist.h"

namespace Falltergeist
{
class Surface;
class LocationObject;

class Location
{
protected:
    std::vector<LocationObject *> * _objects;
    unsigned int _cols;
    unsigned int _rows;

    unsigned int _cameraX;
    unsigned int _cameraY;

    unsigned int _elevation;

    Surface * _tilesBackground;

    libfalltergeist::MapFileType * _mapFile;
    libfalltergeist::LstFileType * _tilesLst;


public:
    enum { TILE_WIDTH = 80, TILE_HEIGHT = 36 };

    Location(libfalltergeist::MapFileType * mapFile);
    ~Location();
    void init();
    void think();
    void generateBackground();
    bool scroll(bool up = false, bool down = false, bool left = false, bool right = false);
    int hexagonToX(unsigned int hexagon);
    int hexagonToY(unsigned int hexagon);
    int tileToX(unsigned int tile);
    int tileToY(unsigned int tile);
    unsigned int width();
    unsigned int height();
    unsigned int cameraX();
    unsigned int cameraY();

    libfalltergeist::MapFileType * mapFile();
    Surface * tilesBackground();
    std::vector<LocationObject *> * objects();
};


}

#endif // FALLTERGEIST_LOCATION_H
