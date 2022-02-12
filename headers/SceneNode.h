#ifndef SCENENODE_H
#define SCENENODE_H

#include "Graphics.h"
#include "Scene.h"
#include "Rectangle.h"

class Scene;

class SceneNode : public Rectangle
{
    private:
        Scene* scene;
        bool removed;
        int ID;

    public:
        SceneNode(int id, int x, int y, int width, int height);
        virtual ~SceneNode() = default;

        void setScene(Scene* s);
        void setId(int id);
        
        int getId();
        Scene* getScene();

        virtual void update();
        virtual void draw(Rectangle* view, Graphics* g);

        void remove();
        bool isRemoved();

        int getID();
};

#endif