// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <cstdint>
#include <algorithm>
#include <array>

enum class EMU_MODE : int
{
    CHIP8,
};

class Chip8
{
public:
    // Constructor - calls `init()`
    Chip8()
    {
        init();
    }
    Chip8(EMU_MODE mode) : mode(mode)
    {
        init();
    }
    ~Chip8() = default;
    Chip8(const Chip8 &) = delete;            // Disable copy constructor
    Chip8 &operator=(const Chip8 &) = delete; // Disable copy assignment
    Chip8(Chip8 &&) = default;                // Enable move constructor
    Chip8 &operator=(Chip8 &&) = default;     // Enable move assignment

    // Reinitialize the Chip-8 interpreter
    void init()
    {
        pc = 0x200; // Program counter starts at 0x200
        i = 0;      // Index register
        sp = 0;     // Stack pointer
        delayTimer = 0;
        soundTimer = 0;

        // Clear memory and registers
        std::fill(memory.begin(), memory.end(), 0);
        std::fill(V.begin(), V.end(), 0);
    }

    // Reset the Chip-8 interpreter to its initial state.
    // Functions as an ailias for `init()`
    void reset()
    {
        init();
    }

    // Load a ROM file into memory
    void load(const char *filename);

    // Load a ROM file into memory with a specific mode
    // Default mode is standard CHIP-8
    void load(const char *filename, EMU_MODE mode);

    // Run one cycle of the Chip-8 interpreter
    void cycle();

    // void setKeys();
    // void drawGraphics();
    // void clearScreen();
    // void updateTimers();
    // void handleInput();

private:
    EMU_MODE mode = EMU_MODE::CHIP8;        // Default mode is CHIP-8
    std::array<uint8_t, 4096> memory = {0}; // 4KB of memory
    std::array<uint8_t, 16> V = {0};        // 16 registers (V0 to VF)
    uint16_t i;                             // Index register
    uint16_t sp;                            // Stack pointer
    uint16_t pc;                            // Program counter
    uint8_t delayTimer;                     // Delay timer
    uint8_t soundTimer;                     // Sound timer
};
