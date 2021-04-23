#ifndef COMPUTER_H
#define COMPUTER_H

class Computer
{
    static int idGen;

    int serial;
    std::string brand;
    std::string processor;
    std::string video;
    int hardDrive;
    double weight;
    double battery;
    double price;
    int quantity;

    void copy(int serial, const std::string &brand, const std::string &processor, const std::string &video, int hardDrive, double weight, double battery, double price, int quantity);

public:
    Computer();
    Computer(const std::string &brand, const std::string &processor, const std::string &video, int hardDrive, double weight, double battery, double price, int quantity);
    Computer(Computer const &otherComputer);
    Computer &operator=(Computer const &otherComputer);
    
    const std::string getBrand() const { return brand; }
    void setBrand(const char *brand) { this->brand = brand; }
    
    const std::string getProcessor() const { return processor; }
    void setProcessor(const char *processor) { this->processor = processor; }
    
    const std::string getVideo() const { return this->video; }
    void setVideo(const char *video) { this->video = video; }
    
    const int getHardDrive() const { return this->hardDrive; }
    void setHardDrive(int hardDrive) { this->hardDrive = hardDrive; }
    
    double getWeight() const { return this->weight; }
    void setWeight(double weight) { this->weight = weight; }
    
    int getBatteryLife() const { return this->battery; }
    void setBatteryLife(double battery) { this->battery = battery; }
    
    double getPrice() const { return this->price; }
    void setPrice(double price);
    
    int getQuantity() const { return this->quantity; }
    void setQuantity(double price);

    void print();
};

#endif /* ifndef COMPUTER_H */