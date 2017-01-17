#define WHITE       0  // For drawing pixels. A 0 draws white.
#define BLACK       1  // A 1 draws black.

int line_height = 8;
int line_length = 14;
int current_y = line_height*5;
int current_x = 0;


void print(char * dString){
  bool bw = true;
  
  while (*dString != 0x00) // loop until null terminator
  {
    //переход на новую строку если символ перехода
    if(*dString == '\n'){
      dString++;
      pull_lines_up();
      current_x = 0;
    }
    else{
      //нарисовать символ
      setChar(*dString++, current_x, current_y, bw);
      current_x+=5;
  
      //один пиксель после сивкола
      for (int i=current_y; i<current_y+8; i++)
        setPixel(current_x, i, !bw);
      current_x++;
  
      //Переход на новую строку если конец строки
      if (current_x > (LCD_WIDTH - 5)) {
        pull_lines_up();
        current_x = 0;
      }
    }
  }
  updateDisplay();
}

void println(char * dString){
  print(dString);
  print("\n");
}

void print_animated(char* dString){
  while (*dString != 0x00){
    char toPrint[2];
    char c = *dString;
    dString++;
    toPrint[0] = c;
    toPrint[1] = 0x00;
    print(toPrint);
    delay(50);
  }
}

void println_animated(char * dString){
  print_animated(dString);
  print_animated("\n");
}

