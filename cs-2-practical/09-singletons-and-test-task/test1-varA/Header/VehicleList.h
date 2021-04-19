#pragma once

#include "Vehicle.h"

class VehicleList {
    Vehicle **vehicles = nullptr;
    size_t allocated = 0;
    size_t used = 0;

public:
    explicit VehicleList(std::size_t capacity);

    VehicleList(const VehicleList &other);

    VehicleList(VehicleList&& other) noexcept;

    ~VehicleList();

    VehicleList &operator=(const VehicleList &other);

    VehicleList& operator=(VehicleList&& other) noexcept;

    void insert(const char *regnum, const char *description);

    const Vehicle& at(size_t index) const;

    const Vehicle &operator[](size_t index) const;

    bool empty() const;

    std::size_t capacity() const;

    std::size_t size() const;

    const Vehicle *find(const char *regnum) const;

private:
    Vehicle** clone(Vehicle** v, size_t size, size_t used);

    void deleteVehicleList();
};

