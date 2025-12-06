---
title: Functions
---

Also known as "codepointers" in earlier versions of DeHackEd, Doom's functions are the building blocks of all map object behavior. Only the functions included in the pre-built engine are available to modders, so game development would benefit greatly from further generalization of Doom's library of functions.

## Marine's Best Friend

The MBF engine, based on Boom, added several useful functions to the library which persist in modern engines like PrBoom. The map collection [_Valiant_](https://doomwiki.org/wiki/Valiant) made use of the new `A_RandomJump` and `A_Spawn` functions to create a regular monster that essentially has a "second phase".

## Jumpwad

The [_Jumpwad_](https://doomwiki.org/wiki/Jumpwad) mapping project utilized a unique combination of functions and objects to give the player a "jump" action to complete certain challenges. The drawback was getting rid of most of the Hud and consequently many engine features. Game development could benefit from a dedicated "Jump" function that can be assigned like any other codepointer.
