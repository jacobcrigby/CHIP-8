// SPDX-License-Identifier: GPL-3.0-or-later

#include "emu.h"
#include "chip-8.hpp"

emu_t *init()
{
    Chip8 *chip8 = new Chip8();
    return reinterpret_cast<emu_t *>(chip8);
}

void load(emu_t *emu, char *filename)
{
    Chip8 *chip8 = reinterpret_cast<Chip8 *>(emu);
    chip8->load(filename);
}

void step(emu_t *emu)
{
    Chip8 *chip8 = reinterpret_cast<Chip8 *>(emu);
    chip8->cycle();
}

void stop(emu_t *emu)
{
    Chip8 *chip8 = reinterpret_cast<Chip8 *>(emu);
    delete chip8;
}
