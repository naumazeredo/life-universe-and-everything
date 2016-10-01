# Life, the Universe and Everything

_Life, the Universe and Everything_ (LUE for short) is a rogue-like, space
exploration, RTS and ship-building based on [Faster Than Light](http://www.ftlgame.com).

Since _FTL_ will no longer be updated nor have a sequel, I aim to recreate the
_FTL_ experience and add direct support for modding.

Any help is welcome!

# To-Do list

- [ ] Engine
  - [x] Limit framerate
  - [x] Textures
  - [x] Sprites
  - [x] Text rendering
    - [ ] Bitmap font
  - [x] Buttons
  - [ ] Audio
  - [ ] Timer
    - [ ] Game time
    - [ ] Pause
    - [ ] Time scaling
- [ ] Game
  - [ ] Main menu
  - [ ] Ships
    - [ ] Ship building
    - [ ] Systems/subsystems
    - [ ] Ship battle
    - [ ] Crew
      - [ ] Crew movement
      - [ ] Crew fight
  - [ ] Races
  - [ ] Sectors
  - [ ] Random events

# Dependencies

- [SDL2](https://www.libsdl.org/download-2.0.php)
- [SDL2 image](https://www.libsdl.org/projects/SDL_image)
- [SDL2 ttf](https://www.libsdl.org/projects/SDL_ttf)

in Ubuntu 16.04:

```
$ sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

# License

The game is licensed under the [BSD License](https://opensource.org/licenses/BSD-2-Clause):

Copyright (c) 2016, Naum Azeredo
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
