#include "mainmenu.h"

boolean __is_str_same(char input1[], char input2[]) {
  int i = 0;
  boolean same = input1[i] == input2[i];
  while (same && (input1[i] != '\0' || input2[i] != '\0')) {
    i++;
    same = input1[i] == input2[i];
  }
  return same;
}

char *__ask_input() {
  printf("ENTER COMMAND: ");
  char *input = malloc(100 * sizeof(char));

  read_line(input, 100);
  return input;
}

void mm_dashboard() {
  Color cyan = create_text_color_cd(0x0a9396);
  set_text_color(cyan);

  printf("___  ___      _     _ _ _ _        \n");
  printf("|  \\/  |     | |   (_) (_) |       \n");
  printf("| .  . | ___ | |__  _| |_| |_ __ _ \n");
  printf("| |\\/| |/ _ \\| '_ \\| | | | __/ _` |\n");
  printf("| |  | | (_) | |_) | | | | || (_| |\n");
  printf("\\_|  |_/\\___/|_.__/|_|_|_|\\__\\__,_|\n");

  reset_color();

  printf("\n\nVersi 1.0.0.\n\n");

  cm_modal_info(
      "Halo, Aku Mobita. Bantuin aku yuk...\nKamu bisa masukin perintah "
      "dibawah ini yaa, Selamat bermain");

  delete_color(cyan);
}

void show_main_menu() {
  // wm_start_word(stdin);
  // while (!wm_end_word){
  //     printf("%s\n", wm_current_word.contents);
  //     wm_adv_word();
  // }
  clear_screen();

  // Kalau mau ngeprint ascii art saat load game
  mm_dashboard();
  cm_set_end_char("\n", 1);

  char *main_input_command;

  boolean GAME_COMPLETE = false;
  do {
    main_input_command = __ask_input();
    if (__is_str_same(main_input_command, "NEW GAME") ||
        __is_str_same(main_input_command, "LOAD GAME")) {
      StatusGame s_status_game;
      if (__is_str_same(main_input_command, "NEW GAME")) {
        // Loading Config
        printf("Path to config file: ");
        char *configPath = __ask_input();
        readConfigFile(configPath, &s_status_game);

        // Config file nya udah dibaca
        // configPath adalah hasil malloc, harus di free supaya gak makan memory
        free(configPath);
      } else {
        show_load_game(&s_status_game);
      }

      // Game berlangsung selama ToDoList tidak Kosong dan
      // Tas (Isinya pesanan yang harus diantar) tidak kosong
      char *input_command;
      while (!td_is_empty(SG_TDL(s_status_game)) &&
             !t_is_empty(SG_TAS(s_status_game))) {
        // Game
        input_command = __ask_input();
        if (__is_str_same(input_command, "MOVE")) {
          // MOVE
        } else if (__is_str_same(input_command, "PICK_UP")) {
          // PICK UP
        } else if (__is_str_same(input_command, "DROP_OFF")) {
          // DROP OFF
        } else if (__is_str_same(input_command, "MAP")) {
          show_map();
        } else if (__is_str_same(input_command, "TO_DO")) {
          show_to_do(s_status_game);
        } else if (__is_str_same(input_command, "IN_PROGRESS")) {
          show_progress(s_status_game);
        } else if (__is_str_same(input_command, "BUY")) {
          show_page_buy(&s_status_game);
        } else if (__is_str_same(input_command, "INVENTORY")) {
          show_inventory(&s_status_game);
        } else if (__is_str_same(input_command, "HELP")) {
          // HELP
        } else if (__is_str_same(input_command, "SAVE_GAME")) {
          show_save_game(s_status_game);
        } else {
          cm_modal_error("COMMAND TIDAK DIKENALI!");
        }
        // input_command merupakan hasil malloc,
        // jadinya perlu di dealokasi
        free(input_command);
      }
      // Keluar while, artinya game sudah selesai
      GAME_COMPLETE = true;

      // Tampilin Statistik Game
      printf("Game Selesai\n");
      printf("Time: %d\n", SG_TIME(s_status_game));
      // Display berapa banyak item yang diantar

    } else if (__is_str_same(main_input_command, "HELP")) {
      // SHOW HELP
    } else if (__is_str_same(main_input_command, "EXIT")) {
      printf("Exiting Game....\n");
      GAME_COMPLETE = true;
    } else {
      printf("\n");
      cm_modal_error("COMMAND TIDAK DIKENALI!");
    }
    // main_input_command adalah hasil malloc, perlu free biar gak jadi zombie
    free(main_input_command);
  } while (!GAME_COMPLETE);
}
