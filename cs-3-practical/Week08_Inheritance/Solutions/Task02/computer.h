#pragma once
#include "hard_drive.h"
#include "video_card.h"
#include "processor.h"
#include "ram.h"

class Computer {
    HardDrive *hard;
    VideoCard *video;
    Processor *processor;
    Ram *ram;

public:
    Computer(const HardDrive &hard, const VideoCard &video, const Processor &processor, const Ram &ram);

    HardDrive getHardDrive() const;
    void setHardDrive(const HardDrive &hard);

    VideoCard getVideoCard() const;
    void setVideoCard(const VideoCard &video);

    Processor getProcessor() const;
    void setProcessor(const Processor &processor);

    Ram getRam() const;
    void setRam(const Ram &ram);

    void print();
};