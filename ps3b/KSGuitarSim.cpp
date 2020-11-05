/*
  Copyright 2015 Fred Martin,
  Y. Rykalova, 2020
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "CircleBuffer.h"
#include "StringSound.h"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

using namespace std;
using namespace sf;

std::vector<sf::Int16> makeSamples(StringSound ss) {
    std::vector<sf::Int16> samples;

    ss.pluck();
    int duration = 8;  // seconds
    int i;
    for (i = 0; i < SAMPLES_PER_SEC * duration; i++) {
        ss.tic();
        samples.push_back(ss.sample());
    }
    return samples;
}


int main() {
    sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound Lite");
    sf::Event event;
    double freq;
    std::vector<sf::Int16> sample;

    //lambda
    auto return_freq = [](int n) { return 440 * pow(2, ((n - 24.0) / 12.0)); };

    std::vector<std::vector<int16_t>>samples; //vector of 37 vector samples
    std::vector<sf::SoundBuffer> soundBuffers;
    std::vector<sf::Sound> sounds;
    for (int i = 0; i < 37; i++) {
        freq = return_freq(i);
        StringSound save_freq = StringSound(freq);
        sample = makeSamples(save_freq);
        samples.push_back(sample);    //pushback 37 samples 
    }
    //std::vector<sf::SoundBuffer> soundBuffers; //37 samples go into soundBuffers
    for (int i = 0; i < 37; i++) {
        sf::SoundBuffer buffers;
        buffers.loadFromSamples(&samples.at(i)[0], samples.at(i).size(), 2, SAMPLES_PER_SEC);
        soundBuffers.push_back(buffers);
    }
    //std::vector<sf::Sound> sounds;//37 sounds go into soundBuffers
    for (int i = 0; i < 37; i++) {
        sf::Sound sound;
        sound.setBuffer(soundBuffers[i]);
        sounds.push_back(sound);
    }

    std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' "; //make a keyboard string
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::TextEntered: {
                string save_string;
                save_string = save_string + event.text.unicode; //encoding characters in string
                int n = keyboard.find(save_string);//find the key within the string
                if (n < 0) {
                    break; //exit if it is the wrong key
                }
                sounds[n].play();
            }
            default:
                break;
            }
            window.clear();
            window.display();
        }
    }
    return 0;
}
