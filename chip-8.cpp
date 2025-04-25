// SPDX-License-Identifier: GPL-3.0-or-later

#include <cstdint>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "chip-8.hpp"

bool Chip8::load(const char *filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }
    file.read(reinterpret_cast<char *>(memory.data() + 0x200), memory.size() - 0x200);
    return true;
}

bool Chip8::load(const char *filename, EMU_MODE mode)
{
    this->mode = mode;
    return load(filename);
}

void Chip8::cycle()
{
    // Fetch
    uint16_t opcode = (memory[pc] << 8) | memory[pc + 1]; // Fetch opcode
    pc += 2;                                              // Increment program counter

    // Decode and execute
    switch (opcode & 0xF000)
    {
    case 0x0000:
        switch (opcode & 0x00FF)
        {
        case 0x00E0:
        {
            // CLS
        }
        break;
        case 0x00EE:
        {
            // RET
        }
        break;
        }
    break;
    case 0x1000:
    {
        // JP
    }
    break;
    default:
        std::cerr << "Unknown opcode: " << std::hex << opcode << std::endl;
        break;
    }
}
