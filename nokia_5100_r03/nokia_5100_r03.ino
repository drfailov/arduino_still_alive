/* 84x48 LCD Defines: */
#define LCD_WIDTH   84 // Note: x-coordinates go wide
#define LCD_HEIGHT  48 // Note: y-coordinates go high
struct Line{
  long seconds = 0;
  long minutes = 0;
  String line = "";

  Line(int in_minutes, int in_seconds, String in_line){
    line = in_line;
    minutes = in_minutes;
    seconds = in_seconds;
  }
  long ms(){
    return 1000*(seconds + (minutes * 60));
  }
};

Line line[] = {
  Line(0,0,"This was a triumph!|"),
  Line(0,3,"I'm making a note here:|"),
  Line(0,6,"Huge success!|"),
  
  Line(0,9,"It's hard to overstate|"),
  Line(0,11,"my satisfaction.|"),
  
  Line(0,16,"Aperture Science:|"),
  Line(0,20,"We do what we must|"),
  Line(0,21,"because we can|"),
  Line(0,25,"For the good of all of us.|"),
  Line(0,28,"Except the ones who are dead.|"),
  
  Line(0,30,"But there's no sense crying|"),
  Line(0,32,"over every mistake.|"),
  Line(0,34,"You just keep on trying|"),
  Line(0,37,"'til you run out of cake.|"),
  Line(0,39,"And the science gets done.|"),
  Line(0,40,"And you make a neat gun|"),
  Line(0,42,"for the people who are|"),
  Line(0,44,"still alive.|"),
  Line(0,46,"...|"),
  
  Line(0,52,"I'm not even angry...|"),
  Line(0,56,"I'm being so sincere right now.|"),
  Line(1,1,"Even though you broke my heart,|"),
  Line(1,5,"and killed me.|"),
  
  Line(1,8,"And tore me to pieces.|"),
  Line(1,12,"And threw every piece into a fire.|"),
  Line(1,17,"As they burned it hurt because|"),
  Line(1,20,"I was so happy for you!|"),
  
  Line(1,22,"Now, these points of data|"),
  Line(1,24,"make a beautiful line.|"),
  Line(1,27,"And we're out of beta.|"),
  Line(1,28,"We're releasing on time!|"),
  Line(1,30,"So I'm GLaD I got burned!|"),
  Line(1,32,"Think of all the things we learned!|"),
  Line(1,35,"for the people who are|"),
  Line(1,36,"still alive.|"),
  Line(1,38,"...|"),
  
  Line(1,44,"Go ahead and leave me...|"),
  Line(1,48,"I think I'd prefer to stay inside...|"),
  Line(1,53,"Maybe you'll find someone else|"),
  Line(1,56,"to help you.|"),
  Line(2,0,"Maybe Black Mesa?|"),
  Line(2,4,"That was a joke. |"),
  Line(2,5,"Ha Ha. Fat Chance!|"),
  
  Line(2,8,"Anyway this cake is great!|"),
  Line(2,12,"It's so delicious and moist!|"),
  
  Line(2,14,"Look at me: still talking|"),
  Line(2,17,"when there's science to do!|"),
  Line(2,18,"When I look out there,|"),
  Line(2,20,"it makes me glad I'm not you.|"),
  
  Line(2,22,"I've experiments to run.|"),
  Line(2,24,"There is research to be done.|"),
  Line(2,26,"On the people who are|"),
  Line(2,28,"still alive.|"),
  Line(2,31,"And believe me I am|"),
  Line(2,32,"still alive.|"),
  Line(2,34,"I'm doing science and I'm|"),
  Line(2,36,"still alive.|"),
  Line(2,38,"I feel fantastic and I'm|"),
  Line(2,40,"still alive.|"),
  Line(2,43,"While you're dying I'll be|"),
  Line(2,44,"still alive.|"),
  Line(2,46,"And when you're dead I will be|"),
  Line(2,48,"still alive|"),
  
  Line(2,50,"Still alive.|"),
  
  Line(2,52,"Still|"),
  Line(2,52,"alive.|"),
};
int total = 66;


void setup()
{
  lcdBegin(); // This will setup our pins, and initialize the LCD
  updateDisplay(); // with displayMap untouched, SFE logo
  setContrast(40); // Good values range from 40-60
  delay(500);  
  clearDisplay(0);
  updateDisplay();
  digitalWrite(9, LOW);

  
  println_animated("READY........");
  delay(1000);  
  println_animated("SET..........");
  delay(1000);  
  println_animated("GO!..........");
  println_animated("=============");
  delay(100);

  long started = millis();
  for(int i=0; i<total; i++){
    long timeout = line[i].ms();
    while(millis()-started < timeout);//wait
    char buf[100];
    line[i].line.toCharArray(buf, line[i].line.length());
    println_animated(buf);
  }

  delay(2000);
  println_animated(".");
  println_animated(".");
  println_animated("Thanks for");
  println_animated("watching!");
  println_animated(".");
}


void loop()
{
}

