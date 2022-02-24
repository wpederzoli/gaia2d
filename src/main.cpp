#include "Game.h"
#include "Font.h"

class FontTest : public Game
{
    private:
        Font font;

    public:
        FontTest(){};
        ~FontTest(){};
        bool init() override
        {
            if(!initSystem("Space Game", 800, 600, false) )
                return false;

            if(!font.load("./Mistic-Regular.ttf", "Wharap", 100, 255, 100, 5, 255, Game::getGraphics()) )
                return false;
            
            font.setPosition(100, 200);
            return true;
        };
        void free() override {};
        void update() override{};
        void draw(Graphics* g) override
        {
            font.draw(g);
        };
};
 
int main(int argc, char const *argv[])
{
    FontTest game;
    if(!game.init() )
    {
        game.free();
        return 0;
    }

    game.run();
    return 0;
}
