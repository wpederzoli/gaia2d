#include "MapNode.h"

MapNode::MapNode(int i, int x, int y, int width, int height, bool solid, Map* m) : SceneNode(i, x, y, width, height)
{
    this->solid = solid;
    this->map = m;
};

MapNode::~MapNode()
{};

//for debugging
void MapNode::draw(Rectangle* view, Graphics* g)
{
    if(this->overlapsMap() )
        g->fillRect(this->getX() - view->getX() , this->getY() - view->getY(),
            this->getWidth(), this->getHeight(), 255, 0, 0);
    else
        g->fillRect(this->getX() - view->getX(), this->getY() - view->getY(),
            this->getWidth(), this->getHeight(), 0, 0, 255);
};

bool MapNode::overlapsMap()
{
    if(this->map == NULL)
        return false;
    
    for(int x = this->getX(); x < this->getX2(); x+= this->map->getTileWidth() )
    {
        for(int y = this->getY(); y < this->getY2(); y += this->map->getTileHeight() )
        {
            if(this->map->checkSolid(x/this->map->getTileWidth(), y/this->map->getTileHeight() ) )
                return true;
        }

        if(this->map->checkSolid(x/this->map->getTileWidth(), this->getY2()/this->map->getTileHeight() ) )
            return true;
    }

    for(int y = this->getY(); y < this->getY2(); y += this->map->getTileHeight() )
    {
        if(this->map->checkSolid(this->getX2()/this->map->getTileWidth(), y/this->map->getTileHeight() ) )
            return true;
    }

    return this->map->checkSolid(this->getX2()/this->map->getTileWidth(), this->getY2()/this->map->getTileHeight() );
};

void MapNode::move(int x, int y)
{
    if(!this->solid || this->map == NULL)
    {
        this->setX(this->getX() + x);
        this->setY(this->getY() + y);
        return;
    }

    this->setX(this->getX() + x);

    if(x < 0)
    {
        if(this->overlapsMap() )
            this->setX( ((this->getX()/this->map->getTileWidth()) + 1) * this->map->getTileWidth() );
    }

    if(x > 0)
    {
        if(this->overlapsMap() )
            this->setX2( (this->getX2()/this->map->getTileWidth()) * this->map->getTileWidth() - 1 );
    }

    this->setY(this->getY() + y);

    if(y < 0)
    {
        if(this->overlapsMap() )
            this->setY( ((this->getY()/this->map->getTileHeight()) + 1) * this->map->getTileHeight() );
    }

    if(y > 0)
    {
        if(this->overlapsMap() )
            this->setY2( (this->getY2()/this->map->getTileHeight()) * this->map->getTileHeight() - 1 );
    }
};