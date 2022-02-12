#include "Scene.h"

Scene::Scene()
{};

Scene::~Scene()
{};

void Scene::addNode(SceneNode* node)
{
    node->setScene(this);
    this->nodes.push_back(node);
};

void Scene::removeNode(SceneNode* node)
{
    if(node != NULL)
    {
        SceneNode* n = node;
        this->nodes.remove(node);
        delete n;
    }
    else
    {
        while(!this->nodes.empty() )
        {
            removeNode(*this->nodes.begin() );
        }
    }
};

void Scene::update()
{
    std::list<SceneNode*>::iterator it;

    for(it = nodes.begin(); it != nodes.end(); it++)
    {
        if((*it)->isRemoved() )
        {
            SceneNode* old = *it;
            it--;
            removeNode(old);
        }
    }

    for(it = nodes.begin(); it != nodes.end(); it++)
    {
        (*it)->update();
    }
};

void Scene::draw(Rectangle* view, Graphics* g)
{
    for(std::list<SceneNode*>::iterator it = nodes.begin(); it != nodes.end(); it++)
    {
        (*it)->draw(view, g);
    }
};

std::list<SceneNode*>* Scene::getNodes()
{
    return &nodes;
}