#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Audio
{
    private:
    
    public:
        bool init();
        void kill();

        bool audioPlaying();
        bool audioPaused();
        void pauseAudio();
        void resumeAudio();
        void stopAudio();

        void stopChannel(int channel);
};

#endif