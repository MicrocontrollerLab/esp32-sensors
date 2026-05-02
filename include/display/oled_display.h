#pragma once

void display_init();
void display_clear();
void display_update();

void display_print_text(const char* text);
void build_text(char* buffer, size_t buffer_size, 
  float value_1, float value_2, float value_3);