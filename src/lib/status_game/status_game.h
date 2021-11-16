#ifndef H_STATUS_GAME
#define H_STATUS_GAME

#include <stdio.h>

#include "../game/game.h"

typedef struct StatusGame {
  ProgressList progress_list;
  ToDoList to_do_list;
  Tas tas_mobita;
  OrderList order_list;
  inventory_gadget inventory_gadget;
  Time Waktu_Permainan;
  Building posisi_sekarang;
  Map peta_game;
  int uang_mobita;

} StatusGame;

#define SG_TDL(StatusGame) (StatusGame).to_do_list
#define SG_TAS(StatusGame) (StatusGame).tas_mobita
#define SG_TIME(StatusGame) (StatusGame).Waktu_Permainan

extern StatusGame s_status_game;

/*Berfungsi untuk mereset waktu*/
void sg_reset_time();

/*Berfungsi untuk increment waktu*/
void sg_inc_time();

/* mengubah state game berdasarkan gadget yang diinputkan */
/* masih menunggu beberapa adt game selesai */
void g_change_state(int type, int mv);

#endif
