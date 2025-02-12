#include "../../Header/Sounds/SoundManager.h"
#include <iostream>

namespace Sound
{
    sf::Music SoundManager::backgroundMusic;
    sf::SoundBuffer SoundManager::ballBounce;
    sf::Sound SoundManager::soundEffect;

    const std::string SoundManager::ballBouncePath = "Assets/Sounds/Ball_Bounce.wav";
    const std::string SoundManager::bgmPath = "Assets/Sounds/Pong_bgm.mp3";

    float SoundManager::backgroundMusicVolume = 50.0f;



    SoundManager::SoundManager()
    {
        Initialize();
    }

    SoundManager::~SoundManager()
    {
        delete this;
    }

    void SoundManager::Initialize()
    {
        LoadSoundFromFile();
    }

    void SoundManager::LoadSoundFromFile()
    {
        if (!ballBounce.loadFromFile(ballBouncePath))
            std::cerr << "Error loading sound file: " << ballBouncePath << std::endl;
        if (!backgroundMusic.openFromFile(bgmPath))
            std::cerr << "Error loading background music file: " << bgmPath << std::endl;
    }

    void SoundManager::PlaySoundEffect(SoundType soundType)
    {
        switch (soundType)
        {
        case SoundType::BALL_BOUNCE:
            soundEffect.setBuffer(ballBounce);
            break;
        default:
            std::cerr << "Invalid sound type" << std::endl;
            return;
        }

        soundEffect.play();
    }

    void SoundManager::PlayBackgroundMusic()
    {
        backgroundMusic.setLoop(true);
        backgroundMusic.setVolume(backgroundMusicVolume);
        backgroundMusic.play();
    }
}