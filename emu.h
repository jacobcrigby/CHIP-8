// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef void* emu_t;

emu_t* init();
void load(emu_t* emu, char* filename);
void step(emu_t* emu);
void stop(emu_t* emu);

#ifdef __cplusplus
}
#endif
