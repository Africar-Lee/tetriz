# pragma once
namespace tc { // terminal control

    void cursor_move_to(int row, int col);
    void set_fore_color(int color_id);
    void set_back_color(int color_id);
    void clean_screen();
    void reset_color();
    void hide_cursor();
    void show_cursor();
}