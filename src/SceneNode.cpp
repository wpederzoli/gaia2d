#include "SceneNode.h"

SceneNode::SceneNode(int id, int x, int y, int width, int height) : Rectangle(x, y, width, height)
{
    this->ID = id;
    this->scene = NULL;
    this->removed = false;
};

SceneNode::~SceneNode()
{};

void SceneNode::setScene(Scene* s)
{
    this->scene = s;
};

Scene* SceneNode::getScene()
{
    return this->scene;
};

void SceneNode::update()
{};

//For debugging
void SceneNode::draw(Rectangle* view, Graphics* g)
{
    if(view->overlaps(*this) && g != NULL)
        printf("Draw a red rectangle\n");
};

void SceneNode::remove()
{
    this->removed = true;
};

bool SceneNode::isRemoved()
{
    return this->removed;
};

int SceneNode::getID()
{
    return this->ID;
};