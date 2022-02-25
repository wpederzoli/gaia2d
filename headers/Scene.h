#ifndef SCENE_H
#define SCENE_H

#include <list>

#include "SceneNode.h"
#include "Rectangle.h"

class SceneNode;

class Scene
{
    private:
        std::list<SceneNode*> nodes;
    
    public:
        Scene();
        ~Scene();

        void addNode(SceneNode* node);
        void removeNode(SceneNode* node);

        void update();
        void draw(Rectangle* view, Graphics* g);

        std::list<SceneNode*>* getNodes();
};

#endif