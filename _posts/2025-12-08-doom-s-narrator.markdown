---
layout: post
title:  "Doom's Narrator"
date:   2025-12-08 12:00:00 -0800
categories: theory
---

Dialogue in the Doom engine is either notoriously absent; present only in the form of intermission screens and short messages during gameplay (to indicate picked-up items and locked doors). The lack of dialogue or scripted scenes limits the kind of game that can be made in with Doom, but it does leave the player with fewer distractions and the developer with fewer concerns during game design.

Since it traditionally refers to the player as "You", I've taken to calling the dialogue system "Boom's Narrator".

## Item Pick-up Messages

The engine prints a short message on the screen whenever the player picks up an item. It only stays visible for a second or two and is overwritten by any consecutive messages, limiting it to unimportant dialogue that can be read quickly. Its also a one-time dialogue system---you can't pick up an item again to read the message.

## Locked Door and Switch Messages

The same message system prints a short message on the screen when the player attempts to open a door or activate a switch that requires keys the player doesn't have. This message is again limited to something that can be read quickly, but in this case the message is repeatable. The player can attempt the door or switch any number of times to read the message again.

## Intermission Screens

Aside from the end-level screen---which is displayed after every level and can only show the name of the previous and next map---developers can program "intermissions" which slowly print some long-form text to the screen. This is traditionally used to tell the story of Doom or the Doom mod, but as intermission screens are few and far-between the experience can be both jarring and insufficient for storytelling purposes.

In the case of intermission screens I don't think they play to the Doom engine's strengths very well. The action-oriented design of the engine lends itself to _environmental storytelling_ and the intermissions are completely removed from any map's environment.

## A Creative Solution or Two

I think the best way to implement a dialogue system in the engine would avoid interrupting player control and closely integrate with the environment. Item pick-ups are an unlikely candidate for this, but expanding the concept of keyed doors shows promise.

When editing a map recently, I used a keyed door to tell the player how many items to collect before exiting. It simply says "All six soul keys are required to exit", but the message isn't very impactful and even has the potential to be missed. The short message is printed in a corner of the screen and it only made known by its presence and a short "oof" or clicking sound.

For an experiment I used a Freedoom texture to create a "switch" that gets activated simultaneously with the keyed door trigger. Now the locked door looks like it has a metal mask on it, and when you try to open it the eyes of the mask light up briefly along with a clunky sound. I think it ties the dialogue in with the environment much more effectively now, and I think this is a major area where the engine can be improved.

## A Linedef-triggered Dialogue System

Expanding the functionality of locked doors can make them much more impactful. Locked doors should be able to make a sound and change their texture just like switches, even when they can't be activated yet. The action can be re-triggered on-demand, keeping the player in total control of the interaction.

Other implementations of this idea include a walk-over linedef that prints a message about an environmental change. Something like "you feel a sense of foreboding beyond this point" along with a visual indicator of the line you walked over to trigger the message.

## Other Solutions

Other solutions include contextual writing on wall textures (signs like "disaster area" and "no humans" come to mind, as well as Jumpwad's "collect X gems to exit") and using sectors to write messages on the automap (as in [Bury My Heart Knee Deep](https://doomwiki.org/wiki/Bury_My_Heart_Knee_Deep)).
