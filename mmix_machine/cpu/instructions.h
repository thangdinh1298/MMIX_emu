#include <iostream>

#include "types.hpp"

namespace CPU {
    
}

class Instruction {
private:
    octa inst_;
    const static byte mask_ = 0xFF;
public:
    Instruction(octa inst) : inst_{inst} {

    }

    byte op() const {
        return inst_ & (mask_ << 24);
    }

    byte x() const {
        return inst_ & (mask_ << 16);
    }

    byte y() const {
        return inst_ & (mask_ << 8);
    }

    byte z() const {
        return inst_ & mask_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Instruction& inst);
};

std::ostream& operator<<(std::ostream& os, const Instruction& inst)
{
    os << "Op: " << static_cast<unsigned int> (inst.op())
       << "\tX: " << static_cast<unsigned int> (inst.x()) 
       << "\tY: " << static_cast<unsigned int> (inst.y())
       << "\tZ: " << static_cast<int> (inst.z());
    return os;
}