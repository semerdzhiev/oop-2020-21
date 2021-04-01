class Beer {

private:
    char* brand;
    unsigned volume{};
    double abv{};
   
    void copyFrom(const Beer& other);
    void free();

public: 
    Beer();
    Beer(const char* _brand, unsigned _volume, double _abv);
    Beer& operator=(const Beer& other);
    ~Beer();

    void print();
};
