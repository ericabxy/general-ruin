// Leap into the air with the same physics as an archvile jump.
void A_ArchJump( player_t* player, pspdef_t* psp )
{
  S_StartSound (player->mo, sfx_barexp);
  player->momz = 1000*FRACUNIT/player->info->mass;
}
