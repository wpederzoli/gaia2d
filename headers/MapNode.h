#ifndef MAPNODE_H
#define MAPNODE_H

#include "Map.h"
#include "SceneNode.h"

class MapNode : public SceneNode
{
    private:
        Map* map;
        bool solid;
    
    public:
        MapNode(int id, int x, int y, int width, int height, bool solid, Map* m);
        ~MapNode();

        virtual void draw(Rectangle* view, Graphics* g);
        virtual void move(int x, int y);

        bool overlapsMap();
        
        void setCollision(bool collide){ this->solid = collide; };
        void setMap(Map* m){ this->map = m; };
};

#endif