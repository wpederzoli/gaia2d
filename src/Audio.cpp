#include <stdio.h>
#include "Audio.h"

bool Audio::init()
{
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048 ) == -1 )
    {
        printf("Failed to load audio: %s\n", Mix_GetError() );
        return false;
    }

    return true;
};

void Audio::kill()
{
    Mix_CloseAudio();
};

bool Audio::audioPlaying()
{
    return Mix_PlayingMusic();
};

bool Audio::audioPaused()
{
    return Mix_PausedMusic();
};

void Audio::pauseAudio()
{
    Mix_PauseMusic();
};

void Audio::resumeAudio()
{
    Mix_ResumeMusic();
};

void Audio::stopAudio()
{
    Mix_HaltMusic();
};

void Audio::stopChannel(int channel)
{
    Mix_HaltChannel(channel);
};