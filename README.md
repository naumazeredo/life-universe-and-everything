# Life, the Universe and Everything

_Life, Universe and Everything_ (LUE for short) is a rogue-like, space
exploration, RTS and ship-building based on [Faster Than Light](http://www.ftlgame.com)
and inspired by _The Hitchhiker's Guide to the Galaxy_.

## Modding

_LUE_ will feature modding capabilities.

_FTL_ have a great modding community and _LUE_ wants to ease the modding so we
can have a greater community than _FTL_ had with all the issues to mod the game.

The ideia is to implement almost everything in a scripting language like Lua or
Python (even for the main game).

What's going to be moddable:

- Races
- Systems
- Weapons
- Drones
- Augmentations
- Sectors
- Events
- (Missions)

## Unlockables

_LUE_ will feature unlockables.

The game will start with a small set of weapons, systems, augmentations, drones
and races and they will be unlocked during game.

There are some ways to unlock new things:

- Specific events
- Dominating another ship (_might_ unlock weapon/system/augmentations owned)
- Buying at shops
- (Missions)
- (more to think!)

## Missions

_LUE_ will have a set of missions that the player can choose from.

The missions are:

- Rebel Flagship Encounter (_FTL_ mission)
- (more to think!)

On the start of the mission (if not in a mission that gives some premade ship)
the player will buy a new ship (or use some already made one, from himself, other
players or premade).

## Ship Building Mechanics

_LUE_ will feature ship building mechanics.

When player starts a mission he can choose some premade ship or construct a new
one.

There will be limited resources to build a new ship. Ship tiles, doors, systems,
weapons and drones will be priced and the player can spend a certain amount of
_scrap_, the monetary unit in _FTL_ (might change during development), to
construct his/her ship.

During the mission he will encounter ship stations where he can improve his/her
ship.

What ship building will have:

- Buy rooms (player selected connected tiles and builds the room)
- Buy doors (rooms have to be reachable from piloting room)
- Buy system (and assign it to some room. Must have at least piloting and
    engines, O² is optional because of non-oxigen consuming races)
- Buy augmentations
- Buy crew (only on mission start)

## Shops

Shops have some limited amount of fuel, scrap and drone parts to be bought.

Shops can sell weapons, systems, drones and crew (this _might_ be random or shops can
have some types that define what they have.

Weapons, systems, augmentations and drones not unlocked _might_ have a small to
appear in shops.

_On LUE, ships systems be bought at shops!_

## Races

_LUE_ will feature more races than _FTL_ have.

_Probably FTL_ races will change!

- Human
- Engi
- Mantis
- Zoltan
- Rockmen
- Slug
- Crystal
- Lanius

## Contiguous Sectors (_idea_)


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

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
