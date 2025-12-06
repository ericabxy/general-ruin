---
title: A_FirePistol
---

The most basic player weapons in Doom suffer from a hard-coded state reference. Because of this, changing frame #155 via DeHackEd lump results in unexpected behavior.

    void
    A_FirePistol
    ( player_t*	player,
      pspdef_t*	psp ) 
    {
        S_StartSound (player->mo, sfx_pistol);

        P_SetMobjState (player->mo, S_PLAY_ATK2);
        player->ammo[weaponinfo[player->readyweapon].ammo]--;

        P_SetPsprite (player,
		      ps_flash,
		      weaponinfo[player->readyweapon].flashstate);

        P_BulletSlope (player->mo);
        P_GunShot (player->mo, !player->refire);
    }

FirePistol was written this way in order for the player sprite to flash with gunfire when firing a weapon. The player's fist and chainsaw weapons instead use a non-flashing animation frame. Although map objects in Doom were programmed with two "firing" states, these states were used to differentiate monster attack animations and not the player.

Fiddling with the player's firing states could have unintended consequences due to the engine using these states' values to determine certain calculations. Generalizing these functions should probably be done by adding a new state to all map objects. This could fix several other hard-coded state table references including for the player Chaingun and the Archvile's resurrection states. The refactored function might be written as follows.

    void
    A_FirePistol
    ( player_t*	player,
      pspdef_t*	psp ) 
    {
        S_StartSound (player->mo, sfx_pistol);

        P_SetMobjState (player->mo, player->mo->actionstate);
        player->ammo[weaponinfo[player->readyweapon].ammo]--;

        P_SetPsprite (player,
		      ps_flash,
		      weaponinfo[player->readyweapon].flashstate);

        P_BulletSlope (player->mo);
        P_GunShot (player->mo, !player->refire);
    }

With this change, the FirePistol function sets the player state according to information stored in the player object itself, which is fully configurable via DeHackEd lump.
