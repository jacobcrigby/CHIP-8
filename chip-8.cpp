// SPDX-License-Identifier: GPL-3.0-or-later

#include "chip-8.hpp"

void Chip8::load(const char *filename)
{
}

void Chip8::load(const char *filename, EMU_MODE mode)
{
    this->mode = mode;
    load(filename);
}

void Chip8::cycle()
{
}
