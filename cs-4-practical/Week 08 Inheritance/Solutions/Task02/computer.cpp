#include "computer.h"
#include <iostream>

Computer::Computer(const HardDrive &hard, const VideoCard &video, const Processor &processor, const Ram &ram) {
    this->hard = new HardDrive(hard);
    this->video = new VideoCard(video);
    this->processor = new Processor(processor);
    this->ram = new Ram(ram);
}

HardDrive Computer::getHardDrive() const {
    return *hard;
}
void Computer::setHardDrive(const HardDrive &hard) {
    this->hard = new HardDrive(hard);
}

VideoCard Computer::getVideoCard() const {
    return *video;
}
void Computer::setVideoCard(const VideoCard &video) {
    this->video = new VideoCard(video);
}

Processor Computer::getProcessor() const {
    return *processor;
}
void Computer::setProcessor(const Processor &processor) {
    this->processor = new Processor(processor);
}

Ram Computer::getRam() const {
    return *ram;
}
void Computer::setRam(const Ram &ram) {
    this->ram = new Ram(ram);
}

void Computer::print() {
    std::cout << "Computer configuration:\n";
    processor->print();
    ram->print();
    hard->print();
    video->print();
}